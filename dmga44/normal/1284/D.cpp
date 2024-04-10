#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define MAXN 100005

int lg[MAXN];
vector<int> abi1[MAXN],abi2[MAXN];

void update1(int p,int v)
{
    while(p<MAXN)
    {
        abi1[p].push_back(v);
        p+=(p&-p);
    }
}

int query1(int p,int v)
{
    int res=0;
    while(p)
    {
        res+=lower_bound(all(abi1[p]),v)-abi1[p].begin();
        p-=(p&-p);
    }
    return res;
}

void update2(int p,int v)
{
    while(p<MAXN)
    {
        abi2[p].push_back(v);
        p+=(p&-p);
    }
}

int query2(int p,int v)
{
    int res=0;
    while(p)
    {
        res+=lower_bound(all(abi2[p]),v)-abi2[p].begin();
        p-=(p&-p);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lg[0]=-1;
    for(int i=1;i<MAXN;i++)
        lg[i]=lg[i-1]+!(i&(i-1));

    int n;
    cin >> n;
    vector<ppp> v;
    for(int i=0;i<n;i++)
    {
        int sa,ea,sb,eb;
        cin >> sa >> ea >> sb >> eb;
        v.push_back(ppp(pii(sa,ea),pii(sb,eb)));
    }

    sort(all(v));

    for(int i=0;i<n;i++)
    {
        update1(i+1,v[i].s.f);
        update2(i+1,v[i].s.s);
    }

    for(int i=0;i<MAXN;i++)
    {
        sort(all(abi1[i]));
        sort(all(abi2[i]));
    }

    bool ok=1;
    for(int i=0;i<n;i++)
    {
        pii p2=v[i].second;
        int l2=p2.second;
        int l1=p2.f;
        int pos=lower_bound(all(v),ppp(pii(v[i].f.s+1,0),pii(0,0)))-v.begin();
        if(pos!=n)
        {
            int x=query2(n,l1)-query2(pos,l1);
            int y=query1(n,l2+1)-query1(pos,l2+1);
            y=(n-pos-y);
            ok&=(x+y==(n-pos));
        }
        if(pos!=i+1)
        {
            int x=query2(pos,l1)-query2(i+1,l1);
            int y=query1(pos,l2+1)-query1(i+1,l2+1);
            y=(pos-i-1-y);
            ok&=!(x+y);
        }
    }
    if(ok)
        db("YES")
    else
        db("NO")

    return 0;
}
/**
2
1 2 7 8
3 4 3 6

3
1 3 2 4
4 5 6 7
3 4 5 5

6
1 5 2 9
2 4 5 8
3 6 7 11
7 10 12 16
8 11 13 17
9 12 14 18
**/