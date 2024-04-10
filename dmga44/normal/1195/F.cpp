#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> ppp;
#define MAXN 400005

ll ini[MAXN],ant[MAXN];
vector<pii> di;
vector<int> abi[MAXN];

void solve(vector<pii> ps)
{
    int n=ps.size();
    for(int i=0;i<n;i++)
    {
        ll x1=ps[(i+1)%n].first-ps[i].first;
        ll y1=ps[(i+1)%n].second-ps[i].second;

        ll v=__gcd(abs(x1),abs(y1));
        x1/=v;
        y1/=v;
        di.push_back(pii(x1,y1));
    }
}

void update(int p,int v)
{
    int pp=p;
    while(p<MAXN)
    {
        abi[p].push_back(v);
        p+=(p&-p);
    }
}

int query(int p,int v)
{
    int res=0;
    while(p)
    {
        res+=upper_bound(abi[p].begin(),abi[p].end(),v)-abi[p].begin();
        p-=(p&-p);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x,y,k;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> k;
        ini[i]=di.size();
        vector<pii> ps;
        for(int j=0;j<k;j++)
        {
            cin >> x >> y;
            ps.push_back(pii(x,y));
        }

        solve(ps);
    }
    ini[n]=di.size();

    map<pii,int> m;
    int t=di.size();
    for(int i=0;i<t;i++)
    {
        ant[i]=m[di[i]]-1;
        m[di[i]]=i+1;
    }

    for(int i=0;i<t;i++)
        update(i+1,ant[i]);

    for(int i=0;i<MAXN;i++)
        sort(abi[i].begin(),abi[i].end());

//    for(int i=0;i<t;i++)
//    {
//        for(auto y : abi[i])
//            cout << y << ' ';
//        db("")
//    }

    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        l--,r--;
        int l1=ini[l];
        int r1=ini[r+1]-1;
//        db(l1)
//        db(r1)
        db(query(r1+1,l1-1)-l1)
//        db("")
    }

    return 0;
}