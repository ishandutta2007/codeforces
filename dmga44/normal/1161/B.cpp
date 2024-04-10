#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN ((ll)(100005))

vector<ll> edges,aux;
int n,m;

bool check(int i)
{
    aux.clear();
    for(auto y : edges)
        aux.push_back(min((y/MAXN+i)%n,(y%MAXN+i)%n)*MAXN+max((y/MAXN+i)%n,(y%MAXN+i)%n));

    sort(aux.begin(),aux.end());

    bool res=1;
    for(int i=0;i<m;i++)
        res&=(edges[i]==aux[i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll u,v;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        u--,v--;
        if(u>v)
            swap(u,v);
        edges.push_back(u*MAXN+v);
    }

    sort(edges.begin(),edges.end());

    bool ok=1;
    for(int i=1;i<n && ok;i++)
        if(!(n%i) && check(i))
        {
            ok=0;
            db("Yes")
        }

    if(ok)
        db("No")

    return 0;
}