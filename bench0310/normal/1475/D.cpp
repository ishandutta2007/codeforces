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
        ll m;
        cin >> n >> m;
        vector<ll> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<ll> v[3];
        for(int i=1;i<=n;i++)
        {
            int b;
            cin >> b;
            v[b].push_back(a[i]);
        }
        for(int i=1;i<=2;i++) sort(v[i].begin(),v[i].end(),greater<ll>());
        vector<vector<ll>> sum(3,vector<ll>(n+1,0));
        int one=v[1].size();
        int two=v[2].size();
        for(int j=1;j<=one;j++) sum[1][j]=v[1][j-1]+sum[1][j-1];
        for(int j=1;j<=two;j++) sum[2][j]=v[2][j-1]+sum[2][j-1];
        int res=2*n+1;
        int idx=0;
        for(int i=one;i>=0;i--)
        {
            while(idx<two&&sum[1][i]+sum[2][idx]<m) idx++;
            if(sum[1][i]+sum[2][idx]<m) break;
            res=min(res,i+2*idx);
        }
        if(res==2*n+1) res=-1;
        cout << res << "\n";
    }
    return 0;
}