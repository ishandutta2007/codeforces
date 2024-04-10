#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<int> kra[1000002];
int funk[1000002];
vector<int> wejkra[1000002];
int kub[1000002], strat[1000002], odw[1000002];
int glakt = 1;
int perm1[1000002], perm2[1000002];

void zeruj(int n) {
    glakt = 1;
    for (int i=0; i<=n+1; i++) {
        strat[i] = 0;
        kub[i] = 0;
        odw[i] = 0;
        funk[i] = 0;
        wejkra[i].clear();
        kra[i].clear();
    }
}

int dfs(int n, int o, int wezojca) {
    vector<int> dowziecia;
    odw[n] = 1;
    for (int i=0; i<kra[n].size(); i++) {
        int v = kra[n][i];
        if (v == o)
            continue;
        int wezwez = -1;
        if (dowziecia.size() == 0 && o == -1 && i == kra[n].size() - 1) {
            wezwez = n;
        }
        int res = dfs(v, n, wezwez);
        if (res != 0) {
            dowziecia.push_back(res);
        }
    }
    if (wezojca != -1) {
        dowziecia.push_back(wezojca);
    }
    if (dowziecia.size() == 0) {
        return n;
    }
    perm2[n] = glakt;
    for (auto v : dowziecia) {
        perm1[v] = glakt;
        glakt++;
        perm2[v] = glakt;
    }
    perm1[n] = glakt;
    glakt++;
    return 0;
}

void fun() {
    int n, m;
    cin >> n >> m;
    zeruj(n);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        wejkra[a].push_back(b);
        wejkra[b].push_back(a);
    }
    int stratne = 0;
    for (int i = 1; i <= n; i++) {
        if (wejkra[i].size() == n-1) {
            stratne++;
            strat[i] = 1;
            continue;
        }
        for (auto v : wejkra[i]) {
            kub[v] = i;
        }
        for (int j = 1; j <= n; j++) {
            if (j == i)
                continue;
            if (kub[j] != i) {
                funk[i] = j;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (funk[funk[i]] == i) {
            if (i < funk[i]) {
                kra[i].push_back(funk[i]);
                kra[funk[i]].push_back(i);
            }
        } else {
            kra[i].push_back(funk[i]);
            kra[funk[i]].push_back(i);
        }
    }
    //cout << glakt << "\n";
    for (int i = 1; i <= n; i++) {
        if (strat[i] == 1 || odw[i] == 1) {
            continue;
        }
        dfs(i, -1, -1);
        //cout << glakt << "\n";
    }
    for (int i = 1; i <= n; i++) {
        if (strat[i] == 1) {
            perm1[i] = glakt;
            perm2[i] = glakt;
            glakt++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << perm1[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= n; i++) {
        cout << perm2[i] << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) fun();
}