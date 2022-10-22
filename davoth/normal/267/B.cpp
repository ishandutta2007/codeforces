#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int MAXN = 1e2 + 5;
int n;
int A[MAXN], B[MAXN];
string ans;
bool bc[7];
vector<pair<int, int> > adj[7];
bool flag[MAXN * 3];

void dfs(int v) {
    bc[v] = true;
    if (adj[v].empty()) return;
    for (auto p : adj[v]) {
        int x = p.F, y = p.S;
        if(flag[y]) continue;
        flag[y] = true;
        if (y % 2 == 0) y++;
        else y--;
        flag[y] = true;
        dfs(x);
        ans += to_string(y / 2 + 1);
        ans += ' ';
        if (A[y / 2] == v) ans += "-\n";
        else ans += "+\n";
    }
}

int main() {
    fast_io;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i];
        adj[A[i]].emplace_back(B[i], i * 2);
        adj[B[i]].emplace_back(A[i], i * 2 + 1);
    }
    int odd = 0, odl = -1, le = -1, ll = 0;
    for (int i = 0; i < 7; i++) {
        if (adj[i].size() % 2 == 1) odd++, odl = i;
        else if (adj[i].size() > ll) ll = adj[i].size(), le = i;
    }
    int start;
    if (odd != 2 && odd != 0) return cout << "No solution", 0;
    if (odd == 0) start = le;
    else start = odl;
    int sz[7];
    for (int i = 0; i < 7; i++) sz[i] = adj[i].size();
    dfs(start);
    for (int i = 0; i < 7; i++) if (!bc[i] && sz[i]) return cout << "No solution", 0;
    cout << ans;
    return 0;
}
/*
100
1 5
0 3
0 0
3 1
1 5
0 5
3 0
3 0
5 3
2 4
3 4
1 3
6 2
1 5
1 5
5 4
6 0
6 0
0 0
3 3
5 6
6 3
4 3
5 6
4 0
4 2
2 6
0 6
6 6
4 1
2 0
1 5
1 0
1 5
0 0
1 6
4 5
3 0
3 2
1 4
2 1
4 4
0 6
3 0
5 4
0 4
3 5
3 6
5 3
1 4
5 0
1 4
2 2
3 6
2 0
1 5
6 4
5 3
2 6
5 1
5 2
5 3
4 0
5 0
1 6
6 1
5 5
5 4
1 4
3 0
1 1
4 4
4 6
0 5
6 6
2 2
0 5
4 4
4 2
4 5
2 1
4 1
6 6
1 4
0 5
2 4
2 6
5 2
0 0
4 1
2 4
0 0
5 5
5 1
3 1
0 1
0 5
2 6
3 1
3 4
98 +
87 -
59 +
27 -
13 -
66 +
65 +
22 +
62 -
58 +
49 -
47 -
9 -
88 +
61 -
94 +
60 -
56 -
34 +
32 -
15 +
14 -
5 +
1 -
36 +
43 -
28 +
18 +
97 +
85 -
77 +
74 -
64 -
51 +
6 +
16 +
78 -
72 -
42 -
100 -
23 -
91 -
86 +
79 +
26 -
11 -
20 -
39 +
76 -
53 -
10 +
90 +
84 +
82 +
69 +
52 -
50 +
40 -
99 -
95 +
12 +
4 +
81 -
41 +
71 -
30 -
63 +
46 +
25 +
70 -
44 +
38 -
8 +
7 -
2 -
55 -
31 +
96 +
33 +
92 -
89 -
35 -
19 -
3 -
17 -
 */