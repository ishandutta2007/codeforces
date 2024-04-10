#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>
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
#define DBG2(v1,v2) cout<<(v1)<<" - "<<(v2)<<endl;
#define CZ(x) scanf("%d",&(x))
using namespace std;

ll nwd(ll a,ll b)
{
    return (a==0?b:nwd(b%a,a));
}

ll lcm[110][110],gcd[110][110];
vector<pair<int,int> > rozw;
int zrob[200];
int odw[200];
ll ile[200];
int n,m;

void dfs(int u, ll wal)
{
    odw[u]=1;
    zrob[u]=1;
    ile[u]=wal;
    FOR(i,n)
    {
        if (gcd[u][i]==0) continue;
        rozw.pb(mp(u,i));
        if (odw[i]) continue;
        dfs(i,max(1LL,gcd[u][i]*lcm[u][i]/wal));
    }
}

bool prob2(int u,ll wal)
{
    FOR(i,n) odw[i]=0;
    rozw.clear();
    dfs(u,wal);
    FOR(i,rozw.sz())
    {
        int x=rozw[i].fi,y=rozw[i].se;
        if (nwd(ile[x],ile[y])!=gcd[x][y]) return 0;
        if (ile[x]*ile[y]!=gcd[x][y]*lcm[x][y]) return 0;
    }
    return 1;
}

bool prob(int u)
{
    int z;
    for(z=0;z<n;z++) {if (gcd[z][u]>0) break;}
    if (z==n)
    {
        ile[u]=1;
        return 1;
    }
    ll M=lcm[z][u];
    for(int k=1;k*k<=M;k++)
    {
        if ((M%k)!=0) continue;
        if (prob2(u,k))
            return 1;
        if (prob2(u,M/k))
            return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    FOR(i,110) FOR(j,110) lcm[i][j]=gcd[i][j]=0;
    FOR(i,m)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--;b--;
        lcm[a][b]=d;
        lcm[b][a]=d;
        gcd[a][b]=c;
        gcd[b][a]=c;
    }
    int ok=1;
    FOR(i,n) zrob[i]=0;
    FOR(i,n)
    {
        if (zrob[i]) continue;
        if (prob(i)==0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;

        
        FOR(i,n) cout<<ile[i]<<" ";

    return 0;
}