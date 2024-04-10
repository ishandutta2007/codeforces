#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        string s(n+1,'1');
        string t;
        cin >> t;
        t="$"+t;
        ll res=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j+=i)
            {
                if(t[j]=='0')
                {
                    if(s[j]=='1')
                    {
                        s[j]='0';
                        res+=i;
                    }
                }
                else break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}