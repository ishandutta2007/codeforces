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
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 200005

int d[MAXN],f[MAXN][26];

int fin(int u)
{
    if(d[u]<0)
        return u;
    d[u]=fin(d[u]);
    return d[u];
}

void join(int u,int v)
{
    u=fin(u);
    v=fin(v);
    if(u==v)
        return ;
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        for(int i=0;i<n;i++)
        {
            d[i]=-1;
            for(int j=0;j<26;j++)
                f[i][j]=0;
        }
        for(int i=0;i<n/2;i++)
            join(i,n-1-i);
        for(int i=0;i+k<n;i++)
            join(i,i+k);

        for(int i=0;i<n;i++)
            f[fin(i)][s[i]-'a']++;
        int res=0;
        for(int i=0;i<n;i++)
        {
            int sum=0,ma=0;
            for(int j=0;j<26;j++)
            {
                sum+=f[i][j];
                ma=max(f[i][j],ma);
            }
            res+=(sum-ma);
        }
        db(res)
    }

    return 0;
}
/**
2
6 2
abaaba
6 3
abaaba
**/