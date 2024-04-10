#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    ld d=0;
    for(int i=0;i<n;i++)
    {
        ld x=s[i]-'0';
        if(s[i]=='?')
            x=4.5;
        if(i>=n/2)
            x=-x;
        d+=x;
    }
    if(d==0)
        cout << "Bicarp";
    else cout << "Monocarp";
}