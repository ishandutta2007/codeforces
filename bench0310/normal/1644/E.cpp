#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll r=1,c=1;
        string s;
        cin >> s;
        for(char a:s)
        {
            r+=(a=='D');
            c+=(a=='R');
        }
        if(r==1||c==1) cout << n << "\n";
        else
        {
            ll tr=0,tc=0;
            for(char a:s)
            {
                if(a!=s[0])
                {
                    ll res=tr+tc;
                    res+=(n*(n-tr-tc));
                    res-=((r-tr)*(c-tc)-(1+r-tr-1+c-tc-1));
                    cout << res << "\n";
                    break;
                }
                tr+=(a=='D');
                tc+=(a=='R');
            }
        }
    }
    return 0;
}