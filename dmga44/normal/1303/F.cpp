#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 305
#define MAXQ 2000005

int abi[MAXQ];
int a[MAXN][MAXN],d[MAXN][MAXN],b[MAXN][MAXN];
vector<pip> ups[MAXQ],ps[MAXQ];

void update(int p,int v)
{
    while(p<MAXQ)
    {
        abi[p]+=v;
        p+=(p&-p);
    }
}

int query(int p)
{
    int res=0;
    while(p)
    {
        res+=abi[p];
        p-=(p&-p);
    }
    return res;
}

int fin(int i,int j)
{
    if(d[i][j]<0)
        return i*MAXN+j;
    d[i][j]=fin(d[i][j]/MAXN,d[i][j]%MAXN);
    return d[i][j];
}

int join(int i1,int j1,int i2,int j2)
{
    int u=fin(i1,j1);
    int v=fin(i2,j2);
    if(u==v)
        return 0;
    int ux=u/305;
    int uy=u%305;
    int vx=v/305;
    int vy=v%305;
    if(d[ux][uy]>d[vx][vy])
    {
        swap(ux,vx);
        swap(uy,vy);
        swap(u,v);
    }
    d[ux][uy]+=d[vx][vy];
    d[vx][vy]=u;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,q,x,y,c;
    cin >> n >> m >> q;
//    db(q)
    for(int i=1;i<=q;i++)
    {
        cin >> x >> y >> c;
        x--,y--;
        ps[c].push_back(pip(i,pii(x,y)));
        if(c!=b[x][y])
            ups[b[x][y]].push_back(pip(i,pii(x,y)));
        b[x][y]=c;
    }

//    db("xxx")
    for(int c=0;c<=max(1000,((int)2e6/(n*m))+1);c++)
    {
//        db(c)
        int cc=0,lastp=0;
        if(c)
        {
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                {
                    a[i][j]=0;
                    d[i][j]=-1;
                }

            for(auto y : ps[c])
            {
                int p=y.first;
                int i=y.second.first;
                int j=y.second.second;
                if(a[i][j]!=c)
                {
                    cc++;
                    a[i][j]=c;
                    if(i && a[i-1][j]==c)
                        cc-=join(i,j,i-1,j);
                    if(j && a[i][j-1]==c)
                        cc-=join(i,j,i,j-1);
                    if(i<n-1 && a[i+1][j]==c)
                        cc-=join(i,j,i+1,j);
                    if(j<m-1 && a[i][j+1]==c)
                        cc-=join(i,j,i,j+1);
                }

                update(p,cc);
                update(p+1,-cc);
                lastp=p;
            }
        }

        cc=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                a[i][j]=b[i][j];
                d[i][j]=-1;
                if(a[i][j]==c)
                {
                    cc++;
                    if(i && a[i-1][j]==c)
                        cc-=join(i,j,i-1,j);
                    if(j && a[i][j-1]==c)
                        cc-=join(i,j,i,j-1);
                }
            }

        reverse(all(ups[c]));

        int lastu=q;
        for(auto y : ups[c])
        {
            int p=y.first;
            int i=y.second.first;
            int j=y.second.second;

            update(p,cc);
            update(lastu+1,-cc);
            lastu=p-1;
            if(a[i][j]!=c)
            {
                cc++;
                a[i][j]=c;
                if(i && a[i-1][j]==c)
                    cc-=join(i,j,i-1,j);
                if(j && a[i][j-1]==c)
                    cc-=join(i,j,i,j-1);
                if(i<n-1 && a[i+1][j]==c)
                    cc-=join(i,j,i+1,j);
                if(j<m-1 && a[i][j+1]==c)
                    cc-=join(i,j,i,j+1);
            }
        }

        update(lastp+1,cc);
        update(lastu+1,-cc);
    }

    for(int i=1;i<=q;i++)
        db(query(i))

    return 0;
}
/**
3 2 10
2 1 1
1 2 1
2 2 1
1 1 2
3 1 2
1 2 2
2 2 2
2 1 2
3 2 4
2 1 5
**/