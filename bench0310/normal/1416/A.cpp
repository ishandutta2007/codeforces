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
        vector<int> v[n+1];
        for(int i=1;i<=n;i++) v[i].push_back(0);
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            v[a].push_back(i);
        }
        for(int i=1;i<=n;i++) v[i].push_back(n+1);
        vector<int> res(n+1,n+1);
        for(int i=1;i<=n;i++)
        {
            int m=0;
            for(int j=0;j<(int)v[i].size()-1;j++) m=max(m,v[i][j+1]-v[i][j]);
            if(m<=n) res[m]=min(res[m],i);
        }
        for(int i=1;i<=n;i++) res[i]=min(res[i],res[i-1]);
        for(int i=1;i<=n;i++) if(res[i]==n+1) res[i]=-1;
        for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    }
    return 0;
}