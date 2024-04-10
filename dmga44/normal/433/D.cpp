#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

int a[MAXN][MAXN];
/**
0 x-
1 x+
2 y-
3 y+
**/
int prec[MAXN][MAXN][4];
int len[MAXN];

int solve(int k,int n)
{
    if(!len[k])
        return 0;
    int l=k,r=k,res=len[k];
    for(int width=len[k];width>0;width--)
    {
        while(l && len[l-1]>=width)
            l--;
        while(r<n-1 && len[r+1]>=width)
            r++;
        res=max(res,width*(r-l+1));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,q;
    cin >> n >> m >> q;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(!a[i][j])
                prec[i][j][0]=0;
            else
            {
                if(!i)
                    prec[i][j][0]=1;
                else
                    prec[i][j][0]=prec[i-1][j][0]+1;
            }
        }
    for(int i=n-1;i>=0;i--)
        for(int j=0;j<m;j++)
        {
            if(!a[i][j])
                prec[i][j][1]=0;
            else
            {
                if(i==n-1)
                    prec[i][j][1]=1;
                else
                    prec[i][j][1]=prec[i+1][j][1]+1;
            }
        }

    for(int j=0;j<m;j++)
        for(int i=0;i<n;i++)
        {
            if(!a[i][j])
                prec[i][j][2]=0;
            else
            {
                if(!j)
                    prec[i][j][2]=1;
                else
                    prec[i][j][2]=prec[i][j-1][2]+1;
            }
        }
    for(int j=m-1;j>=0;j--)
        for(int i=0;i<n;i++)
        {
            if(!a[i][j])
                prec[i][j][3]=0;
            else
            {
                if(j==m-1)
                    prec[i][j][3]=1;
                else
                    prec[i][j][3]=prec[i][j+1][3]+1;
            }
        }

    while(q--)
    {
        int ty;
        cin >> ty;
        if(ty==1)
        {
            int x,y;
            cin >> x >> y;
            x--,y--;
            a[x][y]=1-a[x][y];
            ///0
            if(a[x][y])
            {
                if(!x)
                    prec[x][y][0]=1;
                else
                    prec[x][y][0]=1+prec[x-1][y][0];
            }
            else
                prec[x][y][0]=0;
            for(int i=x+1;i<n;i++)
            {
                if(!a[i][y])
                    prec[i][y][0]=0;
                else
                {
                    if(!i)
                        prec[i][y][0]=1;
                    else
                        prec[i][y][0]=prec[i-1][y][0]+1;
                }
            }

            ///1
            if(a[x][y])
            {
                if(x==n-1)
                    prec[x][y][1]=1;
                else
                    prec[x][y][1]=1+prec[x+1][y][1];
            }
            else
                prec[x][y][1]=0;
            for(int i=x-1;i>=0;i--)
            {
                if(!a[i][y])
                    prec[i][y][1]=0;
                else
                {
                    if(i==n-1)
                        prec[i][y][1]=1;
                    else
                        prec[i][y][1]=prec[i+1][y][1]+1;
                }
            }

            ///2
            if(a[x][y])
            {
                if(!y)
                    prec[x][y][2]=1;
                else
                    prec[x][y][2]=1+prec[x][y-1][2];
            }
            else
                prec[x][y][2]=0;
            for(int i=y+1;i<m;i++)
            {
                if(!a[x][i])
                    prec[x][i][2]=0;
                else
                {
                    if(!i)
                        prec[x][i][2]=1;
                    else
                        prec[x][i][2]=prec[x][i-1][2]+1;
                }
            }

            ///3
            if(a[x][y])
            {
                if(y==m-1)
                    prec[x][y][3]=1;
                else
                    prec[x][y][3]=1+prec[x][y+1][3];
            }
            else
                prec[x][y][3]=0;
            for(int i=y-1;i>=0;i--)
            {
                if(!a[x][i])
                    prec[x][i][3]=0;
                else
                {
                    if(i==m-1)
                        prec[x][i][3]=1;
                    else
                        prec[x][i][3]=prec[x][i+1][3]+1;
                }
            }
        }
        else
        {
            int x,y;
            cin >> x >> y;
            x--,y--;
            for(int i=0;i<m;i++)
                len[i]=prec[x][i][0];
            int res=solve(y,m);
            for(int i=0;i<m;i++)
                len[i]=prec[x][i][1];
            res=max(res,solve(y,m));

            for(int i=0;i<n;i++)
                len[i]=prec[i][y][2];
            res=max(res,solve(x,n));
            for(int i=0;i<n;i++)
                len[i]=prec[i][y][3];
            res=max(res,solve(x,n));
            db(res)
        }
    }

    return 0;
}
/**
3 4 5
0 1 1 0
1 0 0 1
0 1 1 0
2 2 2
2 1 2
1 2 2
1 2 3
2 2 2

3 3 4
1 1 1
1 1 1
1 1 1
2 2 2
1 2 2
2 1 1
2 2 1
**/