#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100+5;

int n;
int m;
int v[N][N];
int a[N][N];

int _r[N],_c[N];

int tota=0;
int totb=0;

void print(string a,int p,int cnt)
{
    for(int i=1;i<=cnt;i++)
    {
        cout<<a<<" "<<p<<"\n";
    }
}


void f(int ord)
{
    for(int i=0;i<N;i++) _r[i]=0, _c[i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            v[i][j]=a[i][j];
        }
    }
    if(ord==0)
    {
    for(int r=1;r<=n;r++)
    {
        int mi=(1<<30);
        for(int c=1;c<=m;c++)
        {
            mi=min(mi,v[r][c]);
        }
        for(int c=1;c<=m;c++)
        {
            v[r][c]-=mi;
        }
        _r[r]=mi;
        tota+=mi;
    }
    for(int c=1;c<=m;c++)
    {
        int mi=(1<<30);
        for(int r=1;r<=n;r++)
        {
            mi=min(mi,v[r][c]);
        }
        for(int r=1;r<=n;r++)
        {
            v[r][c]-=mi;
            if(v[r][c])
            {
                tota=(1<<30);
                return;
            }
        }
        _c[c]=mi;
        tota+=mi;
    }
    }
    else
    {
    for(int c=1;c<=m;c++)
    {
        int mi=(1<<30);
        for(int r=1;r<=n;r++)
        {
            mi=min(mi,v[r][c]);
        }
        for(int r=1;r<=n;r++)
        {
            v[r][c]-=mi;
        }
        _c[c]=mi;
        totb+=mi;
    }
    for(int r=1;r<=n;r++)
    {
        int mi=(1<<30);
        for(int c=1;c<=m;c++)
        {
            mi=min(mi,v[r][c]);
        }
        for(int c=1;c<=m;c++)
        {
            v[r][c]-=mi;
            if(v[r][c])
            {
                totb=(1<<30);
                return;
            }
        }
        _r[r]=mi;
        totb+=mi;
    }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
  ///  cout<<tota<<"\n";
    f(0);
    f(1);
    if(min(tota,totb)==(1<<30))
    {
        cout<<"-1\n";
        return 0;
    }
    cout<<min(tota,totb)<<"\n";
    if(tota<totb) f(0);
    else f(1);
    for(int i=1;i<=n;i++)
    {
        print("row",i,_r[i]);
    }
    for(int i=1;i<=m;i++)
    {
        print("col",i,_c[i]);
    }
    return 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
/**

v[1][1] = r[1] + c[1] ; v[1][2] = r[1] + c[2] ... v[1][m] = r[1] + c[m]
...
v[n][1] = r[n] + c[1] ; v[n][2] = r[n] + c[2] ... v[n][m] = r[n] + c[m]

**/