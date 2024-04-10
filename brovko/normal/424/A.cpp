#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    int k = 0;

    for(auto x:s)
        k += (x == 'X');

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'x' && k < n / 2)
        {
            k++;
            ans++;
            s[i] = 'X';
        }

        if(s[i] == 'X' && k > n / 2)
        {
            k--;
            ans++;
            s[i] = 'x';
        }
    }

    cout << ans << "\n" << s;
}