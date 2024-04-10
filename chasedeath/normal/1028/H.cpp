#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=2e5+10,M=5.1e6+10,INF=1e9+10;

int n,m;
int stk[M][9],T[M];
int A[N];

struct BIT{
	int s[N];
	BIT(){ memset(s,63,sizeof s); }
	void Add(int p,int x){
		while(p) cmin(s[p],x),p-=p&-p;
	}
	int Que(int p){
		int res=1e8;
		while(p<=n) cmin(res,s[p]),p+=p&-p;
		return res;
	}
} tr;

vector <Pii> G[N];

int notpri[N],pri[N],pc;
int F[N],C,U[1<<8];
void Fac(int n){
	C=0;
	for(int i=1;pri[i]*pri[i]<=n;++i) if(n%pri[i]==0) {
		int c=0;
		while(n%pri[i]==0) c^=1,n/=pri[i];
		if(c) F[C++]=pri[i];
	}
	if(n>1) F[C++]=n;
}
int ans[M];

int main(){
	rep(i,2,N-1) if(!notpri[i]){
		pri[++pc]=i;
		for(int j=i;j<N;j+=i) notpri[j]=1;
	}
	n=rd(),m=rd();
	rep(i,1,n) A[i]=rd();
	rep(i,1,m){
		int l=rd(),r=rd();
		G[r].pb(mp(i,l));
	}
	rep(i,1,n) {
		Fac(A[i]);
		rep(S,0,(1<<C)-1){
			if(S==0) U[S]=1;
			else U[S]=U[S&(S-1)]*F[__lg(S&-S)];
			int x=U[S],t=C-__builtin_popcount(S); // cost
			//cout<<"!"<<i<<' '<<t<<' '<<x<<endl;
			rep(i,1,T[x]) {
				//cout<<"$"<<i<<' '<<(stk[x][i]&((1<<20)-1))<<' '<<(stk[x][i]>>20)<<' '<<t<<endl;
				tr.Add(stk[x][i]&((1<<20)-1),(stk[x][i]>>20)+t);
			}
			while(T[x] && (stk[x][T[x]]>>20)>=t) T[x]--;
			stk[x][++T[x]]=t<<20|i;
		}
		for(auto v:G[i]) ans[v.first]=tr.Que(v.second);
	}
	rep(i,1,m) printf("%d\n",ans[i]);
}