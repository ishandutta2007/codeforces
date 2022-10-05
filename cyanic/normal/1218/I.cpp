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

const int N=4005;
int a[N][N],b[N],vis[N],col[N],n;
vector<pii> e[N];
vi ansR,ansC;
char s[N];

void upd(int a,int b){
	if(col[a]==1-b){
		puts("-1");
		exit(0);
	}
	col[a]=b;
}

void dfs(int u){
	vis[u]=1;
	for(auto v:e[u])
		if(vis[v.fi]&&col[v.fi]!=-1&&(col[u]^col[v.fi])!=v.se){
			puts("-1");
			exit(0);
		}
		else if(!vis[v.fi]){
			col[v.fi]=v.se^col[u];
			dfs(v.fi);
		}
}

int main(){
	read(n);
	rep(i,1,n){
		scanf("%s",s+1);
		rep(j,1,n)
			if(s[j]=='1')a[i][j]^=1;
	}
	rep(i,1,n){
		scanf("%s",s+1);
		rep(j,1,n)
			if(s[j]=='1')a[i][j]^=1;
	}
	scanf("%s",s+1);
	rep(i,1,n)b[i]=(s[i]=='1');
	memset(col,-1,sizeof col);
	rep(i,1,n)rep(j,1,n)
		if(!b[i]&&!b[j]){
			if(a[i][j]){
				puts("-1");
				return 0;
			}
		}
		else if(b[i]&&b[j]){
			e[i].pb(mp(n+j,a[i][j]));
			e[n+j].pb(mp(i,a[i][j]));
		}
		else if(b[j]){
			upd(i,a[i][j]);
		}
		else if(b[i]){
			upd(n+j,a[i][j]);
		}
	rep(i,1,n*2)
		if(!vis[i]&&col[i]!=-1)
			dfs(i);
	rep(i,1,n*2)
		if(!vis[i]){
			col[i]=0;
			dfs(i);
		}
	rep(i,1,n)
		if(col[i])ansR.pb(i);
	rep(i,n+1,n*2)
		if(col[i])ansC.pb(i-n);
	printf("%d\n",(int)ansR.size()+(int)ansC.size());
	for(auto x:ansR)
		printf("row %d\n",x-1);
	for(auto x:ansC)
		printf("col %d\n",x-1);
	return 0;
}