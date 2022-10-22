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
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define mod (ll)(1e9+7)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define MAXN 2005

int a[3][3],b[3][3];

int eval(pii x)
{
    if(x.f==x.s)
        return 0;
    if(x.f==((x.s+1)%3))
        return 1;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll k,a0,b0;
    cin >> k >> a0 >> b0;
    a0--,b0--;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin >> a[i][j];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin >> b[i][j];

    vector<pii> pos,dif;
    map<pii,int> mk;
    pii act=pii(a0,b0);
    int ga=0,gb=0;
    dif.push_back(pii(0,0));
    while(!mk[act])
    {
        pos.push_back(act);
        mk[act]=pos.size();
        int v=eval(act);
        if(v)
        {
            if(v==1)
                ga++;
            else
                gb++;
        }
        dif.push_back(pii(ga,gb));
        act=pii(a[act.f][act.s]-1,b[act.f][act.s]-1);
    }

    if(pos.size()>=k)
        cout << dif[k].f << ' ' << dif[k].s << '\n';
    else
    {
        int p=mk[act]-1;
        int cycle_len=pos.size()-p;
        ll cycle_vala=ga-dif[p].f;
        ll cycle_valb=gb-dif[p].s;
        ga=dif[p].f;
        gb=dif[p].s;
        k-=p;
        ll times=(k/cycle_len);
        ll add=k%cycle_len;
        ll ra=ga+times*cycle_vala+(dif[p+add].f-dif[p].f);
        ll rb=gb+times*cycle_valb+(dif[p+add].s-dif[p].s);
        cout << ra << ' ' << rb << '\n';
    }

    return 0;
}
/**
10 2 1
1 1 1
1 1 1
1 1 1
2 2 2
2 2 2
2 2 2

8 1 1
2 2 1
3 3 1
3 1 3
1 1 1
2 1 1
1 2 3

5 1 1
1 2 2
2 2 2
2 2 2
1 2 2
2 2 2
2 2 2
**/