#include <bits/stdc++.h>

using namespace std;

const int maxn = 2055;

int n, m;
int a[maxn];
vector<int> g[maxn];

int between[maxn];
int visited[maxn];
int matched[maxn];

bool dfs(int v) {
    if (visited[v]) return false;

    visited[v] = 1;
    for(int s : g[v]) {
        if (matched[s] == -1 || dfs(matched[s])) {
            matched[s] = v;
            matched[v] = s;
            return true;
        }
    }
    return false;
}

int main() {

    memset(matched, -1, sizeof matched);

    cin >> m >> n;
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        for(int j = 0; j < s.size(); ++j) {
            if(s[j] == '1') a[i] |= (1 << j);
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) if(i != j) {
            if ((a[i] & a[j]) == a[j]) {
                g[j].push_back(i+n);
            }
        }
    }

    vector<int> perm;
    for(int i = 0; i < n; ++i) perm.push_back(i);

    sort(perm.begin(), perm.end(), [&](int i, int j) {
        return __builtin_popcount(a[i]) > __builtin_popcount(a[j]); 
    });

    int R = n - 1;

    for(int i = 0; i < n; ++i) {
        memset(visited, 0, sizeof visited);
        R -= dfs(perm[i]);
    }

    for(int i = 0; i < n; ++i) {
        if (matched[i] != -1) between[matched[i] - n] = 1;
    }


    vector<char> ans;

    memset(visited, 0, sizeof visited);
    for(int i = 0; i < n; ++i) {
        if (between[i]) continue;
        visited[i] = true;

        if (ans.size()) ans.push_back('R');
        int start = i, current = 0;
        vector<int> path(1, start);
        while(true) {
            if (matched[start] == -1) break;
            start = matched[start] - n;
            visited[start] = true;
            path.push_back(start);
        }

        for(int j : path) {
            int need = a[j] - current;
            for(int b = 0; b < 10; ++b) if (need & (1 << b)) ans.push_back('0' + b);
            current += need;
        }
    }

    cout << ans.size() << endl;
    for(auto c : ans) cout << c << " ";
    cout << endl;

    return 0;
}