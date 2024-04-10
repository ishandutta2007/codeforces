#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> s;
        n=s.size();
        int ans=0;
        int k0=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
                k0++;
            else
            {
                int x=0;
                for(int j=0;j<20;j++)
                    if(i+j<n)
                {
                    x=x*2+s[i+j]-'0';
                    if(j+k0+1>=x)
                        ans++;
                }
                k0=0;
            }
        }
        cout << ans << endl;
    }
}