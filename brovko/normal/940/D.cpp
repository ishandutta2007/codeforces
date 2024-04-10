#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> s;

    int Min = -1e9;
    int Max = 1e9;

    for(int i = 4; i < n; i++)
    {
        if(s[i] == '1' && s[i - 1] == '0')
            {
                for(int j = i - 4; j <= i; j++)
                    Min = max(Min, a[j] + 1);
            }
        else if(s[i] == '0' && s[i - 1] == '1')
        {
            for(int j = i - 4; j <= i; j++)
                Max = min(Max, a[j] - 1);
        }
    }

    cout << Min << ' ' << Max;
}