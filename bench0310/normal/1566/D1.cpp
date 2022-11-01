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
        vector<array<int,2>> v(n*m);
        for(int i=0;i<n*m;i++)
        {
            int a;
            cin >> a;
            v[i]={a,i};
        }
        sort(v.begin(),v.end());
        int l=0;
        vector<int> s(n*m,-1);
        while(l<n*m)
        {
            int r=l;
            while(r+1<n*m&&v[r+1][0]==v[l][0]) r++;
            if(l/m==r/m)
            {
                for(int i=l;i<=r;i++) s[v[i][1]]=r-(i-l);
            }
            else
            {
                int x=(l/m)*m+m-1;
                int idx=l;
                while(x>=l) s[v[idx++][1]]=x--;
                for(int row=(l/m)+1;row<=(r/m)-1;row++)
                {
                    x=row*m;
                    int y=x+m-1;
                    while(y>=x) s[v[idx++][1]]=y--;
                }
                int y=r;
                x=(r/m)*m;
                while(y>=x) s[v[idx++][1]]=y--;
            }
            l=r+1;
        }
        vector vis(n,vector(m,int(0)));
        int res=0;
        for(int p:s)
        {
            int r=p/m;
            int c=p%m;
            for(int i=0;i<c;i++) res+=vis[r][i];
            vis[r][c]=1;
        }
        cout << res << "\n";
    }
    return 0;
}