#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, x;
string s;

int f(char c)
{
    return (1ll << (c - 'a'));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> s;

    x -= f(s[n - 1]);

    if(n > 1)
        x += f(s[n - 2]);

    vector <char> v;

    for(int i = 0; i < n - 2; i++)
        v.push_back(s[i]);

    sort(v.rbegin(), v.rend());

    for(auto to:v)
    {
        if(x > 0)
            x -= f(to);
        else x += f(to);
    }

    if(x == 0)
        cout << "Yes";
    else cout << "No";
}