#include<bits/stdc++.h>
#define pb push_back
#define LL long long
using namespace std;
const int N=4e6;
int t,h,g,n,m,a[N],d[N],son[N];LL ans;
vector<int>v;
int read(){
	int x=0,c;
	while(!isdigit(c=getchar()));
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
void up(int x){int lc=x<<1,rc=x<<1|1;son[x]=!a[lc]&&!a[rc]?x:a[lc]>a[rc]?son[lc]:son[rc];}
void build(int x){
	if(!a[x])return;
	build(x<<1);build(x<<1|1);
	up(x);
}
void erase(int x){//cout<<x<<" ";
	int lc=x<<1,rc=x<<1|1;
	if(!a[lc]&&!a[rc])a[x]=0;
	else if(a[lc]>a[rc])a[x]=a[lc],erase(lc);
	else a[x]=a[rc],erase(rc);
	up(x);
}
void solve(int x){
	if(!a[x])return;
	while(a[x]&&d[son[x]]>g)ans-=a[x],erase(x),v.pb(x);//cout<<1;
	solve(x<<1);solve(x<<1|1);
}
void solve(){
	scanf("%d%d",&h,&g);n=(1<<h)-1;m=(1<<g)-1;ans=0;v.clear();
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),ans+=a[i];
	build(1);solve(1);
	cout<<ans<<endl;
	for(int i=0;i<v.size();i++)printf("%d ",v[i]);puts("");
	for(int i=1;i<=n;i++)a[i]=0;
}
int main(){
	for(int i=1;i<N;i++)d[i]=d[i>>1]+1;
	t=read();
	while(t--)solve();
	return 0;
}