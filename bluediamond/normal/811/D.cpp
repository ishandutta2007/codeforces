#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100+5;

int n,m;
int v[N][N];

int rf,cf;

char L='L',R='R'; bool LR=0;
char U='U',D='D'; bool UD=0;

int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};

bool valid(int r,int c)
{
    if(1<=r && r<=n && 1<=c && c<=m && v[r][c]==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int d[N][N];

void build()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            d[i][j]=-1;
        }
    }
    d[rf][cf]=0;
    queue<pair<int,int>>q;
    q.push({rf,cf});
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int k=0;k<4;k++)
        {
            int rn=r+dr[k];
            int cn=c+dc[k];
            if(valid(rn,cn) && d[rn][cn]==-1)
            {
                d[rn][cn]=1+d[r][c];
                q.push({rn,cn});
            }
        }
    }
}

int r;
int c;

void Move()
{
    if(r==rf && c==cf)
    {
        exit(0);
    }
    else
    {
        if(LR==0 && v[r][c-1]==0 && v[r][c+1]==0)
        {
            LR=1;
            cout<<L<<endl;
            int rn,cn;
            cin>>rn>>cn;
            if(c+1<=m)
            {
                if(cn==c+1)
                {
                    swap(L,R);
                }
            }
            else
            {
                if(cn==c)
                {
                    swap(L,R);
                }
            }
            r=rn; c=cn;
            return;
        }
       /// cout<<"\t\t\t"<<r<<" , "<<c<<" : "<<v[r-1][c]<<" "<<v[r+1][c]<<"\t\t\t"<<LR<<";"<<UD<<"\t\t"<<L<<" "<<R<<" "<<U<<" "<<D<<"\n";
        if(UD==0 && v[r-1][c]==0 && v[r+1][c]==0)
        {
            UD=1;
            cout<<U<<endl;
            int rn,cn;
            cin>>rn>>cn;
            if(r+1<=n)
            {
                if(rn==r+1)
                {
                    swap(U,D);
                }
            }
            else
            {
                if(rn==r)
                {
                    swap(U,D);
                }
            }
            r=rn; c=cn;
            return;
        }
        int x=d[r][c]-1;
        if(valid(r-1,c) && d[r-1][c]==x) cout<<U<<endl;
        else
        if(valid(r+1,c) && d[r+1][c]==x) cout<<D<<endl;
        else
        if(valid(r,c-1) && d[r][c-1]==x) cout<<L<<endl;
        else
        if(valid(r,c+1) && d[r][c+1]==x) cout<<R<<endl;
        cin>>r>>c;
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
        {
            if(s[j-1]=='*') v[i][j]=1;
            if(s[j-1]=='F') {rf=i; cf=j;}
        }
    }
    build();
    /**
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }
    **/
    r=c=1;
    while(1)
    {
        Move();
    }
    return 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
/**

2 2

4 3
...
**.
F*.
...

**/