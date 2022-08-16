#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
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

const int N=0;


void solve(){
	int n,k;
	cin>>n>>k;
	int l1,r1,l2,r2;
	cin>>l1>>r1>>l2>>r2;
	
	// identical
	if(l1 == l2 && r1 == r2){
		int o = r1 - l1;
		o *= n;
		if(o >= k){
			cout<<"0\n";
		}
		else{
			cout<< (k-o)*2 << "\n";
		}
		return;
	}
	
	if(l1 > l2){
		swap(l1,l2);
		swap(r1,r2);
	}
	
	// partial overlap
	if(r1 >= l2 && r1 <= r2){
		int o = r2 - l1;
		o *= n;
		int fans = 0;
		if(o < k){
			fans += (k-o)*2;
		}
		int cur = r1 - l2;
		cur *= n;
		if(cur >= k){
			cout <<"0\n";
		}
		else{
			k = min(o,k);
			fans += k - cur;
			cout<<fans<<"\n";
		}
		return;
	}
	
	// completely in
	if(l2 >= l1 && r2 <= r1){
		int o = r1 - l1;
		o *= n;
		int fans = 0;
		if(o < k){
			fans += (k-o)*2;
		}
		int cur = r2 - l2;
		cur *= n;
		if(cur >= k){
			cout <<"0\n";
		}
		else{
			k = min(o,k);
			fans += k - cur;
			cout<<fans<<"\n";
		}
		return;
	}
	
	
	// away
	int o = r2 - l1;
	int dis = l2 - r1;
	int fans = 0;
	int ans = INF;
	
	
	rep(i,0,n){
		fans += dis;
		if(o >= k){
			fans += k;
			amin(ans,fans);
			break;
		}
		fans += o;
		k -= o;
		amin(ans,fans + 2*k);
	}
	cout<<ans<<"\n";
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}