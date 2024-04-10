// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;
/*
static char buf[450 << 20];
size_t idx = sizeof buf;
void* operator new(size_t s) {
	assert(s < idx);
	return (void*)&buf[idx -= s];
}
void operator delete(void*) {}

template<class T> struct ptr {
	unsigned ind;
	ptr(T* p = 0) : ind(p ? unsigned((char*)p - buf) : 0) {
		assert(ind < sizeof buf);
	}
	T& operator*() const { return *(T*)(buf + ind); }
	T* operator->() const { return &**this; }
	T& operator[](int a) const { return (&**this)[a]; }
	explicit operator bool() const { return ind; }
};
*/
namespace sst {
    class SST {
    public:
    	ll sum;
    	SST* ch[2];
    	SST() : sum(0) {
    		ch[0] = nullptr;
    		ch[1] = nullptr;
    	}
    	void inc(int val, int diff, int dep=16) {
    		sum += diff;
    		if (!dep) return;
    		bool cv = val & (1 << (dep - 1));
    		if (!ch[cv]) ch[cv] = new SST;
    		ch[cv]->inc(val, diff, dep-1);
    	}
    };
    
    inline ll psum(SST* root, int val) {
    	int dep = 16; ll ans = 0;
    	while(dep && root) {
    		bool cv = val & (1 << (--dep));
    		if (cv && root->ch[0]) ans += root->ch[0]->sum;
    		root = root->ch[cv];
    	}
    	return ans + (root ? root->sum : 0);
    }
}

class IaIs {
public:
    sst::SST* di, *idi;
    IaIs() { using namespace sst; di = new SST(); idi = new SST(); }
    void ia(int r, int dt) { di->inc(r, dt); idi->inc(r, r*dt); }
    void ia(int l, int r, int dt) { ia(r+1, -dt); ia(l, dt); }
    ll is(int r) { using namespace sst; return (r+1) * psum(di, r) - psum(idi, r); }
    ll is(int l, int r) { return is(r) - is(l-1); }
};

IaIs colors[50004];
vector<int> elist[50004];

#define size MY_FUCKING_size

int size[50004], heavy[50004];
int hp[50004], par[50004], dep[50004];

void dfsSize(int u=1, int f=-1) {
    if(f == -1) dep[u] = 1;
    else dep[u] = dep[f] + 1;
    size[u] = 1, heavy[u] = -1; par[u] = f;
    for(int& v:elist[u]) if(v != f) {
        dfsSize(v, u);
        size[u] += size[v];
        if(heavy[u] == -1 || size[heavy[u]] < size[v]) heavy[u] = v;
    }
}

#define clock MY_FUCKING_clock

int clock = 1;
int toDfs[50004];

ll askLink(int L, int R, int color) {
    return colors[color].is(toDfs[L], toDfs[R]);
}

void addLink(int L, int R, int dt, int color) {
    return colors[color].ia(toDfs[L], toDfs[R], dt);
}

void dfsHeav(int u=1, int f=-1) {
    if(f == -1) hp[u] = u;
    toDfs[u] = clock++;
    if(heavy[u] != -1) {
        hp[heavy[u]] = hp[u];
        dfsHeav(heavy[u], u);
    }
    for(int& v:elist[u]) if(v != f && v != heavy[u]) {
        hp[v] = v;
        dfsHeav(v, u);
    }
}

ll askToRoot(int u, int color) {
    ll ans = 0;
    while(u != -1) {
        ans += askLink(hp[u], u, color);
        u = par[hp[u]];
    }
    return ans;
}

void addToRoot(int u, int dt, int color) {
    while(u != -1) {
        addLink(hp[u], u, dt, color);
        u = par[hp[u]];
    }
}

int type[50004];
int ck[50004];
ll sumT[50004], sumT2[50004];

void make(int i, int dt) {
    sumT[type[i]] += dt * dep[i];
    sumT2[type[i]] += dt * (2 * askToRoot(i, type[i])) + dep[i];
    addToRoot(i, dt, type[i]);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, q, c; cin >> n >> m >> q >> c;
    rep1(i, n) cin >> type[i];
    iter(i, 2, n+1) {
        int f; cin >> f;
        elist[f].pb(i);
        elist[i].pb(f);
    }
    rep1(i, m) cin >> ck[i];
    dfsSize();
    dfsHeav();
    rep1(i, n) {
        make(i, 1);
    }
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int x, w; cin >> x >> w;
            make(x, -1);
            type[x] = w;
            make(x, 1);
        } else {
            int k; cin >> k;
            ll ans = 1ll * n * c * c;
            ans += 1ll * ck[k] * ck[k] * sumT2[k];
            ans -= 2 * ck[k] * c * sumT[k];
            long double v = ans;
            v /= n;
            cout << fixed << setprecision(20) << v << endl;
        }
    }
}