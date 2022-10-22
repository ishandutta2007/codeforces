#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int k[30];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;

    for(int i = 0; i < 2 * n - 2; i += 2)
    {
        k[s[i] - 'a']++;

        if(k[s[i + 1] - 'A'] == 0)
            ans++;
        else k[s[i + 1] - 'A']--;
    }

    cout << ans;
}