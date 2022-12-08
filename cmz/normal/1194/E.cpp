#include<bits/stdc++.h>
#define lowbit(x) x&-x
#define LL long long
using namespace std;
const int N=5010;
int n,n1,n2,c[N*2],tot,m,p[N],cnt,f[N*2];LL ans;
struct node{
	int y1,y2,x;
	bool friend operator <(node a,node b){
		return a.x<b.x;
	}
}a[N],b[N];
bool cmp(node a,node b){
	return a.y2<b.y2;
}
void add(int x,int y){
	for(;x<=m;x+=lowbit(x))f[x]+=y;
}
int ask(int x){
	int ret=0;
	for(;x;x-=lowbit(x))ret+=f[x];
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1,x1,x2,y1,y2;i<=n;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(y1>y2)swap(y1,y2);if(x1>x2)swap(x1,x2);
		if(x1==x2)a[++n1]=(node){y1,y2,x1},c[++tot]=y1,c[++tot]=y2;
		else b[++n2]=(node){x1,x2,y1},c[++tot]=y1;
	}
	sort(c+1,c+tot+1);m=unique(c+1,c+tot+1)-c-1;
	for(int i=1;i<=n1;i++){
		a[i].y1=lower_bound(c+1,c+m+1,a[i].y1)-c;
		a[i].y2=lower_bound(c+1,c+m+1,a[i].y2)-c;
	}
	for(int i=1;i<=n2;i++)b[i].x=lower_bound(c+1,c+m+1,b[i].x)-c;
	sort(a+1,a+n1+1);
	sort(b+1,b+n2+1,cmp);
	for(int i=1,k=1;i<n1;i++){
		k=1;cnt=0;
		for(int j=1;j<=n2;j++){
			if(b[j].y1<=a[i].x&&b[j].x>=a[i].y1&&b[j].x<=a[i].y2){//cout<<i<<" "<<j<<endl;
				p[++cnt]=j;
				add(b[j].x,1);
			}
		}
		for(int j=i+1;j<=n1;j++){
			while(k<=cnt&&b[p[k]].y2<a[j].x)add(b[p[k++]].x,-1);
			int dat=ask(a[j].y2)-ask(a[j].y1-1);
			ans+=1ll*dat*(dat-1)/2;
		}
		while(k<=cnt)add(b[p[k++]].x,-1);
	}
	cout<<ans;
	return 0;
}