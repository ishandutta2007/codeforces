#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin >> s[i];
    auto in=[&](int r,int c)->bool{return (0<=r&&r<n&&0<=c&&c<m);};
    vector<array<int,2>> z={{1,0},{-1,0},{0,-1},{0,1}};
    vector one(n,vector(m,bool(0)));
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<m-1;j++)
        {
            if(s[i][j]!='X') continue;
            int c=0;
            for(auto [di,dj]:z) c+=(s[i+di][j+dj]=='.');
            if(c==4)
            {
                s[i][j]='.';
                one[i][j]=1;
            }
        }
    }
    vector id(n,vector(m,int(0)));
    int cc=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='X'||id[i][j]!=0) continue;
            cc++;
            function<void(int,int)> dfs=[&](int r,int c)
            {
                id[r][c]=cc;
                for(auto [dr,dc]:z)
                {
                    int nr=r+dr;
                    int nc=c+dc;
                    if(in(nr,nc)&&s[nr][nc]=='.'&&id[nr][nc]==0) dfs(nr,nc);
                }
            };
            dfs(i,j);
        }
    }
    vector<int> v[cc+1];
    bool ok=1;
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<m-1;j++)
        {
            if(s[i][j]=='.') continue;
            vector<array<int,3>> t;
            for(auto [di,dj]:z)
            {
                int ni=i+di;
                int nj=j+dj;
                if(s[ni][nj]=='.') t.push_back({id[ni][nj],di,dj});
            }
            ok&=((t.size()%2)==0);
            if(t.size()==2)
            {
                auto [a,ai,aj]=t[0];
                auto [b,bi,bj]=t[1];
                if(ai==bi||aj==bj)
                {
                    v[a].push_back(b);
                    v[b].push_back(a);
                }
            }
        }
    }
    if(ok)
    {
        vector<int> c(cc+1,-1);
        function<void(int)> dfs=[&](int a)
        {
            for(int to:v[a])
            {
                if(c[to]==-1)
                {
                    c[to]=(c[a]^1);
                    dfs(to);
                }
            }
        };
        for(int i=1;i<=cc;i++)
        {
            if(c[i]==-1)
            {
                c[i]=0;
                dfs(i);
            }
        }
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(one[i][j]) s[i][j]='X';
        vector res(n,vector(m,int(0)));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='.') res[i][j]=((((j+c[id[i][j]])%2)==0)?1:4);
            }
        }
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(s[i][j]=='.') continue;
                for(auto [di,dj]:z)
                {
                    int ni=i+di;
                    int nj=j+dj;
                    if(s[ni][nj]=='.') res[i][j]+=res[ni][nj];
                }
            }
        }
        cout << "YES\n";
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cout << res[i][j] << " \n"[j==m-1];
    }
    else cout << "NO\n";
    return 0;
}