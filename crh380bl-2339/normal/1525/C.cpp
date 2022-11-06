#include<bits/stdc++.h>
#define N 300005
using namespace std;
struct node{
	bool dir;//0L 1R
	int start;
	int id;
	node(){}
	bool operator <(const node x)const{
		return start<x.start;
	}
}a[N],odd[N],even[N],q[N];
char s[3];int ans[N];
int tot,m,h;
void work(node *a,int n){
	tot=0;
	int i,j,k;
	for(i=1;i<=n;++i){
		if(a[i].dir==1)q[++tot]=a[i];
		else{
			if(tot&&q[tot].dir==1){
				ans[q[tot].id]=ans[a[i].id]=abs(a[i].start-q[tot].start)>>1;
				--tot;
			}
			else q[++tot]=a[i];
		}
	}
	for(h=1;h<tot&&q[h].dir==0&&q[h+1].dir==0;h+=2){
		ans[q[h].id]=ans[q[h+1].id]=(q[h].start+q[h+1].start)>>1;
	}
	for(;tot>=2&&q[tot].dir&&q[tot-1].dir;tot-=2){
		ans[q[tot].id]=ans[q[tot-1].id]=m-(q[tot].start+q[tot-1].start)/2;
	}
	if(q[h].dir==0&&q[tot].dir&&h+1==tot){
		ans[q[h].id]=ans[q[tot].id]=m-abs(q[h].start-q[tot].start)/2;
	}
}
int main(){
	int T;
	int n,n1,n2,i,j,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i){
			a[i].id=i;
			ans[i]=-1;
			scanf("%d",&a[i].start);
		}
		for(i=1;i<=n;++i){
			scanf("%s",s);
			if(s[0]=='L')a[i].dir=0;
			else a[i].dir=1;
		}
		sort(a+1,a+1+n);
		n1=n2=0;
		for(i=1;i<=n;++i){
			if(a[i].start&1)odd[++n1]=a[i];
			else even[++n2]=a[i];
		}
		assert(n1+n2==n);
		work(even,n2);
		work(odd,n1);
		for(i=1;i<n;++i)printf("%d ",ans[i]);
		printf("%d\n",ans[n]);
	}
	return 0;
}