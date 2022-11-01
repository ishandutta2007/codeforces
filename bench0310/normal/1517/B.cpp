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
        vector<vector<int>> b(n+1,vector<int>(m+1,0));
        vector<array<int,3>> v;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin >> b[i][j];
                v.push_back({b[i][j],i,j});
            }
        }
        sort(v.begin(),v.end());
        vector<int> x[n+1];
        for(int i=0;i<m;i++) x[v[i][1]].push_back(v[i][2]);
        int now=1;
        for(int i=1;i<=n;i++)
        {
            vector<bool> in(m+1,0);
            for(int y:x[i]) in[y]=1;
            vector<int> a[2];
            for(int j=1;j<=m;j++) a[in[j]].push_back(b[i][j]);
            array<int,2> idx={0,0};
            int sz=x[i].size();
            for(int j=1;j<=m;j++)
            {
                bool z=(now<=j&&j<now+sz);
                b[i][j]=a[z][idx[z]++];
            }
            now+=sz;
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cout << b[i][j] << " \n"[j==m];
    }
    return 0;
}