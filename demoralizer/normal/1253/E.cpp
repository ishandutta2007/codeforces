#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

int n,m;
int x[90],s[90];

int dp[100005][2];
int calc(int a,int b){
	//cout<<a<<" "<<b<<"\n";
	if(a>m)return 0;
	int &ans=dp[a][b];
	if(ans!=-1)return ans;
	if(b){
		ans=1+calc(a+1,1);
	}
	for(int i=0;i<n;i++){
		// if(x[i]<a)continue;
		int t=max(abs(x[i]-a),s[i]),c=t-s[i],tans=c+calc(x[i]+t+1,1);
		if(ans==-1 || tans<ans)ans=tans;
	}
	return ans;
}

void solve(){
	mem1(dp);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x[i]>>s[i];
	}
	cout<<calc(1,0);
}
signed main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}