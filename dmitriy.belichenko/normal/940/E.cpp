#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
#include <random>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
#define ld long double
#define mt make_tuple
using namespace std;
const int N = 1e5 + 5;
ll a[N] , dp[N];
ll sum = 0;
multiset<ll> kek;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , c;
    cin >> n >> c;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        sum += a[i];
        if (i >= c)
        {
            sum -= a[i - c];
            auto it = kek.find(a[i - c]);
            if(it != kek.end()) kek.erase(it);
        }
        kek.insert(a[i]);
        dp[i + 1] = dp[i] + a[i];
        ll p = dp[i - c + 1] - *kek.begin();
        if (i > c - 2) dp[i + 1] = min(dp[i + 1], sum + p);
    }
    cout << dp[n] << "\n";
    return 0;
}