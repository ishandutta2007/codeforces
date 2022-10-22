#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

string s;
int n;
ld ps[500005], ans;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.size();

    for(int i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + (ld)1 / i;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U' || s[i] == 'I' || s[i] == 'Y')
        {
            int a = i + 1, b = n - i;

            if(a > b)
                swap(a, b);

            ans += a + a * (ps[b] - ps[a]) + (n + 1) * (ps[n] - ps[b]) - (n - b);
        }
    }

    cout << setprecision(20) << ans;
}