#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(2e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<pii> vxy;
int n;
int mx=0;
int my=0;

pii okx(int dif)
{
    int x=mx-dif;
    x=max(0,x);
    int y=my;
    for(int i=0;i<n;i++)
        if(vxy[i].f<x)
            y=max(y,vxy[i].s+(x-vxy[i].f));
    y-=dif;
    y=max(0,y);
    if(!x && !y)
    {
        x++;
        y++;
    }
    bool res=1;
    for(int i=0;i<n;i++)
    {
        int xx=vxy[i].f;
        int yy=vxy[i].s;
        if(xx>=x && yy>=y)
        {
            int ma=max(xx-x,yy-y);
            res&=(ma<=dif);
        }
        else if(xx<x && yy<y)
        {
            int ma=max(x-xx,y-yy);
            res&=(ma<=dif);
        }
        else if(xx<x)
        {
            int ma=x-xx+yy-y;
            res&=(ma<=dif);
        }
        else
        {
            int ma=xx-x+y-yy;
            res&=(ma<=dif);
        }
    }
    if(res)
        return pii(x,y);
    return pii(-oo,-oo);
}

pii oky(int dif)
{
    int y=my-dif;
    y=max(0,y);
    int x=mx;
    for(int i=0;i<n;i++)
        if(vxy[i].s<y)
            x=max(x,vxy[i].f+(y-vxy[i].s));
    x-=dif;
    x=max(0,x);
    if(!x && !y)
    {
        x++;
        y++;
    }
    bool res=1;
    for(int i=0;i<n;i++)
    {
        int xx=vxy[i].f;
        int yy=vxy[i].s;
        if(xx>=x && yy>=y)
        {
            int ma=max(xx-x,yy-y);
            res&=(ma<=dif);
        }
        else if(xx<x && yy<y)
        {
            int ma=max(x-xx,y-yy);
            res&=(ma<=dif);
        }
        else if(xx<x)
        {
            int ma=x-xx+yy-y;
            res&=(ma<=dif);
        }
        else
        {
            int ma=xx-x+y-yy;
            res&=(ma<=dif);
        }
    }

    if(res)
        return pii(x,y);
    return pii(-oo,-oo);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        int x=0;
        int y=0;
        int len=s.size();
        for(int j=0;j<len;j++)
        {
            if(s[j]=='N')
                x++;
            if(s[j]=='B')
                y++;
        }
        vxy.push_back(pii(x,y));
        mx=max(mx,x);
        my=max(my,y);
    }

    int res=-1;
    for(int po=(1<<19);po;po>>=1)
        if(okx(res+po).f==-oo && oky(res+po).f==-oo)
            res+=po;
    res++;
    pii p1=okx(res);
    pii p2=oky(res);
    db(res)
//    cout << p1.f << ' ' << p1.s << '\n';
//    cout << p2.f << ' ' << p2.s << '\n';
    if(p1.f!=-oo)
    {
        for(int i=0;i<p1.f;i++)
            cout << 'N';
        for(int i=0;i<p1.s;i++)
            cout << 'B';
        cout << '\n';
    }
    else
    {
        for(int i=0;i<p2.f;i++)
            cout << 'N';
        for(int i=0;i<p2.s;i++)
            cout << 'B';
        cout << '\n';
    }

    return 0;
}
/**
3
B
N
BN

10
N
BBBBBB
BNNNBBNBB
NNNNBNBNNBNNNBBN
NBNBN
NNNNNN
BNBNBNBBBBNNNNBBBBNNBBNBNBBNBBBBBBBB
NNNNBN
NBBBBBBBB
NNNNNN

8
NNN
NNN
BBNNBBBN
NNNBNN
B
NNN
NNNNBNN
NNNNNNNNNNNNNNNBNNNNNNNBNB

3
BNNNBNNNNBNBBNNNBBNNNNBBBBNNBBBBBBNBBBBBNBBBNNBBBNBNBBBN
BBBNBBBBNNNNNBBNBBBNNNBB
BBBBBBBBBBBBBBNBBBBBNBBBBBNBBBBNB

**/