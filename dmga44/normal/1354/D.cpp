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
#define pi		3.14159265358979323846
#define MAXN 1000005

int abi[MAXN];

void update(int p,int v)
{
    while(p<MAXN)
    {
        abi[p]+=v;
        p+=(p&-p);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q,v;
    cin >> n >> q;
    for(int i=0;i<n;i++)
    {
        cin >> v;
        update(v,1);
    }

    while(q--)
    {
        int k;
        cin >> k;
        if(k>0)
            update(k,1);
        else
        {
            k=-k;
            ll res=0,ac=0;
            for(int po=(1<<19);po;po>>=1)
                if(res+po<MAXN && ac+abi[res+po]<k)
                {
                    res+=po;
                    ac+=abi[res];
                }
            res++;
            update(res,-1);
        }
    }

    int res=0;
    for(int i=0;i<MAXN;i++)
        if(abi[i])
        {
            res=i;
            break;
        }

    db(res)

    return 0;
}