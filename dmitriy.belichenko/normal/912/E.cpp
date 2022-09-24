#include <iostream>
#include <map>
#include <vector>
#include <cassert>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
#define ld long double
const double PI = acos(-1);
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
ll sum(ll a, ll b)
{
    a += b;
    if (a < 0)
        return  a + MOD;
    if (a >= MOD)
        return a - MOD;
    else return a;
}

ll mult(ll a, ll  b)
{
    long long c = 1LL * (a % MOD) * (b % MOD);
    return c % MOD;
}
int poww(long long a, long long b)
{
    long long res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}

int arr[16] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53 };
long long brr[16];
const long long INF = 1e18;
vector <long long> ans;
long long now = 1;
int n;
int CAP;
const int K = 8;

void rec(int cur)
{
    if (cur == CAP)
    {
        ans.push_back(now);
    }
    else
    {
        if (now < brr[cur])
        {
            long long keep = now;
            now *= arr[cur];
            rec(cur);
            now = keep;
        }
        rec(cur + 1);
    }
}

long long mx(long long mid, long long cur)
{
    return mid / cur;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        brr[i] = (INF + arr[i]) / arr[i];
    }
    if (n <= K)
    {
        CAP = n;
        rec(0);
        sort(ans.begin(), ans.end());
        cout << ans[k - 1] << endl;
        return 0;
    }
    else
    {
        CAP = K;
        rec(0);
        vector <long long> ans2 = ans;
        ans.clear();
        CAP = n;
        rec(K);
        if (ans.size() > ans2.size())
        {
            ans2.swap(ans);
        }
        sort(ans.begin(), ans.end());
        sort(ans2.begin(), ans2.end());
        long long l = 0, r = 1e18 + 1;
        while (l + 1 < r)
        {
            long long mid = (l + r) / 2;
            long long cur = 0;
            for (int i = 0; i < ans.size(); i++)
            {
                long long m = mx(mid, ans[i]);
                auto it = upper_bound(ans2.begin(), ans2.end(), m);
                cur += it - ans2.begin();
            }
            if (cur < k)
                l = mid;
            else
                r = mid;
        }
        cout << r << endl;
    }
    return 0;
}