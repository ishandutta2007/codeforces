#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define fi first
#define se second
 
int nod1(int a, int b)
{
    return a ? nod1(b % a, a) : b;
}
 
int nod(int a, int b)
{
    if (a > b)
        swap(a, b);
    return nod1(a, b);
}
 
int nok(int a, int b)
{
    return a / nod(a, b) * b;
}
 
ll sum(vector<int> v)
{
    ll ans = 0;
    for (int i = 0; i < v.size(); i++)
        ans += v[i];
    return ans;
}
 
bool letter(char c)
{
    return 'a' <= c && c <= 'z';
}
 
bool LETTER(char c)
{
    return 'A' <= c && c <= 'Z';
}
 
 
 
 
ll strToInt(string s)
{
    ll ans = 0;
    for (int i = 0; i < s.size(); i++)
        ans = 10 * ans + (s[i] - '0');
    return ans;
}
 
bool digit(char c)
{
    return '0' <= c && c <= '9';
}
 
bool prime(int n)
{
    if (n == 1)
        return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
 

const ll null = 0;
const ll INF = 1e18;
const ll MOD = 1000000007;

const int MAXN = 200005;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
 
vector<ll> a(26), b(26, 0), c, used;
 
ll dp[1004];
 
int main()
{
   
    int n;
    string s;
    cin >> n >> s;
    used.assign(n, 0);
    for (int i = 0; i < 26; i++)
        cin >> a[i];
    bool ok = true;
    ll longest = 0, minn = 1e9;
    for (ll i = 0; i < n; i++)
    {
        minn = min(minn, (ll)(a[s[i] - 'a']));
        if (minn < i + 1)
            ok = false;
        if (ok)
        {
            dp[i] = 1;
            used[i] = 1;
            longest = max(longest, i + 1);
        }
        bool ok1 = true;
        ll minn1 = 1e9;
        for (ll j = i; j > 0; j--)
        {
            minn1 = min(minn1, a[s[j] - 'a']);
            if (minn1 < i - j + 1)
                ok1 = false;
            if (ok1)
            {
                dp[i] = (dp[i] + dp[j - 1]) % MOD;
                if (used[j - 1])
                    longest = max(longest, i - j + 1), used[i] = 1;
            }
        }
    }
    cout << dp[n - 1] << " " << longest << " ";
    ll ans = 0;
    ll i = 0;
    while (i < n)
    {
        ans++;
        ll minn = 1e9;
        ll last = i;
        while (i < n)
        {
            minn = min(minn, a[s[i] - 'a']);
            if (minn < i - last + 1)
                break;
            i++;
        }
    }
    cout << ans;
    return 0;
}