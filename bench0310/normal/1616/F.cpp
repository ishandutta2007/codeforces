#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast","unroll-loops")
#pragma GCC target ("avx2")

using namespace std;
typedef long long ll;

const int mod=3;

int add(int a,int b){return (((a+b)%mod)+mod)%mod;}
int sub(int a,int b){return (((a-b)%mod)+mod)%mod;}
int mul(int a,int b){return (((a*b)%mod)+mod)%mod;}

bool gauss(vector<vector<int>> a,vector<int> &res)
{
    int n=a.size();
    if(n==0) return 1;
    int m=(int)a[0].size()-1;
    vector<int> where(m,-1);
    for(int c=0,r=0;c<m&&r<n;c++)
    {
        int p=-1;
        for(int i=r;i<n;i++) if(a[i][c]!=0) p=i;
        if(p==-1) continue;
        swap(a[r],a[p]);
        where[c]=r;
        int x=a[r][c];
        for(int j=0;j<=m;j++) a[r][j]=mul(a[r][j],x);
        for(int i=0;i<n;i++)
        {
            if(i==r) continue;
            int y=a[i][c];
            for(int j=c;j<=m;j++) a[i][j]=sub(a[i][j],mul(a[r][j],y));
        }
        r++;
    }
    res.assign(m,0);
    for(int i=0;i<m;i++) if(where[i]!=-1) res[i]=a[where[i]][m];
    for(int i=0;i<n;i++)
    {
        int s=0;
        for(int j=0;j<m;j++) s=add(s,mul(a[i][j],res[j]));
        if(s!=a[i][m]) return 0;
    }
    return 1;
}

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
        vector e(n+1,vector(n+1,int(0)));
        vector<int> c(m+1,0);
        for(int i=1;i<=m;i++)
        {
            int a,b,x;
            cin >> a >> b >> x;
            if(x==3) x=0;
            e[a][b]=e[b][a]=i;
            c[i]=x;
        }
        vector<vector<int>> a;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    if(e[i][j]&&e[j][k]&&e[i][k])
                    {
                        int s=0;
                        vector<int> x(m+1,0);
                        for(int b:{e[i][j],e[j][k],e[i][k]})
                        {
                            if(c[b]==-1) x[b-1]=1;
                            else s=sub(s,c[b]);
                        }
                        x[m]=s;
                        a.push_back(x);
                    }
                }
            }
        }
        vector<int> res(m);
        if(gauss(a,res))
        {
            for(int i=0;i<m;i++)
            {
                int d=c[i+1];
                if(c[i+1]==-1) d=res[i];
                if(d==0) d=3;
                cout << d << " \n"[i==m-1];
            }
        }
        else cout << "-1\n";
    }
    return 0;
}