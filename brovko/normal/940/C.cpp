#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, used[128], Max, Min;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    cin >> s;

    Max = 0;
    Min = 128;

    for(auto to:s)
    {
        used[to] = 1;
        Max = max(Max, (int)to);
        Min = min(Min, (int)to);
    }

    if(n < k)
    {
        for(int i = 0; i < k; i++)
        {
            if(i < n)
                cout << s[i];
            else cout << (char)Min;
        }
        return 0;
    }

    int j = k - 1;
    while(s[j] == Max)
        j--;

    int c = s[j] + 1;
    while(used[c] == 0)
        c++;

    for(int i = 0; i < k; i++)
    {
        if(i < j)
            cout << s[i];
        else if(i == j)
            cout << (char)c;
        else cout << (char)Min;
    }
}