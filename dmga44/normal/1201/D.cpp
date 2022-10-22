#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e15)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

ll lims[MAXN][2];
ll lr[MAXN][2];
map<pii,ll> dp;
map<pii,bool> mk;

ll aux(int r,int c,int li,int ls,int nc)
{
    ll add=0;
    if(c<=li)
        add=ls-c+abs(ls-nc);
    else if(c>=ls)
        add=c-li+abs(li-nc);
    else
    {
        add=ls-li;
        add+=min(c-li+abs(nc-ls),ls-c+abs(nc-li));
    }
    return add;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,m,k,qq;
    cin >> n >> m >> k >> qq;
    for(int i=0;i<n;i++)
    {
        lims[i][0]=oo;
        lims[i][1]=0;
    }
    ll maa=0;
    for(int i=0;i<k;i++)
    {
        ll x,y;
        cin >> x >> y;
        x--,y--;
        maa=max(x,maa);
        lims[x][0]=min(lims[x][0],y);
        lims[x][1]=max(lims[x][1],y);
    }
    for(int i=0;i<m;i++)
    {
        lr[i][0]=-1;
        lr[i][1]=m;
    }
    for(int i=0;i<qq;i++)
    {
        int x;
        cin >> x;
        x--;
        lr[x][0]=x;
        lr[x][1]=x;
    }

    for(int i=1;i<m;i++)
        lr[i][0]=max(lr[i][0],lr[i-1][0]);
    for(int i=m-2;i>=0;i--)
        lr[i][1]=min(lr[i][1],lr[i+1][1]);

    dp[pii(0,0)]=0;
    queue<pii> q;
    q.push(pii(0,0));
    while(1)
    {
        pii t=q.front();
        if(t.s==maa)
            break;
        q.pop();

        ll w=dp[t];
        ll r=t.s;
        ll c=t.f;
//        cout << r << ' ' << c << ' ' << w << '\n';
        if(lims[r][0]==oo)
        {
            if(!mk[pii(lr[c][1],r+1)])
            {
                mk[pii(lr[c][1],r+1)]=1;
                q.push(pii(lr[c][1],r+1));
                dp[pii(lr[c][1],r+1)]=lr[c][1]-c+w+1;
            }
            dp[pii(lr[c][1],r+1)]=min(lr[c][1]-c+w+1,dp[pii(lr[c][1],r+1)]);
            continue;
        }
        ll li=lims[r][0];
        ll ls=lims[r][1];
        set<int> s;
        s.insert(lr[li][0]);
        s.insert(lr[li][1]);
        s.insert(lr[ls][0]);
        s.insert(lr[ls][1]);
        for(auto nc : s)
        {
            if(nc==-1 || nc==m)
                continue;
            ll v=w+aux(r,c,li,ls,nc)+1;
            if(!mk[pii(nc,r+1)])
            {
                mk[pii(nc,r+1)]=1;
                q.push(pii(nc,r+1));
                dp[pii(nc,r+1)]=v;
            }
            dp[pii(nc,r+1)]=min(v,dp[pii(nc,r+1)]);
        }
    }

    vector<pii> qqq;
    while(!q.empty())
    {
        qqq.push_back(q.front());
        q.pop();
    }
    ll res=oo;
    for(auto y : qqq)
    {
//        cout << y.f << ' ' << y.s << ' ' << dp[y] << '\n';
        int c=y.f;
        ll w=dp[y];
        int li=lims[maa][0];
        int ls=lims[maa][1];
        if(li>=c)
            res=min(res,w+ls-c);
        else if(ls<=c)
            res=min(res,w+c-li);
        else
            res=min(res,w+ls-li+min(c-li,ls-c));
    }
    db(res)

    return 0;
}