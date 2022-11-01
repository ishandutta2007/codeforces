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
        int n,m;
        cin >> n >> m;
        string s;
        cin >> s;
        s="$"+s;
        vector<int> lmn(n+1,0);
        vector<int> lmx(n+1,0);
        vector<int> sum(n+1,0);
        for(int i=1;i<=n;i++)
        {
            sum[i]=sum[i-1]+(s[i]=='+'?1:-1);
            lmn[i]=min(lmn[i-1],sum[i]);
            lmx[i]=max(lmx[i-1],sum[i]);
        }
        vector<int> rmn(n+2,0);
        vector<int> rmx(n+2,0);
        for(int i=n;i>=1;i--)
        {
            int x=(s[i]=='+'?1:-1);
            rmn[i]=min(rmn[i+1]+x,0);
            rmx[i]=max(rmx[i+1]+x,0);
        }
        while(m--)
        {
            int l,r;
            cin >> l >> r;
            int mn=min(lmn[l-1],sum[l-1]+rmn[r+1]);
            int mx=max(lmx[l-1],sum[l-1]+rmx[r+1]);
            cout << mx-mn+1 << "\n";
        }
    }
    return 0;
}