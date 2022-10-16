#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define V vector
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "LINE(" << __LINE__ << ") ->" << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 4e5 + 7, M = 998244353;

int black[N], pw[N], who[N];
int HASH = 0;
deque<int> dk[N];

void SET(int i, int j) {
    HASH = (HASH + M - pw[i] * black[i]) % M;
    black[i] = j;
    HASH = (HASH + pw[i] * black[i]) % M;
}

void add_edge(int u, int v, int i) {
    if(who[u] == v) { // close cycle
        deque<int> cycle = dk[u];
        cycle.PB(i);
        dk[u].clear(), dk[v].clear();
        assert(cycle.size() % 2 == 0);
        for(int i = 0; i < int(cycle.size()); i++) {
            SET(cycle[i], i % 2);
            //black[cycle[i]] = i % 2;
        }
        who[u] = u, who[v] = v;
     } else {
        if(dk[u].size() < dk[v].size()) swap(u, v);
        int x = who[u], y = who[v];
        who[x] = y, who[y] = x;
        if(dk[u].empty()) {
            dk[u].PB(i);
            dk[v].PB(i);
            return;
        }
        //black[i] = 1 ^ black[dk[x].back()], dk[x].PB(i);
        SET(i, 1 ^ black[dk[x].back()]), dk[x].PB(i);
        for(int j:dk[v]) SET(j, 1 ^ black[dk[x].back()]), dk[x].PB(j);
        dk[u].push_front(i);
        for(int j:dk[v]) dk[u].push_front(j);
        swap(dk[u], dk[y]);
        dk[u].clear();
        who[u] = u;
        if(y != v) {
            dk[v].clear();
            who[v] = v;
        }
    }
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	pw[0] = 2;
	for(int i = 1; i < N; i++)
        pw[i] = pw[i - 1] * 2 % M;
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    for(int i = 1; i <= n1 + n2; i++) who[i] = i;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v + n1, i);
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if(op == 1) {
            int u, v;
            cin >> u >> v;
            add_edge(u, v + n1, m++);
            cout << HASH << endl;
        } else {
            int k = 0;
            for(int i = 0; i < m; i++)
                k += black[i];
            cout << k;
            for(int i = 0; i < m; i++) if(black[i])
                cout << " " << i + 1;
            cout << endl;
        }
    }

}