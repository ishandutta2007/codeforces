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
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
const int N = 4e5;
const int INF = 1e9;
ll MOD =  1000000007;
ll ans = 0LL;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n , ans;
    cin >> n;
    int k = 0;
    while (k * k <= n) k++;
    ans = (k - 1) * 4;
    k--;
    n -= k * k;
    if (n == 1)
    {
        ans += 2;
    }
    else
        if (n <= k && n!=0)
    {
        ans += 2;
    }
    else
        if (n!=0)
    {
        ans += 4;
    }
    cout << ans << "\n";
    return 0;
}