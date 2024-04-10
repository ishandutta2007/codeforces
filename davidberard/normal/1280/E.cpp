#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 1400000;
const int INF = 0x3f3f3f3f;

char type[N];
vector<int> ch[N];
int par[N];
int w[N];
int id[N];
ll val[N];
int loc[N];
string s;
ll R;

void build(int u) {
    //cerr << " : " << u << " :: " << type[u] << endl;
    if (type[u] == '*') {
        assert(ch[u].empty());
        w[u] = 1;
        return;
    }
    assert(ch[u].size());
    if (type[u] == 'Q') {
        assert(ch[u].size() == 1);
        build(ch[u][0]);
        return;
    }
    for (auto& v : ch[u]) {
        build(v);
    }
    if (type[u] == 'S') {
        w[u] = INF;
        for (auto& v : ch[u]) {
            w[u] = min(w[u], w[v]);
        }
        return;
    }
    if (type[u] == 'P') {
        w[u] = 0;
        for (auto& v : ch[u]) {
            w[u] += w[v];
        }
        return;
    }
    assert(false);
}

void assign(int u, ll per) {
    if (type[u] == '*') {
        val[u] = per;
    } else if (type[u] == 'S') {
        pii best(INF, INF);
        for (auto& v : ch[u]) {
            best = min(best, pii(w[v], v));
        }
        assign(best.second, per);
    } else if (type[u] == 'P') {
        for (auto& v : ch[u]) {
            assign(v, per);
        }
    } else {
        assert(false);
    }
}

void solve() {
    cin >> R;
    s = string();
    getline(cin, s);
    //cerr << " s=" << s << endl;

    int pos = 1;
    int rcount = 0;
    int tot = 1;
    type[1] = 'Q';
    ch[1].clear();
    par[1] = 0;
    for (auto& c : s) {
        if (c == ' ') continue;
        if (c == '(') {
            par[++tot] = pos;
            ch[pos].push_back(tot);
            ch[tot].clear();
            type[tot] == ' ';
            pos = tot;
        } else if (c == ')') {
            pos = par[pos];
        } else if (c == '*') {
            par[++tot] = pos;
            ch[pos].push_back(tot);
            ch[tot].clear();
            type[tot] = '*';
            id[tot] = ++rcount;
            loc[rcount] = tot;
            val[tot] = 0;
        } else if (c == 'S') {
            type[pos] = 'S';
        } else if (c == 'P') {
            type[pos] = 'P';
        }
    }
    build(1);
    assert(ch[1][0] == 2);
    /*
    for (int i=1; i<=tot; ++i) {
        //cerr << " w[" << i << "] = " << w[i] << endl;
    }
    */

    assign(2, w[2]*R);

    cout << "REVOLTING ";
    for (int i=1; i<=rcount; ++i) {
        cout << val[loc[i]] << " ";
    }
    cout << "\n";
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        solve();
    }
    return 0;
}