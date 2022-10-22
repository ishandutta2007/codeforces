#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n = s.size();

    int x = -1;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '.')
            x = i;
    }

    if(x == -1)
    {
        x = n;
        s += ".";
        n++;
    }

    int l = 0;
    int r = n - 1;

    while(s[l] == '0' || s[l] == '.')
        l++;

    while(s[r] == '0' || s[r] == '.')
        r--;

    int k = 0;

    for(int i = l; i <= r; i++)
        if(s[i] != '.')
            k++;

    if(k == 1)
    {
        cout << s[l];

        if(x - l > 1)
            cout << 'E' << x - l - 1;

        if(x - l < 1)
            cout << 'E' << x - l;

        return 0;
    }

    cout << s[l] << '.';

    for(int i = l + 1; i <= r; i++)
        if(s[i] != '.')
            cout << s[i];

    if(x - l > 1)
        cout << 'E' << x - l - 1;

    if(x - l < 1)
        cout << 'E' << x - l;
}