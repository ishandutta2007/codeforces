#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
#define mod (ll)(1e9+7)
#define MAXN 300005

int a[MAXN][8],n,m;
vector<int> bm[300];

pii check(int x)
{
    for(int i=0;i<300;i++)
        bm[i].clear();
    int tot=(1<<m)-1;

    for(int i=0;i<n;i++)
    {
        int mask=0;
        for(int j=0;j<m;j++)
            if(a[i][j]>=x)
                mask+=(1<<j);
        //cout << i << ' ' << mask << '\n';
        if(bm[mask].empty())
        {
            bm[mask].push_back(i+1);
            for(int j=0;j<mask;j++)
                if((mask&j)==j && bm[j].empty())
                    bm[j].push_back(i+1);
        }
    }

    for(int i=0;i<=tot;i++)
        if(bm[i].size() && bm[tot-i].size())
            return pii(bm[i][0],bm[tot-i][0]);
    return pii(-1,-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];

    int res=0;
    for(int p=(1<<30);p;p>>=1)
        if(check(res+p).first!=-1)
            res+=p;

    pii ok=check(res);
    cout << ok.first << ' ' << ok.second << '\n';

    return 0;
}