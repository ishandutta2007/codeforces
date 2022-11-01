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
        int n;
        cin >> n;
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++) cin >> p[i];
        vector s(n+1,vector(n+1,int(0)));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                s[i][j]=(s[i][j-1]+(p[j]<p[i]));
            }
        }
        ll res=0;
        for(int i=1;i<=n;i++)
        {
            ll c=0;
            for(int j=i+1;j<=n;j++)
            {
                if(p[i]>p[j]) res+=c;
                c+=s[j][i-1];
            }
        }
        cout << res << "\n";
    }
    return 0;
}