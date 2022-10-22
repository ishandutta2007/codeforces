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
typedef pair<ll,ll> pii;
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
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

vector<pii> vp;
vector<int> pos;

int nex(pip x)
{
    int ty=x.s.s;
    int len=x.s.f;
    int p=x.f;
    if(!ty)
        return upper_bound(all(vp),pii(vp[p].f+len,MAXN))-vp.begin()-1;
    return lower_bound(all(vp),pii(vp[p].f-len,0))-vp.begin();
}

int solve(int p,int l)
{
    int last=-1;
    pip x=pip(pos[p],pii(l,0));
    while(1)
    {
        int act=nex(x);
        if(last==act && x.f==act)
            return act;
        int len=abs(vp[act].f-vp[x.f].f);
        int fal=x.s.f;
        fal-=len;
        if(!len || fal<=len || last!=act)
        {
            last=x.f;
            x=pip(act,pii(fal,1-x.s.s));
        }
        else
        {
            int cant=fal/len;
            int rest=fal%len;
            last=-1;
            if(cant&1)
                x=pip(x.f,pii(rest,x.s.s));
            else
                x=pip(act,pii(rest,1-x.s.s));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        vp.push_back(pii(pii(x,i)));
    }

    sort(all(vp));

    pos=vector<int>(n);
    for(int i=0;i<n;i++)
        pos[vp[i].s]=i;

    while(m--)
    {
        int p,l;
        cin >> p >> l;
        p--;
        db(vp[solve(p,l)].s+1)
    }

    return 0;
}
/**
3 2
0 3 5
2 3
1 8

4 4
1 5 7 15
1 4
2 15
3 16
1 28
**/