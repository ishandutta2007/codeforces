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

const int N=1000005,mod=998244353;
int fac[N],n,u,v;
vi e[N];

int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		scanf("%d%d",&u,&v);
		e[u].pb(v),e[v].pb(u);
	}
	fac[0]=1;
	rep(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
	
	int ans=n;
	rep(i,1,n)ans=(ll)ans*fac[e[i].size()]%mod;
	cout<<ans<<endl;

	return 0;
}