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
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define MAXN (ll)(2e5+5)

int ask(int i,int j)
{
    cout << "? " << i+1 << ' ' << j+1 << '\n';
    cout.flush();
    int x;
    cin >> x;
    return x;
}
#define MAXN 3000

int mk[MAXN];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    srand(time(0));

    int n;
    cin >> n;
    int pos=0;
    int act=1;
    while(act<n)
    {
        int x=ask(pos,act);
        while(act<n && !mk[x])
        {
            mk[x]=act;
            act++;
            if(act<n)
                x=ask(pos,act);
        }
        if(act==n)
            break;

        pos=-1;
        int vi=-1;
        for(int i=0;i<MAXN;i++)
            if(mk[i])
            {
                if(pos==-1)
                {
                    pos=mk[i];
                    vi=i;
                }
                mk[i]=0;
            }
        if(vi==x)
            mk[ask(pos,act)]=act;
        act++;
    }

    int p1=pos;
    int p2=-1;
    for(int i=0;i<MAXN;i++)
        if(mk[i] && p2==-1)
            p2=mk[i];

    int p0=-1;
    if(p2==-1)
        p0=pos;
    while(p0==-1)
    {
        int p3=(rand()%n);
        while(p3==p1 || p3==p2)
            p3=(rand()%n);
        int x1=ask(p1,p3);
        int x2=ask(p2,p3);
        if(x1<x2)
            p0=p1;
        if(x2<x1)
            p0=p2;
    }

    vector<int> res(n);
    res[p0]=0;
    for(int i=0;i<n;i++)
        if(i!=p0)
            res[i]=ask(i,p0);

    cout << "!";
    for(int i=0;i<n;i++)
        cout << ' ' << res[i];
    cout << '\n';
    cout.flush();

    return 0;
}
/**
8
0 2 5 6 4 1 7 3
3
2 1 0
**/