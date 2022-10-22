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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(2e18)
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

ll a[MAXN];

struct ABI{
    vector<ll> abi;
    int n;
    ABI(int n) : n(n),abi(n+5) {}

    void update(int l,int r,ll v)
    {
        update(l+1,v);
        update(r+2,-v);
    }

    void update(int p,ll v)
    {
        while(p<n+5)
        {
            abi[p]+=v;
            p+=(p&-p);
        }
    }

    ll query(int l,int r)
    {
        return query(l+1)+a[l];
    }

    ll query(int p)
    {
        ll res=0;
        while(p)
        {
            res+=abi[p];
            p-=(p&-p);
        }
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
//    cin >> n;
    scanf("%d",&n);
    vector<int> kk;
    for(int i=0;i<n;i++)
    {
//        cin > a[i];
        scanf("%lld",&a[i]);
        if(i && a[i]>=a[i-1]+2)
            kk.push_back(i);
    }

    ABI abi(n);

    stack<ll> s;
    for(ll i=1;i<n;i++)
    {
        while(1)
        {
            if(s.empty())
            {
                ll dif=abi.query(i,i)-abi.query(i-1,i-1);
                ll c=dif/(i+1);
                abi.update(0,i-1,c);
                abi.update(i,i,-c*i);

                dif%=(i+1);
                if(dif<2)
                    break;
                else
                {
                    dif--;
                    abi.update(i,i,-dif);
                    abi.update(0,dif-1,1);
                    s.push(dif);
                    break;
                }
            }
            else
            {
                ll dif=abi.query(i,i)-abi.query(i-1,i-1);
                if(dif<2)
                    break;
                else
                {
                    int u=s.top();
                    s.pop();
                    dif--;
                    if(dif>=(i-u))
                    {
                        abi.update(i,i,-(i-u));
                        abi.update(u,i-1,1);
                    }
                    else
                    {
                        abi.update(i,i,-dif);
                        abi.update(u,u+dif-1,1);
                        s.push(u+dif);
                    }
                }
            }
        }

//        for(int i=0;i<n;i++)
//            printf("%lld ",abi.query(i,i));
//        printf("\n");

        if(abi.query(i-1,i-1)==abi.query(i,i))
            s.push(i);
    }

//    for(int i=0;i<2*n;i++)
//        st.push(i,0,0);

    for(int i=0;i<n;i++)
        printf("%lld ",abi.query(i,i));
    printf("\n");

    return 0;
}
/**
4
2 6 7 8
**/