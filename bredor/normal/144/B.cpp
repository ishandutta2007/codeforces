//  228

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const long double EPS= (1e-10);
const long long MOD = 1e9 + 7;

int n,xa,xb,ya,yb, a[1005], b[1005], c[1005];
set<pair<int,int>> vis;
int go(int x, int y)
{
    if (vis.count({x,y}))
        return 0;
    vis.insert({x,y});
    for (int i = 0; i < n; i++){
        if (sqrt((x - a[i]) * (x - a[i]) + (y - b[i]) * (y - b[i])) <= c[i])
            return 0;
    }
    return 1;
}

int main()
{
    fast
    cin >> xa >> ya  >> xb >> yb >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];
    int ans = 0;
    for (int i = min(xa,xb); i <= max(xa,xb); i++)
        ans += go(i,ya) + go(i,yb);
    for (int i = min(ya,yb); i <= max(ya,yb); i++)
        ans += go(xa,i) + go(xb,i);
    cout << ans;
}