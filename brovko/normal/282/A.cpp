#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int x = 0;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if(s[1] == '+')
            x++;
        else x--;
    }

    cout << x;
}