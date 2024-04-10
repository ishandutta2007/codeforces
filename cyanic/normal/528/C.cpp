#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=500005;
struct edge{int v,l;}e[N];
int h[N],d[N],vis[N],cnt,n,m,a,b,ty,ans;

void add(int a,int b){
	e[cnt]=(edge){b,h[a]},h[a]=cnt++;
	e[cnt]=(edge){a,h[b]},h[b]=cnt++;
}

void dfs(int u){
	while(h[u]>=0){
		int k=h[u];
		h[u]=e[k].l;
		if(vis[k])continue;
		vis[k^1]=1;
		dfs(e[k].v);
		if(ty)printf("%d %d\n",u,e[k].v);
		else printf("%d %d\n",e[k].v,u);
		ty^=1;
	}
}

int main(){
	read(n),read(m);
	fill(h+1,h+n+1,-1);
	rep(i,1,m){
		read(a),read(b);
		d[a]++,d[b]++;
		add(a,b),ans++;
	}
	int las=0;
	rep(i,1,n)
		if(d[i]&1){
			if(las)add(las,i),las=0,ans++;
			else las=i;
		}
	if(ans&1)add(1,1),ans++;
	printf("%d\n",ans);
	dfs(1);
	return 0;
}