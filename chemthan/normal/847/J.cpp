#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000007
#define sz(a) ((ll)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcnt(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-12
typedef pair<int, int> II;
typedef pair<ll, ll> LL;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI (2 * acos((ld)0))
#define linf (1ll << 60)
#define y1 y32432
#define y0 y435346

#define maxn 5005
#define maxv 20005
#define maxe 100005

struct Dinic {
    int n, s, t, E, adj[maxe], flow[maxe], cap[maxe], next[maxe], last[maxv], run[maxv], level[maxv], que[maxv];

    void init(int _n, int _s, int _t) {
        n = _n; s = _s; t = _t; E = 0;
        For(i, 0, n) last[i] = -1;
    }

    void add(int u, int v, int c1, int c2) {
        adj[E] = v; flow[E] = 0; cap[E] = c1; next[E] = last[u]; last[u] = E++;
        adj[E] = u; flow[E] = 0; cap[E] = c2; next[E] = last[v]; last[v] = E++;
    }

    bool bfs() {
        For(i, 0, n) level[i] = -1;
        level[s] = 0;

        int qsize = 0;
        que[qsize++] = s;

        Rep(i, qsize) {
            for (int u = que[i], e = last[u]; e != -1; e = next[e]) {
                int v = adj[e];
                if (flow[e] < cap[e] && level[v] == -1) {
                    level[v] = level[u] + 1;
                    que[qsize++] = v;
                }
            }
        }

        return level[t] != -1;
    }

    int dfs(int u, int bot) {
        if (u == t) return bot;
        for (int &e = run[u]; e != -1; e = next[e]) {
            int v = adj[e], delta = 0;
            if (level[v] == level[u] + 1 && flow[e] < cap[e] && (delta = dfs(v, min(bot, cap[e] - flow[e]))) > 0) {
                flow[e] += delta; flow[e ^ 1] -= delta;
                return delta;
            }
        }
        return 0;
    }

    int maxflow() {
        int total = 0;
        while (bfs()) {
            For(i, 0, n) run[i] = last[i];
            for (int delta = dfs(s, inf); delta > 0; delta = dfs(s, inf)) total += delta;
        }
        return total;
    }
} dinic;

int n, m, a[maxn], b[maxn];

bool can(int d, int print){
	dinic.init(2 + n + m, 0, 1 + n + m);
	Rep(i, m){
		dinic.add(a[i], 1 + n + i, 1, 0);
		dinic.add(b[i], 1 + n + i, 1, 0);
	}
	For(i, 1, n) dinic.add(0, i, d, 0);
	For(i, 1, m) dinic.add(n + i, 1 + n + m, 1, 0);
	if(dinic.maxflow() == m){
		if(print){
			cout << d << "\n";
			Rep(i, m){
				if(dinic.flow[i * 4]){
					cout << a[i] << " " << b[i] << "\n";
				} else {
					cout << b[i] << " " << a[i] << "\n";
				}
			}
		}
		return 1;
	}
	return 0;
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	Rep(i, m) cin >> a[i] >> b[i];

	int l = 0, r = m + 1, mid;
	while(l < r){
		mid = (l + r) >> 1;
		if(can(mid, 0)) r = mid;
		else l = mid + 1;
	}

	can(l, 1);

	return 0;
}