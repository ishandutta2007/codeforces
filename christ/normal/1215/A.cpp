#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e3+3, MOD = 1e9+7;
int main() {
    int a1,a2,k1,k2;
    scanf ("%d %d %d %d",&a1,&a2,&k1,&k2);
    if (k1 > k2) {swap(a1,a2); swap(k1,k2);}
    int n;
    scanf ("%d",&n);
    int can = (k1-1)*a1 + (k2-1)*a2;
    int mn = max(0,n-can);
    int cango = min(a1,n/k1);
    n -= cango * k1;
    int mx = cango;
    cango = min(a2,n/k2);
    mx += cango;
    printf ("%d %d\n",mn,mx);
    return 0;
}