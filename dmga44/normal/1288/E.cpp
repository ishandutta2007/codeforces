#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
#define mod (ll)(1e9+7)
#define MAXN 1000005

int abi[MAXN],id[MAXN],res[MAXN][2];

void update(int p,int v)
{
    while(p<MAXN)
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        res[i][0]=res[i][1]=i+1;
        id[i]=n-i;
        update(id[i],1);
    }

    for(int i=0;i<m;i++)
    {
        int x;
        cin >> x;
        x--;
        int pos=n+1-query(id[x]);
        res[x][0]=1;
        res[x][1]=max(pos,res[x][1]);
        update(id[x],-1);
        id[x]=n+i+1;
        update(id[x],1);
    }

    for(int i=0;i<n;i++)
    {
        int pos=n+1-query(id[i]);
        res[i][1]=max(pos,res[i][1]);
        cout << res[i][0] << ' ' << res[i][1] << '\n';
    }

    return 0;
}