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
        int n,k,m;
        cin >> n >> k >> m;
        vector<bool> vis(n+1,0);
        for(int i=0;i<m;i++)
        {
            int a;
            cin >> a;
            vis[a]=1;
        }
        vector<int> v;
        int l=1;
        while(l<=n)
        {
            while(l<=n&&vis[l]==1) l++;
            if(l==n+1) break;
            int r=l;
            while(r+1<=n&&vis[r+1]==0) r++;
            v.push_back(r-l+1);
            l=r+1;
        }
        bool ok=0;
        int c=(k-1)/2;
        auto solve=[&](int a,int b)
        {
            if((n-m)%(k-1)) return;
            ok|=(a>=c&&b>=c);
        };
        int one=0;
        int two=n-m;
        solve(one,two);
        for(int a:v)
        {
            one+=a;
            two-=a;
            solve(one,two);
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}