#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using namespace std;

int t;
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
        int Max=-1;
        for(int i=0;i<s.size();i++)
            if(s[i]=='1')
                Max=i;
        int f=0;
        int ans=0;
        for(int i=0;i<Max;i++)
        {
            if(s[i]=='1')
                f=1;
            if(f==1 && s[i]=='0')
                ans++;
        }
        cout << ans << endl;
    }
}