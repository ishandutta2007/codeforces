#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se seoncd
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
const int mod[2]={998244353,19360817};
const int bas[2]={233333,99};
int pw[2][N],n,m,u,v,cnt;
map<pii,int> cur;
ll c[N],sum[N];
vi e[N];

void rmain(){
	read(n),read(m);
	rep(i,1,n) e[i].clear(),read(c[i]);
	cnt=0;
	rep(i,1,m){
		read(u),read(v);
		e[v].pb(u);
	}
	cur.clear();
	rep(i,1,n){
		int s0=0,s1=0;
		for(auto j:e[i]){
			s0=(s0+pw[0][j])%mod[0];
			s1=(s1+pw[1][j])%mod[1];
		}
		if(e[i].empty()) continue;
		if(!cur[mp(s0,s1)]){
			cur[mp(s0,s1)]=++cnt;
			sum[cnt]=0;
		}
		//printf("## %d %d %d\n",i,s0,s1);
		sum[cur[mp(s0,s1)]]+=c[i];
	}
	ll ans=sum[1];
	rep(i,1,cnt){
		ans=__gcd(ans,sum[i]);
		//cout<<i<<" "<<sum[i]<<endl;
	}
	printf("%lld\n",ans);
}

int main(){
	pw[0][0]=pw[1][0]=1;
	REP(t,2) rep(i,1,N-1) pw[t][i]=(ll)pw[t][i-1]*bas[t]%mod[t];
	int T; read(T);
	while(T--) rmain();
	return 0;
}