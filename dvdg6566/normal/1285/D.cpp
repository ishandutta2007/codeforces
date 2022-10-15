#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
#define MAXN 1000100

ll N,a,b,c,d,e,f,x,y,E;
ll A[MAXN];
ll B[MAXN];
ll MOD =1e9+7;
ll ans,cnt,sub;
string S;

struct trie{
	trie *l, *r;
	ll lvl, val;

	trie(ll _l, ll v){
		// cout<<"New Node "<<_l<<' '<<v<<'\n';
		lvl = _l;
		val = v;
		l = r = nullptr;
	}
	
	void insert(ll x){
		if (lvl == 0)return;
		ll next_bit = (1LL<<(lvl-1) & x);
		if (next_bit){
			if (l == nullptr)l = new trie(lvl-1, val + (1LL<<(lvl-1)));
			l->insert(x);
		}else{
			if (r == nullptr)r = new trie(lvl-1, val);
			r->insert(x);
		}
	}

	bool work(ll x){
		// cout<<"Asking "<<lvl<<' '<<val<<'\n';
		ll next_bit = ((1LL<<(lvl-1)) & x);
		if (next_bit == 0){
			if (l == nullptr && r == nullptr)return 1;
			if (l != nullptr && r != nullptr)return 0;
			if (l == nullptr)return r->work(x);
			if (r == nullptr)return l->work(x);
			assert(0);
			return 0;
		}else{
			if (l == nullptr || r == nullptr)return 1;
			return l->work(x) || r->work(x);
		}
	}
}*root;

int main(){
	root = new trie(33,0);
	cin>>N;
	for (ll i=1;i<=N;++i){cin>>a;root->insert(a);}
	// cout<<root->work(1);
	// return 0;
	ll lp = 0;
	ll up = 100000000000LL;
	while (up > lp+1){
		ll mid = (lp+up)/2;
		// cout<<mid<<' '<<root->work(mid)<<'\n';
		if (root->work(mid))up = mid;
		else lp = mid;
	}
	if (root->work(lp))cout<<lp;
	else cout<<up;
}