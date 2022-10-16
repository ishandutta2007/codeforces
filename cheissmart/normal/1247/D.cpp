#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

const int N = 1e5 + 87, M = 350;

int a[N], np[M], ok[N], n, k;
vi primes;

struct Trie{
	struct nd{
		map<int, nd*> nxt;
		int cnt;
		nd() {
			cnt = 0;
		}
	}* root;
	Trie(){
		root = new nd();
	}
	void insert(vi& v) {
		nd* ptr = root;
		for(int i:v) {
			if(ptr->nxt[i] == nullptr) ptr->nxt[i] = new nd();
			ptr = ptr->nxt[i];
		}
		(ptr->cnt)++;
	}
	int qry(vi & v) {
		nd* ptr = root;
		for(int j:v) {
			int i = (k - j) % k;
			if(ptr->nxt[i] == nullptr) ptr->nxt[i] = new nd();
			ptr = ptr->nxt[i];
		}
		return ptr->cnt;
	}
} tt;

map<int, Trie> m;

signed main()
{
	IO_OP;
	
	for(int i=2;i<M;i++) {
		if(np[i]) continue;
		primes.PB(i);
		for(int j=i*i;j<M;j+=i) {
			np[j] = 1;
		}
	}
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	ll ans = 0;
	for(int i=0;i<n;i++) {
		int t = a[i];
		vi v;
		for(int p:primes) {
			int cnt = 0;
			while(t % p == 0) t /= p, cnt++;
			v.PB(cnt%k);
		}
		if(t != 1) {
			if( k == 2) ans += (ll)m[t].qry(v);
			m[t].insert(v);
		} else {
			ans += (ll)tt.qry(v);
			tt.insert(v);
		}
	}
	cout << ans << endl;

}