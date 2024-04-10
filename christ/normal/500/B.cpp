#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 303, MOD = 1e9+7;
mt19937_64 rnd = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
int can[MN][MN];
char s[MN][MN];
int main() {
        int n;
    scanf ("%d",&n);
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
    for (int i = 1; i <= n; i++) {
        scanf ("%s",s[i]+1);
        for (int j = 1; j <= n; j++) {
            if (i == j) can[i][j] = 1;
            else if (s[i][j] == '1') can[i][j] = 1;
            else can[i][j] = 0;
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                can[i][j] |= can[i][k] && can[k][j];
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) if (a[j] < a[i] && can[i][j]) swap(a[i],a[j]);
    }
    for (int i = 1; i <= n; i++) printf ("%d%c",a[i]," \n"[i==n]);
    return 0;
}