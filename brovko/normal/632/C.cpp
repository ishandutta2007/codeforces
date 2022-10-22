#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n;
string s[50005];

bool comp(string i, string j)
{
    return (i + j < j + i);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> s[i];

    sort(s, s + n, comp);

    for(int i = 0; i < n; i++)
        cout << s[i];
}