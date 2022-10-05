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

const int N=55,M=N*N*N;
const int mod=998244353;
int f[N][N][N],a[N],w[N];
int n,m,sum[2];
int inv[M];

inline int power(int x,int p){
	int res=1;
	for(;p;p>>=1,x=(ll)x*x%mod)
		if(p&1)res=(ll)res*x%mod;
	return res;
}

inline void add(int &x,int y){
	x+=y,(x>=mod?x-=mod:0);
}

int solve(int A,int B,int C,int pa,int pc){
	memset(f,0,sizeof f);
	f[0][0][0]=1;
	cerr<<A<<" "<<B<<" "<<C<<" "<<pa<<" "<<pc<<endl;
	rep(i,0,m-1)rep(a,0,i)rep(b,0,i-a){
		int c=i-a-b,t=A+B+C+pa*(a+b)+pc*c;
		int aa=(ll)(A+a*pa)*inv[t]%mod;
		int bb=(ll)(B+b*pa)*inv[t]%mod;
		int cc=(ll)(C+c*pc)*inv[t]%mod;
		add(f[i+1][a+1][b],(ll)f[i][a][b]*aa%mod);
		add(f[i+1][a][b+1],(ll)f[i][a][b]*bb%mod);
		add(f[i+1][a][b],(ll)f[i][a][b]*cc%mod);
	}
	int ans=0;
	rep(a,0,m)rep(b,0,m-a){
		int c=m-a-b;
		add(ans,(ll)(A+a*pa)*f[m][a][b]%mod);
	}
	return ans;
}

int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)scanf("%d",&w[i]),sum[a[i]]+=w[i];
	rep(i,1,M-1)inv[i]=power(i,mod-2);
	rep(i,1,n){
		int A=w[i],B=sum[a[i]]-w[i],C=sum[a[i]^1];
		printf("%d\n",solve(A,B,C,a[i]?1:-1,a[i]?-1:1));
	}
	return 0;
}