#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define all(a) a.begin(),a.end()
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
#define endl "\n"
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define MOD2 1494318097
#define SEED 131
#define mp make_pair
#define fastio cin.tie(0); cin.sync_with_stdio(0);

#define MAXN 100005

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef unordered_map<int,int> umii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<int,pii> triple;
typedef int8_t byte;

mt19937 g1(time(0));

int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<long long>(a, b)(g1);}

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int len,arr[MAXN];
ll psa[MAXN];
multiset<ll> sums;
set<pii> s;

int main(){
	scanf("%d",&len);
	for(int i=1; i<=len; i++){
		scanf(" %d",&arr[i]);
		psa[i] = psa[i-1]+arr[i];
	}
	s.insert(mp(1,len));
	sums.insert(psa[len]);
	for(int i=1; i<=len; i++){
		int d; scanf(" %d",&d);
		pii seg = *--s.upper_bound(mp(d,INT_MAX));
		s.erase(seg);
		sums.erase(sums.find(psa[seg.second]-psa[seg.first-1]));
		if(seg.first != seg.second){
			ll f = psa[d-1]-psa[seg.first-1];
			ll ss = psa[seg.second]-psa[d];
			if(d == seg.first){
				s.insert(mp(seg.first+1,seg.second));
				sums.insert(ss);
			}else if(d == seg.second){
				s.insert(mp(seg.first,seg.second-1));
				sums.insert(f);
			}else{
				s.insert(mp(seg.first,d-1)); sums.insert(f);
				s.insert(mp(d+1,seg.second)); sums.insert(ss);
			}
		}
		if(sums.empty()) printf("0\n");
		else printf("%lld\n",*sums.rbegin());
	}
}