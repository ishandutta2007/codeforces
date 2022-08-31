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

int a[5005];
int b[5005];
int c[5005];

int n,m,k;
vector<int> lis[5005];
int l[5005];
int dp[5005][5005];

int calc(int p,int s){
	if(s<a[p])return -M;
	if(p>n)return 0;
	int &ans=dp[p][s];
	if(ans!=-1)return ans;
	s+=b[p];
	ans=calc(p+1,s);
	int t=0;
	rep(i,0,lis[p].size()){
		t+=lis[p][i];
		int q=t+calc(p+1,s-i-1);
		if(q<0)break;
		ans=max(ans,q);
	}
	return ans;
}

void solve(){
	mem1(dp);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		l[i]=i;
	}
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		l[y]=max(x,l[y]);
	}
	rep(i,1,n+1){
		lis[l[i]].pb(c[i]);
	}
	rep(i,1,n+1){
		sort(all(lis[i]),greater<int>());
	}
	int ans=calc(1,k);
	if(ans<0)ans=-1;
	cout<<ans;
}

signed main(){
	ios_base::sync_with_stdio(false);
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}