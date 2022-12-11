#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <queue>
#include <assert.h>
#include <functional>
#include <complex>
#include <unordered_map>
#include <iomanip>
#include <numeric>

using namespace std;

typedef long long ll;
typedef long double ld;

const long double PI = 3.141592653589793;
const int INF = 2e9 + 10;
const ll LONGINF = 4e18;
const ll INF2 = 1e17 + 10;
const ll mod = 1e9 + 7;

enum Op {
    AND,
    XOR,
    IN,
    NOT,
    OR
};

vector<Op> type;
vector<bool> val;
vector<vector<int>> ch;
vector<bool> imp;

void dfs(int v) {
    for (auto i: ch[v]) {
        dfs(i);
    }
    switch (type[v]) {
        case IN:
            break;
        case NOT:
            val[v] = !val[ch[v].front()];
            break;
        case AND:
            val[v] = val[ch[v][0]] && val[ch[v][1]];
            break;
        case XOR:
            val[v] = val[ch[v][0]] ^ val[ch[v][1]];
            break;
        case OR:
            val[v] = val[ch[v][0]] || val[ch[v][1]];
            break;
    }
}

void dfsans(int v) {
    imp[v] = true;
    switch (type[v]) {
        case IN:
            break;
        case NOT:
            dfsans(ch[v][0]);
            break;
        case XOR:
            dfsans(ch[v][1]);
            dfsans(ch[v][0]);
            break;
        case OR:
            if (!val[ch[v][1]])
                dfsans(ch[v][0]);
            if (!val[ch[v][0]])
                dfsans(ch[v][1]);
            break;
        case AND:
            if (val[ch[v][1]])
                dfsans(ch[v][0]);
            if (val[ch[v][0]])
                dfsans(ch[v][1]);
            break;
    }
}

void solve(istream &cin = cin, ostream &cout = cout) {
    int n;
    cin >> n;
    string s;
    imp.resize(n, false);
    type.resize(n);
    val.resize(n);
    ch.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int a, b;
        if (s == "IN") {
            type[i] = IN;
            cin >> a;
            val[i] = a;
        } else if (s == "NOT") {
            type[i] = NOT;
            cin >> a;
            ch[i].push_back(a - 1);
        } else if (s == "AND") {
            type[i] = AND;
            cin >> a >> b;
            ch[i].push_back(a - 1);
            ch[i].push_back(b - 1);
        } else if (s == "XOR") {
            type[i] = XOR;
            cin >> a >> b;
            ch[i].push_back(a - 1);
            ch[i].push_back(b - 1);
        } else {
            type[i] = OR;
            cin >> a >> b;
            ch[i].push_back(a - 1);
            ch[i].push_back(b - 1);
        }
    }
    dfs(0);
    dfsans(0);
    for (int i = 0; i < n; ++i) {
        if (type[i] == IN) {
            cout << (imp[i] ^ val[0]);
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);

    solve();
    return 0;
}