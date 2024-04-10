#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

string FileName = "vanity";

typedef long long base;

const int N = 5e5 + 1;
int n, m;
vector <pair <point, point>> ans;
set <point> all[3];
vector <point> edge[2];
set <int> star[N][2];
set <int> Pow;
int DSU[N];

int get(int i) {
    if (DSU[i] == i) return i;
    DSU[i] = get(DSU[i]);
    return DSU[i];
}

void sum(int i, int j) {
    Pow.erase(i); Pow.erase(j);
    if (star[i][0].size() + star[i][1].size() > star[j][0].size() + star[j][1].size()) swap(i, j);
    DSU[i] = j;
    for(int k: star[i][0]) star[j][0].insert(k);
    for(int k: star[i][1]) star[j][1].insert(k);
    set <int> M[2]; swap(star[i], M);
    if (star[j][0].size() == 1) Pow.insert(j);
}

int main() {
    ios::sync_with_stdio(false);
    scanf("%d", &n);
    For(j, 0, 2) {
        For(i, 0, n - 1) {
            int a, b; scanf("%d%d", &a, &b);
            --a; --b; if (b < a) swap(a, b);
            all[j].insert({a, b});
            all[2].insert({a, b});
        }
    }
    For(i, 0, n) DSU[i] = i;
    for(auto i: all[2]) {
        if (all[0].count(i) && all[1].count(i)) {
            all[0].erase(i);
            all[1].erase(i);
            DSU[get(i.x)] = get(i.y);
        }
    }
    For(j, 0, 2) {
        for(auto i: all[j]) {
            star[get(i.x)][j].insert((int)edge[j].size());
            star[get(i.y)][j].insert((int)edge[j].size());
            edge[j].pb(i);
        }
    }
    For(i, 0, n) {
        if (star[get(i)][0].size() == 1) {
            Pow.insert(get(i));
        }
    }
    while (Pow.size()) {
        int u = *Pow.begin();
        int k = *star[u][0].begin();
        pair <point, point> Q;
        Q.x = edge[0][k];
        int L = get(edge[0][k].x), R = get(edge[0][k].y);
        Pow.erase(L); Pow.erase(R);
        star[L][0].erase(k); star[R][0].erase(k);
        if (star[L][0].size() == 1) Pow.insert(L);
        if (star[R][0].size() == 1) Pow.insert(R);
        int v = *star[u][1].begin();
        Q.y = edge[1][v];
        L = get(edge[1][v].x); R = get(edge[1][v].y);
        Pow.erase(L); Pow.erase(R);
        star[L][1].erase(v); star[R][1].erase(v);
        if (star[L][1].size() == 1) Pow.insert(L);
        if (star[R][1].size() == 1) Pow.insert(R);
        sum(L, R);
        ans.pb(Q);
    }
    printf("%d\n", ans.size());
    For(i, 0, ans.size()) {
        printf("%d %d %d %d\n", ans[i].x.x + 1, ans[i].x.y + 1, ans[i].y.x + 1, ans[i].y.y + 1);
    }
}