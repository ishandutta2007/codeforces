#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 200005
using namespace std;
struct node{
	int a,t,key;
}p[N],q[N];
int n,T;
bool cmp(node x,node y){return x.a>y.a;}
int w[N],e[N],cnt[N];
void add(int pos){
	++cnt[pos];
	for(int x=pos;x<=20000;x+=x&-x)++w[x],e[x]+=pos;
}
int que2(int pos){
	int s=0;
	for(int x=pos;x;x-=x&-x)s+=w[x];
	return s;
}
int que(int T){
	int l=0,r=32768;
	while(l+1<r){
		int mid=l+r>>1;
		if(e[mid]<=T)T-=e[mid],l=mid;else r=mid;
	}
	return que2(l)+min(T/r,cnt[r]);
}
/*int que_s(int pos){
	int s=0;
	for(int x=pos;x;x-=x&-x)s+=e[x];
	return s;
}*/
bool cmp2(node x,node y){return x.t<y.t;}
int main(){
	scanf("%d%d",&n,&T);
	rep(i,n)scanf("%d%d",&p[i].a,&p[i].t),p[i].key=i;
	sort(p+1,p+n+1,cmp);
	int ans=0,tp=0;
	rep(i,n){
		add(p[i].t);
		int l=que(T);int ss=min(p[i].a,l);
		if(ans<ss)ans=ss,tp=i;
	}
	//printf("%d %d\n",ans,tp);
	printf("%d\n",ans);
	rep(i,tp)q[i]=p[i];
	sort(q+1,q+tp+1,cmp2);
	printf("%d\n",ans);
	rep(i,ans)printf("%d%c",q[i].key,i==ans?'\n':' ');
	if(ans==0)puts("");
	//system("pause");
	return 0;
}