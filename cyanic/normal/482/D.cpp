#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define clr(x) memset(x,0,sizeof x)
using namespace std;
typedef unsigned long long u64;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int mod=1e9+7;
const int N=100005;
int f[N][2],p[N],n;
vi e[N];

void dfs(int u){
	int s1[2],t[2],S[2],T[2],s0=0;
	clr(s1); clr(S);
	s1[0]=s0=S[0]=1;	
	for(auto v:e[u]){
		dfs(v); clr(t);
		REP(a,2){
			t[a^1]=(ll)s1[a]*f[v][1]%mod;
		}
		REP(a,2){
			s1[a]=(s1[a]+t[a])%mod;
		}
		s0=(ll)s0*(1+f[v][0])%mod;
		T[0]=(ll)S[1]*f[v][1]%mod;
		T[1]=(ll)S[0]*f[v][1]%mod;
		S[0]=((ll)S[0]*(f[v][0]+1)+T[0])%mod;
		S[1]=((ll)S[1]*(f[v][0]+1)+T[1])%mod;
	}
	f[u][0]=2ll*S[1]%mod;
	f[u][1]=2ll*S[0]%mod;
	f[u][1]=(f[u][1]+mod-s0)%mod;
	f[u][0]=(f[u][0]+mod-s1[1])%mod;
}

int main(){
	read(n);
	rep(i,2,n){
		read(p[i]);
		e[p[i]].pb(i);
	}
	dfs(1);
	printf("%d\n",(f[1][0]+f[1][1])%mod);
	return 0;
}