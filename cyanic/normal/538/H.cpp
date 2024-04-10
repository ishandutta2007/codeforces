#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
using namespace std;
typedef vector<int> vi;

const int N=200005;
int l[N],r[N],col[N],n,m,mn,mx,n1,n2=1e9;
vi e[N];

void GG(){puts("IMPOSSIBLE"),exit(0);}
int f1(int i){return l[i]<=n1&&n1<=r[i];}
int f2(int i){return l[i]<=n2&&n2<=r[i];}

void dfs(int u,int c){
	if(col[u]){
		if(col[u]!=c)GG();
		return;
	}
	col[u]=c;
	for(auto v:e[u])dfs(v,3-c);
}

int main(){
	scanf("%d%d%d%d",&mn,&mx,&n,&m);
	rep(i,1,n){
		scanf("%d%d",&l[i],&r[i]);
		n1=max(n1,l[i]),n2=min(n2,r[i]);
	}
	rep(i,1,m){
		int a,b;
		scanf("%d%d",&a,&b);
		e[a].pb(b),e[b].pb(a);
	}
	if(n1+n2<mn)n1=mn-n2;
	if(n1+n2>mx)n2=mx-n1;
	if(n1<0||n2<0)GG();
	rep(i,1,n){
		if(!f1(i)&&!f2(i))GG();
		if(f1(i)&&!f2(i))dfs(i,1);
		if(!f1(i)&&f2(i))dfs(i,2);
	}
	rep(i,1,n)if(!col[i])dfs(i,1);
	puts("POSSIBLE");
	printf("%d %d\n",n1,n2);
	rep(i,1,n)printf("%d",col[i]);
	return 0;
}