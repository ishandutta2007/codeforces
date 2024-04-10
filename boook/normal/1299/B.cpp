#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define PII pair<int, int>
#define F first
#define S second
#define maxn 100000 + 10

PII operator + (PII x , PII y){ return mp(x.F + y.F , x.S + y.S); }
PII operator - (PII x , PII y){ return mp(x.F - y.F , x.S - y.S); }
PII operator * (PII x , PII y){ return mp(x.F * y.F , x.S * y.S); }
int cross(PII x , PII y){
    int val = x.F * y.S - x.S * y.F;
    return (val > 0) - (val < 0);
}

int n;
PII x[maxn];

int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++ i)
        cin >> x[i].F >> x[i].S;
    int ok = 1;
    for (int i = 0; i < n; ++ i) {
        int v1 = i, v2 = (i + n / 2) % n;
        PII a = x[(v1 + 1) % n] - x[v1];
        PII b = x[(v2 + 1) % n] - x[v2];
        int dis1 = (a.F * a.F + a.S * a.S);
        int dis2 = (b.F * b.F + b.S * b.S);
        if (cross(a, b) != 0 || dis1 != dis2) ok = 0;
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}