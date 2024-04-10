#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
int main() {
    int n;
    scanf ("%d",&n);
    printf ("%d\n",n+1);
    vector<int> a(n);
    for (auto &au : a) scanf ("%d",&au);
    for (int i = n-1; i >= 0; i--) {
        int go = (i-(a[i]%n)+n)%n;
        printf ("1 %d %d\n",i+1,go);
        for (int j = i; j >= 0; j--) a[j] += go;
    }
    printf ("2 %d %d\n",n,n);
    return 0;
}