#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
int main() {
    int n,m;
    scanf ("%d %d",&n,&m);
    vector<int> a(n); set<int> go;
    for (auto &au : a) scanf ("%d",&au);
    while (m--) {
        int b; scanf ("%d",&b); go.insert(b);
    }
    for (int i : a) if (go.count(i)) printf ("%d ",i);
    printf ("\n");
    return 0;
}