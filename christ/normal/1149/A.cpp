#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5+3, MOD = 1e9+7;
int main() {
    int n;
    scanf ("%d",&n);
    vector<int> a(n); int ones = 0;
    for (auto &au : a) scanf ("%d",&au), ones += au==1;
    int twos = n-ones;
    if (twos) printf ("2 "), --twos;
    if (ones&1) while (ones) printf ("1 "), --ones;
    else while (ones>1) printf ("1 "), --ones;
    while (twos) printf ("2 "), --twos;
    while (ones) printf ("1 "), --ones;
    printf ("\n");
    return 0;
}