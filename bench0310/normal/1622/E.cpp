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
        vector<ll> x(n,0);
        for(int i=0;i<n;i++) cin >> x[i];
        vector<string> s(n);
        for(int i=0;i<n;i++) cin >> s[i];
        pair<ll,vector<int>> res={-1,{}};
        vector<int> c[2*n+1];
        for(int p=0;p<(1<<n);p++)
        {
            ll now=0;
            vector<int> k(m,0);
            for(int i=0;i<n;i++)
            {
                int b=1-2*((p>>i)&1);
                now-=(b*x[i]);
                for(int j=0;j<m;j++) if(s[i][j]=='1') k[j]+=b;
            }
            for(int j=0;j<m;j++) c[k[j]+n].push_back(j);
            int a=1;
            vector<int> opt(m,0);
            for(int i=-n;i<=n;i++)
            {
                for(int b:c[i+n])
                {
                    now+=(i*a);
                    opt[b]=a++;
                }
                c[i+n].clear();
            }
            res=max(res,{now,opt});
        }
        for(int i=0;i<m;i++) cout << res.second[i] << " \n"[i==m-1];
    }
    return 0;
}