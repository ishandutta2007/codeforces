#include <bits/stdc++.h>

using namespace std;

inline void boost(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

struct cir{
    long long x, y, r;
};

long long p[1003], pr[1003];
cir c[1003];
vector<long long> a[1003];
long long area = 0;

bool check(cir a, cir b){
    if (a.r > b.r){
        return false;
    }
    long long dist = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
    return dist <= b.r * b.r;
}

void dfs2(long long i, bool b){
    if (b){
        area += c[i].r * c[i].r;
    } else
        area -= c[i].r * c[i].r;
    for (long long v: a[i])
        dfs2(v, !b);
}

void dfs1(long long i){
    area += c[i].r * c[i].r;
    for (long long v: a[i])
        dfs2(v, true);
}

inline void solve(){
    long long n;
    cin >> n;
    for (long long i = 0; i < n; ++i){
        cin >> c[i].x >> c[i].y >> c[i].r;
        pr[i] = LONG_MAX;
    }
    for (long long i = 0; i < n; ++i){
        for (long long j = 0; j < n; ++j){
            if (i == j)
                continue;
            if (check(c[j], c[i]) && c[i].r < pr[j]){
                pr[j] = c[i].r;
                p[j] = i;
            }
        }
    }
    for (long long i = 0; i < n; ++i){
        if (pr[i] != LONG_MAX){
            a[p[i]].push_back(i);
        }
    }
    for (long long i = 0; i < n; ++i){
        if (pr[i] == LONG_MAX)
            dfs1(i);
    }
    cout << setprecision(10) << fixed;
    cout << (long double)3.14159265359 * area;
}

int main(){
    boost();
    solve();
}