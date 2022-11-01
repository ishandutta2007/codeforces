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
        string s;
        int x;
        cin >> s >> x;
        int n=s.size();
        s="$"+s;
        string w(n+1,'1');
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='1'&&i-x<1&&i+x>n) ok=0;
            if(s[i]=='0')
            {
                if(i-x>=1) w[i-x]='0';
                if(i+x<=n) w[i+x]='0';
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='1'&&(!(i-x>=1&&w[i-x]=='1'))&&(!(i+x<=n&&w[i+x]=='1'))) ok=0;
        }
        if(ok) cout << w.substr(1,n) << "\n";
        else cout << "-1\n";
    }
    return 0;
}