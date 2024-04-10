#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 2000005

int a[MAXN],p[MAXN][2],abi[MAXN];

void update(int p)
{
    while(p<MAXN)
    {
        abi[p]++;
        p+=(p&-p);
    }
}

ll query(int p)
{
    ll res=0;
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

    int n,x;
    cin >> n >> x;
    for(int i=1;i<=x;i++)
        p[i][0]=MAXN,p[i][1]=-MAXN;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        p[a[i]][0]=min(p[a[i]][0],i);
        p[a[i]][1]=max(p[a[i]][1],i);
    }

    int mp=-1,pos=1;
    vector<int> v;
    v.push_back(-MAXN);
    while(p[pos][0]>mp && pos<x)
    {
        mp=max(p[pos][1],mp);
        v.push_back(mp);
        pos++;
    }

    ll res=0;
    mp=MAXN-1,pos=x;
    res+=lower_bound(v.begin(),v.end(),mp)-v.begin();
    while(p[pos][1]<mp && pos>1)
    {
        mp=min(p[pos][0],mp);
        res+=min((ll)(lower_bound(v.begin(),v.end(),mp)-v.begin()),(ll)(pos-1));
        pos--;
    }
    ll ls=pos;
    db(res)

    return 0;
}