#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=3005;

vector<vector<int>> ans;
int a[N];

void solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	rep(i,0,n){
		a[i]=(s[i]=='R');
	}
	bool flag=1;
	int cnt=0;
	while(flag){
		flag=0;
		ans.pb(vector<int>());
		rep(i,0,n-1){
			if(a[i]==1 && a[i+1]==0){
				flag=1;
				ans.back().pb(i+1);cnt++;
				i++;
			}
		}
		for(int x:ans.back()){
			swap(a[x-1],a[x]);
		}
	}
	ans.ppb();
	if(k<sz(ans) || k>cnt){
		cout<<-1;
		return;
	}
	int r=sz(ans);
	int x=0,y=0;
	while(k>r-x){
		cout<<"1 "<<ans[x][y]<<"\n";k--;
		y++;
		if(y==sz(ans[x]))x++,y=0;
	}
	
	cout<<sz(ans[x])-y;
	rep(i,y,sz(ans[x])){
		cout<<" "<<ans[x][i];
	}
	cout<<"\n";
	rep(i,x+1,r){
		cout<<sz(ans[i]);
		for(int x:ans[i])cout<<" "<<x;
		cout<<"\n";
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}