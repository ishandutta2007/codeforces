#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define MAXN 100005

int abi[MAXN],a[MAXN],b[MAXN],ta[MAXN];

int update(int p)
{
    while(p<MAXN)
    {
        abi[p]++;
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

    int n;
    cin >> n;
    vector<pii> v;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        ta[a[i]]=n-i;
    }
    for(int i=0;i<n;i++)
    {
        cin >> b[i];
        v.push_back(pii(n-i,ta[b[i]]));
    }

    sort(v.begin(),v.end());

    int res=0;
    for(int i=0;i<n;i++)
    {
        int x=query(v[i].second);
        if(x!=i)
            res++;
        update(v[i].second);
    }
    db(res)

    return 0;
}