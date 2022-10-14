// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;
 
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
#define int ll
const int MOD = 1000000007;

// Either globally or in a single class:
static char buf[450 << 20];
void* operator new(size_t s) {
	static size_t i = sizeof buf;
	assert(s < i);
	return (void*)&buf[i -= s];
}
void operator delete(void*) {}

const int inf = 1000000000000000000ll;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(); l->set(L, R, x); r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(); l->add(L, R, x); r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf) {
			l->set(lo,hi,mset); r->set(lo,hi,mset); mset = inf;
		}
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

//#undef int

vector<pair<pii, int>> monster;
vector<pii> byY, byX;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    Node* k = new Node(0, 1000009);
    int n, m, p; cin >> n >> m >> p;
    rep(i, n) {
        int a, b; cin >> a >> b;
        byX.pb({a, b});
    }
    rep(i, m) {
        int a, b; cin >> a >> b;
        byY.pb({a, b});
    }
    rep(i, p) {
        int a, b, c; cin >> a >> b >> c;
        monster.pb({{b, a}, c});
    }
    sort(all(byX));
    sort(all(byY));
    sort(all(monster));
    rep(i, n) {
		if(i && (byX[i].fi == byX[i-1].fi)) continue;
        int b = byX[i].se;
        if(i) {
            k->set(byX[i-1].fi+1, byX[i].fi+1, -b);
        }
        else {
            k->set(1, byX[0].fi+1, -b);
        }
    }
    ll opt = -inf; int mpt = 0;
    rep(i, m) {
        int b = byY[i].se;
        while(mpt != p && monster[mpt].fi.fi < byY[i].fi) {
            k->add(monster[mpt].fi.se+1, 1000007, monster[mpt].se);
            mpt++;
        }
        opt = max(opt, k->query(1, 1000007) - b);
    }
    cout << opt << endl;
}