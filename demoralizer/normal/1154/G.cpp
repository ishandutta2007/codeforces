#include "bits/stdc++.h"
using namespace std;
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

const int N=1e7+5;

vector<int> a[N];

pii mn,smn;
void insert(pii x){
	if(mn.fr == -1){
		swap(mn,x);
	}
	else if(mn.fr >= x.fr){
		swap(mn,smn);
		swap(mn,x);
	}
	else if(smn.fr == -1 || smn.fr > x.fr){
		swap(smn,x);
	}
}

void solve(){
	int n;
	cin >> n;
	rep(i,0,n){
		int x;
		cin >> x;
		if(sz(a[x]) < 2)
			a[x].pb(i+1);
	}
	
	long long ans = INF;
	pii pr;
	
	rep(i,1,1e7+1){
		mn.fr = smn.fr = -1;
		for(int j = 1; i * j < N; j++){
			if(sz(a[i*j])){
				insert({j,a[i*j].front()});
			}
			if(sz(a[i*j]) > 1){
				insert({j,a[i*j].back()});
			}
		}
		if(smn.fr != -1){
			// TODO
			long long tmp = i;
			tmp *= mn.fr;
			tmp *= smn.fr;
			if(tmp < ans){
				ans = tmp;
				pr = {mn.sc,smn.sc};
			}
		}
	}
	if(pr.fr > pr.sc) swap(pr.fr,pr.sc);
	cout << pr;
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