#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<int> v[N];
vector<ll> p(N,0);
vector<ll> h(N,0);
vector<ll> c(N,0);
bool ok=1;

void dfs0(int a,int par=-1)
{
    c[a]=p[a];
    for(int to:v[a])
    {
        if(to==par) continue;
        dfs0(to,a);
        c[a]+=c[to];
    }
}

ll dfs1(int a,int par=-1)
{
    if(abs(h[a])>c[a]) ok=0;
    if((c[a]+h[a])&1) ok=0;
    ll x=c[a]-((c[a]+h[a])/2);
    ll sum=0;
    for(int to:v[a])
    {
        if(to==par) continue;
        sum+=dfs1(to,a);
    }
    if(x-p[a]>sum) ok=0;
    return x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        ok=1;
        for(int i=1;i<=n;i++) p[i]=h[i]=c[i]=0;
        for(int i=1;i<=n;i++) cin >> p[i];
        for(int i=1;i<=n;i++) cin >> h[i];
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs0(1);
        dfs1(1);
        if(ok==1) cout << "YES\n";
        else cout << "NO\n";
        for(int i=1;i<=n;i++) v[i].clear();
    }
    return 0;
}