#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 11111, inf = 111111111;
const int C = 1;
const int D = 2;
const int E = 3;
const int F = 4;
const int G = 5;

map<string, int> m[max_n];
vector<int> g[max_n], f[max_n];
int ans1, ans2;

pair<int, int> dfs(int v) {
    int qqq = 0, QQQ = 0;
    //cout << v  << endl;
    for (int i = 0; i < g[v].size(); ++i) {
        if (f[v][i] == 2) {
            ++qqq;
        } else {
            ++QQQ;
            pair<int, int> Q = dfs(g[v][i]);
            qqq += Q.second;
            QQQ += Q.first;
        }
    }
    if (v > 9) {ans1 = max(ans1, QQQ);
    ans2 = max(ans2, qqq);}
    //cout << v << " - " << QQQ << ' ' << qqq << endl;
    return make_pair(QQQ, qqq);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int cnt = 10;
    while (!feof(stdin)) {
        //cout << endl;
        string s;
        cin >> s;
        if (s == "") {
            break;
        }
        string ppp = "";
        int disk = s[0] - 'C';
        int last_folder = disk;
        for (int i = 3; i < s.length(); ++i) {
            if (s[i] == 92) {
                //cout << last_folder << ' ' << ppp << endl;
                if (!m[last_folder].count(ppp)) {
                    ++cnt;
                    m[last_folder][ppp] = cnt;
                    g[last_folder].push_back(m[last_folder][ppp]);
                    f[last_folder].push_back(1);
                }
                last_folder = m[last_folder][ppp];
                ppp = "";
            } else {
                ppp += s[i];
            }
        }
        //cout << last_folder << ' ' << ppp << endl;
        if (!m[last_folder].count(ppp)) {
            ++cnt;
            m[last_folder][ppp] = cnt;
            g[last_folder].push_back(m[last_folder][ppp]);
            f[last_folder].push_back(2);
        }
        //cout << m[last_folder][ppp];
    }
    ans1 = ans2 = 0;
    dfs(0);
    dfs(1);
    dfs(2);
    dfs(3);
    dfs(4);
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}