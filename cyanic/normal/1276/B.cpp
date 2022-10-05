#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
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
int f[N],g[N],q[N],n,m,a,b;
vi e[N];

void bfs(int f[],int s,int ban){
	rep(i,1,n) f[i]=0;
	int l=0,r=0;
	q[r++]=s,f[s]=1;
	while(l<r){
		int u=q[l++];
//		printf("# %d %d\n",s,u);
		for(auto v:e[u])
			if(!f[v]&&v!=ban){
				f[v]=1;
				q[r++]=v;
			}
	}
}

void rmain(){
	read(n),read(m);
	read(a),read(b);
	rep(i,1,n) e[i].clear();
	rep(i,1,m){
		int x,y;
		read(x),read(y);
		e[x].pb(y),e[y].pb(x);
	}
	bfs(f,a,b),bfs(g,b,a);
	int A=0,B=0;
	rep(i,1,n) A+=(f[i]&&!g[i]&&i!=a);
	rep(i,1,n) B+=(g[i]&&!f[i]&&i!=b);
	cout<<(ll)A*B<<endl;
}

int main(){
	int T;
	read(T);
	while(T--) rmain();	
	return 0;
}