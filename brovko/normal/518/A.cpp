#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

string s, t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    int n = s.size();

    int x = n - 1;

    while(s[x] == 'z')
    {
        s[x] = 'a';
        x--;
    }

    s[x]++;

    if(s == t)
        cout << "No such string";
    else cout << s;
}