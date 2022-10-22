#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string s, t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    for(int i=0; i<s.size(); i++)
    {
        if(i == 0 || s[i] < t[0])
            cout << s[i];
        else break;
    }
    cout << t[0];
}