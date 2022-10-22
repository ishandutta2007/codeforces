#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, ps[100005], l[200005];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
                ps[i + 1] = ps[i] - 1;
            else ps[i + 1] = ps[i] + 1;
        }

    int N = 100003;

    for(int i = 0; i < 200005; i++)
        l[i] = 1e9;

    int Max = 0;

    /*for(int i = 0; i <= n; i++)
        cout << ps[i] << ' ';
    cout << endl;*/

    for(int i = 0; i <= n; i++)
    {
        if(l[ps[i] + N] == 1e9)
            l[ps[i] + N] = i;

        Max = max(Max, i - l[ps[i] + N]);
    }

    cout << Max;
}