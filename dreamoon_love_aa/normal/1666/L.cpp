#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB push_back
using namespace std;
const int SIZE = 200'001;
vector<int> e[SIZE];
bool u[SIZE], dis1[SIZE];
int s, from[SIZE];
void track(vector<int>& res, int x) {
    if(x == s) {
        res.PB(x);
        return;
    }
    track(res, from[x]);
    res.PB(x);
}
void print(int y) {
    vector<int> res;
    track(res, y);
    cout << SZ(res) << '\n';
    for(int i = 0; i < SZ(res); i++) {
        cout << res[i] << (i + 1 < SZ(res) ? ' ' : '\n');
    }
}
int subtree_root[SIZE];
void dfs(int x, int rt) {
    subtree_root[x] = rt;
    u[x] = 1;
    for(int y: e[x]){
        if(u[y]) {
            if(subtree_root[y] != rt) {
                cout << "Possible\n";
                print(y);
                from[y] = x;
                print(y);
                exit(0);
            }
        } else {
            if(dis1[y]) {
                cout << "Possible\n";
                cout << "2\n" << s << ' ' << y << '\n';
                from[y] = x;
                print(y);
                exit(0);
            }
            from[y] = x;
            dfs(y, rt);
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if(y == s) continue;
        if(x == s) dis1[y] = 1;
        e[x].PB(y);
    }
    for(int y: e[s]) {
        from[y] = s;
        dfs(y, y);
    }
    cout << "Impossible\n";
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}