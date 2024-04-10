#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

int t, n, x;
string s;

int32_t main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> x >> s;
        int ans=0;
        int k=0;
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
                k++;
            else k--;
            if(k==x)
                f++;
        }
        if(x==0)
            f++;
        if(k==0 && f)
            cout << -1 << endl;
        else
        if(k==0)
            cout << 0 << endl;
        else
        {
            int p=0;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='0')
                    p++;
                else p--;
                if((x-p)%k==0 && ((x-p)/k>=0))
                    ans++;
            }
            p=0;
            if(x==0)
               ans++;
            cout << ans << endl;
        }
    }
}