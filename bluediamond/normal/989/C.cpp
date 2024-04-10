#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=50;

int a,b,c,d;

int n,jum;

int v[N+5][N+5];

int dr[]={-1,-1,0,1,1,1,0,-1};
int dc[]={0,1,1,1,0,-1,-1,-1};

bool valid(int i,int j)
{
    if(1<=i && 1<=j && i<=n && j<=n)
        return 1;
    return 0;
}

bool pot(int i,int j,int val)
{
    for(int k=0;k<8;k++)
    {
        int in=i+dr[k];
        int jn=j+dc[k];
        if(valid(in,jn)==1 && v[in][jn]==val)
            return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b>>c>>d;
    n=50;
    jum=n/2;
    for(int i=1;i<=jum;i++)
        for(int j=1;j<=jum;j++)
        {
            v[i][j]='A';
        }
    for(int i=1;i<=jum;i++)
        for(int j=jum+1;j<=n;j++)
        {
            v[i][j]='B';
        }
    for(int i=jum+1;i<=n;i++)
        for(int j=1;j<=jum;j++)
        {
            v[i][j]='C';
        }
    for(int i=jum+1;i<=n;i++)
        for(int j=jum+1;j<=n;j++)
        {
            v[i][j]='D';
        }
    a--;
    b--;
    c--;
    d--;
    for(int i=1;i<=jum;i++)
        for(int j=1;j<=jum;j++)
        {
            if(b==0)
                continue;
            if(pot(i,j,'B')==0)
                continue;
            v[i][j]='B';
            b--;
        }
    for(int i=1;i<=jum;i++)
        for(int j=jum+1;j<=n;j++)
        {
            if(a==0)
                continue;
            if(pot(i,j,'A')==0)
                continue;
            v[i][j]='A';
            a--;
        }
    for(int i=jum+1;i<=n;i++)
        for(int j=1;j<=jum;j++)
        {
            if(d==0)
                continue;
            if(pot(i,j,'D')==0)
                continue;
            v[i][j]='D';
            d--;
        }
    for(int i=jum+1;i<=n;i++)
        for(int j=jum+1;j<=n;j++)
        {
            if(c==0)
                continue;
            if(pot(i,j,'C')==0)
                continue;
            v[i][j]='C';
            c--;
        }
    cout<<n<<" "<<n<<"\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<char(v[i][j]);
        }
        cout<<"\n";
    }
    return 0;
}
/**

100
100
100
100

**/