#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, k;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    cin >> s;

    int ans = 0;

    int j = -1, a = 0, b = 0;

    for(int i = 0; i < n; i++)
    {
        while(j < n && min(a, b) <= k)
        {
            j++;

            if(s[j] == 'a')
                a++;
            else b++;
        }

        ans = max(ans, j - i);
        
        if(s[i] == 'a')
            a--;
        else b--;
    }

    cout << ans;
}