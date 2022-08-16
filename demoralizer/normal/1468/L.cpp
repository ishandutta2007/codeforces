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

const int N=1e6+5;

#define SIEVE
int primes[N];
vector<int> prime;
void sieve(){
	for(int i=2;i<N;i++){
		if(primes[i]==0){
			prime.pb(i);
			for(int j=i*i;j<N;j+=i){
				primes[j]=1;
			}
		}
		primes[i]^=1;
	}
}

int a[1005];
int vis[1005];

void solve(){
	int n,k;
	cin >> n >> k;
	rep(i,0,n){
		cin >> a[i];
	}
	vector<int> pr,good;
	rep(i,0,n){
		int x = a[i];
		for(int i:prime){
			if(x % i) continue;
			while(x % i == 0){
				x /= i;
			}
			if(x == 1) pr.pb(i);
		}
		if(x == a[i]) pr.pb(x);
	}
	sort(all(pr));
	uniq(pr);
	
	vector<vector<int>> elems;
	
	for(int p:pr){
		int cnt = 0;
		vector<int> tmp;
		rep(i,0,n){
			int x = a[i];
			while(x % p == 0){
				x /= p;
			}
			if(x == 1) cnt++,tmp.pb(i);
		}
		if(cnt > 1){
			good.pb(p);
			elems.pb(tmp);
		}
	}
	
	int z = sz(good);
	if(k >= 2 * z){
		vector<int> ans;
		rep(i,0,z){
			ans.pb(elems[i][0]);
			ans.pb(elems[i][1]);
			vis[elems[i][0]] = 1;
			vis[elems[i][1]] = 1;
		}
		rep(i,0,n){
			if(vis[i]) continue;
			int x = a[i];
			for(int y:good){
				while(x % y == 0) x /= y;
			}
			if(x == 1){
				ans.pb(i);
				vis[i] = 1;
			}
		}
		if(sz(ans) < k){
			cout << 0;
			return;
		}
		ans.resize(k);
		for(int x:ans){
			cout << a[x] << " ";
		}
		return;
	}
	
	
	if(k % 2 == 0){
		vector<int> ans;
		rep(i,0,k/2){
			ans.pb(elems[i][0]);
			ans.pb(elems[i][1]);
		}
		for(int x:ans){
			cout << a[x] << " ";
		}
		return;
	}
	map<int, int> ids;
	rep(i,0,z){
		vis[elems[i][0]] = 1;
		vis[elems[i][1]] = 1;
		ids[good[i]] = i;
	}
	rep(i,0,n){
		if(vis[i]) continue;
		int x = a[i];
		int cnt = 0;
		vector<int> prs;
		for(int y:good){
			if(x % y == 0) cnt++,prs.pb(y);
			while(x % y == 0) x /= y;
		}
		if(x == 1 && cnt <= k / 2){
			vector<int> ans;
			ans.pb(i);
			for(int x:prs){
				ans.pb(elems[ids[x]][0]);
				ans.pb(elems[ids[x]][1]);
				ids[x] = -1;
			}
			int j = 0;
			while(sz(ans) < k){
				if(ids[good[j]] != -1){
					ans.pb(elems[j][0]);
					ans.pb(elems[j][1]);
				}
				j++;
			}
			for(int x:ans){
				cout << a[x] << " ";
			}
			return;
		}
	}
	cout << 0;
	return;

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
	//cin>>t;
	while(t--) solve();
	return 0;
}