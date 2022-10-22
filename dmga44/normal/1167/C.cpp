#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 1000005

vector<int> g[MAXN];
int d[MAXN],s[MAXN];

int f(int u)
{
    if(d[u]<0)
        return u;
    d[u]=f(d[u]);
    return d[u];
}

void join(int u,int v)
{
    u=f(u),v=f(v);
    if(u==v)
        return ;
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    s[u]+=s[v];
    d[v]=u;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n,m,x,y;
    cin >> n >> m;
    for(int i=0;i<n+m;i++)
        d[i]=-1;
    for(int i=m;i<n+m;i++)
        s[i]=1;
    for(int i=0;i<m;i++)
    {
        cin >> x;
        for(int j=0;j<x;j++)
        {
            cin >> y;
            y--;
            join(i,y+m);
        }
    }

    for(int i=m;i<n+m;i++)
        cout << s[f(i)] << ' ';

    return 0;
}