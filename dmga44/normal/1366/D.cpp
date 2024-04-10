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
#define MAXN (ll)(1e7+5)

int p[MAXN];

void criba()
{
    for(int i=2;i<MAXN;i+=2)
        p[i]=2;
    for(int i=3;i<MAXN;i+=2)
        if(!p[i])
            for(int j=i;j<MAXN;j+=i)
                p[j]=i;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    criba();

    int n,x;
    cin >> n;
    vector<pii> res;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        int a=x;
        vector<pii> ps;
        while(x!=1)
        {
            int act=p[x],e=0;
            while(p[x]==act)
            {
                e++;
                x/=act;
            }
            ps.push_back(pii(act,e));
        }
        vector<int> md;
        for(auto y : ps)
        {
            int r=1;
            for(int j=0;j<y.s;j++)
                r*=y.f;
            md.push_back(r);
        }

        for(int j=0;j<md.size();j++)
        {
            int d1=md[j];
            int d2=a/md[j];
            if(a%(d1+d2) && d2!=1)
            {
                res.push_back(pii(d1,d2));
                break;
            }
        }
        if(res.size()==i)
            res.push_back(pii(-1,-1));
    }

    for(int i=0;i<n;i++)
        cout << res[i].f << ' ';
    cout << '\n';
    for(int i=0;i<n;i++)
        cout << res[i].s << ' ';
    cout << '\n';

    return 0;
}
/**
10
2 3 4 5 6 7 8 9 10 24
**/