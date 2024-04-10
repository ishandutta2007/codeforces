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
typedef pair<vector<ll>,vector<pii> > pvv;

int check(vector<ll> &v,vector<ll> &a)
{
    /**
    0 => ok
    -1 => impo
    2 => mon decrec
    1 => mon crec
    3 => al berro
    **/
    int n=v.size();
    bool ok=1;
    for(int i=0;i<n;i++)
        ok&=(v[i]==a[i]);
    if(ok)
        return 0;

    ll mav=-1e12,maa=-1e12;
    ll miv=1e12,mia=1e12;
    for(int i=0;i<n;i++)
    {
        mav=max(mav,v[i]);
        maa=max(maa,a[i]);
        miv=min(miv,v[i]);
        mia=min(mia,a[i]);
    }
    if(mav<maa || miv<mia)
        return -1;

    int d=0;
    bool c3=0;
    for(int i=1;i<n;i++)
    {
        d+=(v[i]>v[i-1]);
        c3|=(v[i]==v[i-1]);
    }
    if(c3)
        return 3;
    if(d==0)
        return 2;
    else if(d==n-1)
        return 1;
    return 3;
}

map<pii,ll> cc;
vector<ll> k;

ll comb(ll n,ll m)
{
    if(cc[pii(n,m)])
        return cc[pii(n,m)];
    ll res=1;
    for(ll i=1;i<=m;i++)
    {
        if(1e18/res<=(n-i+1))
        {
            cc[pii(n,m)]=-1;
            return -1;
        }
        res*=(n-i+1);
        res/=i;
        if(res>1e12)
        {
            cc[pii(n,m)]=-1;
            return -1;
        }
    }
    cc[pii(n,m)]=res;
    return res;
}

void solve(vector<ll> &v,ll x,vector<ll> &res)
{
    ll n=v.size();
    res[0]=v[0];
    for(int i=1;i<n;i++)
    {
        res[i]=v[i];
        for(int j=0;j<i;j++)
        {
            ll c=comb(x-1+(i-j),i-j);
            if(c==-1)
            {
                res[i]=-1;
                break;
            }
            if(1e18/c<=res[j])
            {
                res[i]=-1;
                break;
            }
            res[i]-=(res[j]*c);
            if(res[i]<=0)
                break;
        }
        if(res[i]<=0)
            break;
    }
}

void answer(vector<pii> &res)
{
    ll c[2];
    c[0]=c[1]=0;
    for(auto y : res)
        c[y.f]+=y.s;
    if(c[1]>2e5)
    {
        db("BIG")
        db(c[1])
    }
    else
    {
        reverse(all(res));
        char cc[2];
        cc[0]='R';
        cc[1]='P';
        db("SMALL")
        db(c[0]+c[1])
        for(auto y : res)
            for(int i=0;i<y.s;i++)
                cout << cc[y.f];
        db("")
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    k.resize(n);
    vector<ll> a(n),b(n);
    ll maa=-1e12,mia=1e12;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        maa=(a[i]>maa) ? a[i] : maa;
        mia=(a[i]<mia) ? a[i] : mia;
    }
    for(int i=0;i<n;i++)
        cin >> b[i];
    if(n==1)
    {
        if(a[0]==b[0])
        {
            db("SMALL")
            db(0)
            db("")
        }
        else
            db("IMPOSSIBLE")
        return 0;
    }

    queue<pvv> qv;
    qv.push(pvv(b,vector<pii>(0)));
    vector<ll> v;
    vector<pii> res;
    int cant=0;
    while(!qv.empty())
    {
        cant++;
        if(cant>150)
            while(1);
        pvv u=qv.front();
        qv.pop();

        v=u.first;
//        for(auto y : v)
//            cout << y << ' ';
//        cout << '\n';

        res=u.second;
        int x=check(v,a);
        if(x==0)
        {
            answer(res);
            return 0;
        }
        else if(x==3)
        {
            reverse(all(v));
            res.push_back(pii(0,1));

            x=check(v,a);
            if(x==0)
                answer(res);
            else
                db("IMPOSSIBLE")
            return 0;
        }
        if(x==-1)
        {
            db("IMPOSSIBLE")
            return 0;
        }
        reverse(all(v));
        res.push_back(pii(0,1));
        int xx=check(v,a);
        if(xx==0)
        {
            answer(res);
            return 0;
        }
        else
        {
            reverse(all(v));
            res.pop_back();
        }
        if(x==2)
        {
            reverse(all(v));
            res.push_back(pii(0,1));
            qv.push(pvv(v,res));
        }
        if(x==1)
        {
            if(n<20)
            {
                ll ant=0;
                for(ll po=(1ll<<40);po;po>>=1)
                {
                    solve(v,ant+po,k);
                    ll mav=-1e12;
                    for(int i=0;i<n;i++)
                        mav=max(mav,k[i]);
                    if(check(k,a)==1 && mav>maa)
                        ant+=po;
                }
                ant++;

                solve(v,ant,k);
                res.push_back(pii(1,ant));
                qv.push(pvv(k,res));
            }
            else
            {
                for(int i=0;i<n;i++)
                    k[i]=v[i];
                int ant=0;
                while(1)
                {
                    ant++;
                    ll prefs=k[0];
                    bool ok=1;
                    ll mav=k[0];
                    for(int i=1;i<n;i++)
                    {
                        k[i]-=prefs;
                        prefs+=k[i];
                        ok&=(k[i]>k[i-1]);
                        mav=max(mav,k[i]);
                    }
                    if(!ok || mav<=maa)
                        break;
                }

                res.push_back(pii(1,ant));
                qv.push(pvv(k,res));
            }
        }
    }

    return 0;
}
/**
2
5 7
5 7


2
1 10
14 13

2
10 9
13 14

**/