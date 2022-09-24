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
pair <ll, ll> dp[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    ll Alice = 0 , Bob = 0;
    for(int i = 0 ; i < n; i++) cin >> a[i];
    dp[n] = mp(0, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        ll sum = 0;
        pair <ll, ll> curr;
        for (int j = i; j <= n - 1; j++)
        {
            int next = j + 1;
            curr = mp(dp[next].snd + a[j] ,  dp[next].fst + sum);
            dp[i] = max(dp[i], curr);
            sum += a[j];
        }
        Alice = dp[0].snd;
        Bob = dp[0].fst;
    }
    cout << Alice << " " << Bob << "\n";

    return 0;
}