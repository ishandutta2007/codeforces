#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 300005

int last[20],seen[MAXN][20],a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        for(int j=0;j<20;j++)
            if(a[i]&(1<<j))
            {
                seen[i+1][j]=i+1;
                for(int u=0;u<20;u++)
                    seen[i+1][u]=max(seen[i+1][u],seen[last[j]][u]);
                last[j]=i+1;
            }
    }

    while(q--)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        bool res=0;
        for(int i=0;i<20;i++)
            if((a[u]&(1<<i)) && seen[v+1][i]>u)
                res=1;
        if(res)
            db("Shi")
        else
            db("Fou")
    }

    return 0;
}