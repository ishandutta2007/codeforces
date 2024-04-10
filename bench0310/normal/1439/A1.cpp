#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> d((1<<4),-1);
    vector<int> p((1<<4),-1);
    vector<int> mask={0,14,13,11,7};
    d[0]=0;
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(int i=1;i<=4;i++)
        {
            int na=(a^mask[i]);
            if(d[na]==-1)
            {
                q.push(na);
                d[na]=d[a]+1;
                p[na]=i;
            }
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<int>> v(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            string s;
            cin >> s;
            for(int j=1;j<=m;j++) v[i][j]=(s[j-1]-'0');
        }
        vector<array<int,2>> ops;
        auto add=[&](int r,int c,int a)
        {
            vector<array<int,2>> x(4);
            for(int i=0;i<4;i++) x[i]={r+((i&2)>0),c+(i&1)};
            for(int i=0;i<4;i++)
            {
                if(i!=a-1)
                {
                    ops.push_back(x[i]);
                    v[x[i][0]][x[i][1]]^=1;
                }
            }
        };
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(v[i][j]==0&&v[i][j+1]==0) continue;
                else if(v[i][j]==0) add(i,j,1);
                else if(v[i][j+1]==0) add(i,j,2);
                else add(i,j,3);
            }
        }
        int i=n-1;
        for(int j=1;j<m-1;j++)
        {
            if(v[i][j]==0&&v[i+1][j]==0) continue;
            else if(v[i][j]==0) add(i,j,1);
            else if(v[i+1][j]==0) add(i,j,3);
            else add(i,j,2);
        }
        int j=m-1;
        while(1)
        {
            int a=(v[i][j]+2*v[i][j+1]+4*v[i+1][j]+8*v[i+1][j+1]);
            if(a==0) break;
            add(i,j,p[a]);
        }
        cout << ops.size()/3 << "\n";
        for(int k=0;k<(int)ops.size();k+=3)
        {
            for(int a=k;a<k+3;a++) for(int b:ops[a]) cout << b << " ";
            cout << "\n";
        }
    }
    return 0;
}