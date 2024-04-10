
#include<iostream>
#include<math.h>
#include<cstring>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<ctime>
//#include "optimization.h"
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
const int N =  3e5 +100;
ll INF = (1LL << 62) - 1;
ll MOD = 1e9 + 7;
int a[N];
bool dp[N];
int fa[N];
int n, k;

bool check(int delta)
{
    for (int i = 1; i <= n; i++) dp[i] = 0;
    dp[0] = 0;
    fa[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if(i >= k && a[i] - a[fa[i - k] + 1] <= delta)
        {
            dp[i] = 1;
        }
        else dp[i] = 0;
        if(dp[i])
        {
            fa[i] = i;
        }
        else fa[i] = fa[i - 1];

    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int l = 0, r = a[n] - a[1], ans = 0;
    while(l < r + 1)
    {
        int mid = (l + r) / 2;
        if(check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << "\n";
    return 0;
}