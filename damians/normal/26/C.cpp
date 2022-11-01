#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)REP(i,0,(int)(v)-1)
#define FORD(i,v)REPD(i,(int)(v)-1,0)
#define pb push_back
#define sz size
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
using namespace std;
int n,m,a,b,c;
char pr[205][205];

        

void parz()
{
    char lit[2][5]={"abcd","efgh"};
    FOR(i,n/2)
    {
        FOR(j,m/2)
        {
            if (c>0)
            {
                pr[2*i][2*j]=lit[i%2][j%4];
                pr[2*i][2*j+1]=lit[i%2][j%4];
                pr[2*i+1][2*j]=lit[i%2][j%4];
                pr[2*i+1][2*j+1]=lit[i%2][j%4];
                c--;
            }
            else if (a>0)
            {
                pr[2*i][2*j]=lit[i%2][j%4];
                pr[2*i][2*j+1]=lit[i%2][j%4];
                pr[2*i+1][2*j]=lit[i%2][(j+2)%4];
                pr[2*i+1][2*j+1]=lit[i%2][(j+2)%4];
                a-=2;
            }
            else if (b>0)
            {
                pr[2*i][2*j]=lit[i%2][j%4];
                pr[2*i][2*j+1]=lit[i%2][(j+2)%4];
                pr[2*i+1][2*j]=lit[i%2][j%4];
                pr[2*i+1][2*j+1]=lit[i%2][(j+2)%4];
                b-=2;
            }
            else
                cout<<"\n?????\n";
        }
    }
}

void sl()
{
    bool odwr=0;
    bool niep=0;
    if (m%2)
    {
        swap(a,b);
        swap(n,m);
        odwr=1;
    }
    if (n%2)
    {
        if (a<m/2)
        {
            cout<<"IMPOSSIBLE";
            return;
        }
        FOR(i,m)
        {
            if (i%4<2)
                pr[n-1][i]='p';
            else
                pr[n-1][i]='s';
        }
        a-=m/2;
        n-=1;
        niep=1;
    }
    a=(a/2)*2;
    b=(b/2)*2;
    if (2*a+2*b+4*c<n*m)
    {
        cout<<"IMPOSSIBLE";
        return;
    }
    parz();
    if (odwr)
    {
        FOR(i,m)
        {
            FOR(j,n+niep)
                cout<<pr[n+niep-j-1][m-i-1];
            cout<<endl;
        }
    }
    else
    {
        FOR(i,n+niep)
        {
            FOR(j,m)
                cout<<pr[n+niep-i-1][m-j-1];
            cout<<endl;
        }
    }
    
}

int main()
{
    cin>>n>>m>>a>>b>>c;
    if ((n*m)%2)
        cout<<"IMPOSSIBLE";
    else
        sl();
    return 0;
}