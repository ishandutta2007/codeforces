#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 300005

map<pii,bool> g;
int p[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie();

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> p[i];
    while(m--)
    {
        int u,v;
        cin >> u >> v;
        g[pii(u,v)]=1;
    }

    vector<int> v;
    v.push_back(p[n-1]);
    int res=0;
    for(int i=n-1;i>=0;i--)
    {
        int u=p[i],ok=1;
        for(int j=0;j<v.size() && ok;j++)
            ok&=g[pii(u,v[j])];
        if(ok)
            res++;
        else
            v.push_back(p[i]);
    }
    db(res)

    return 0;
}