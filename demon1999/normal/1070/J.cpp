#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;

vector<bool> rukzak(vector<int> &v)
{
    int s = 0;
    for (int i: v)
        s += i;
    vector<bool> ans;
    for (int i = 0; i <= s; i++)
        ans.push_back(false);
    ans[0] = 1;
    for (int i: v)
        for (int j = s; j >= i; j--)
            ans[j] = (ans[j] | ans[j - i]);
    return ans;
}

vector<int> v(26);

ll solve()
{
    int n, m, t;
    string s;
    cin >> n >> m >> t >> s;
    fill(v.begin(), v.end(), 0);
    for (int i = 0; i < t; i++)
        v[s[i] - 'A']++;
    auto ans = rukzak(v);
    for (int i = n; i <= t - m; i++)
        if (ans[i])
            return 0;
    ll answer = (ll)t * t;
    for (int i = 0; i < 26; i++)
    {
        int x = v[i];
        swap(v[i], v[25]);
        v.pop_back();
        ans = rukzak(v);
        v.push_back(x);
        swap(v[i], v[25]);
        for (int j = max(0, n - x); j <= min(n, t - x); j++)
        {
            if (ans[j])
            {
                ll q = n - j;
                ll w = m - (t - x - j);
                assert(w >= 0);
                answer = min(answer, q * w);
            }
        }
    }
    return answer;
}

int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        cout << solve() << "\n";
    return 0;
}