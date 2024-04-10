#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
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
#define MAXN 505
#define oo 1e8

ll r[MAXN],b[MAXN];
bool mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,k;
    cin >> n >> k;
    ll res=0;
    ll cr=0,cb=0,l=0;
    mk[0]=1;
    for(ll i=0;i<n;i++)
    {
        cin >> r[i] >> b[i];
        ll a1=0,a2=0;
        if(r[i]>2*k)
            a1=(r[i]-k)/k;
        if(b[i]>2*k)
            a2=(b[i]-k)/k;
        res+=(a1+a2);
        r[i]-=k*a1;
        b[i]-=k*a2;
        cr+=r[i];
        cb+=b[i];
        if(r[i]+b[i]>=k)
        {
            ll x1=max(0ll,k-b[i]);
            ll x2=min(r[i],k);
            vector<int> oks;
            for(int j=0;j<k;j++)
                if(mk[j])
                    oks.push_back(j);
            for(int j=x1;j<=x2;j++)
                for(auto y : oks)
                    mk[(y+j)%k]=1;
        }
    }

    ll ant=res;
    for(ll i=0;i<k;i++)
        if(mk[i])
            res=max(res,ant+((cr-i)/k)+((cb+i)/k));
    db(res)

    return 0;
}
/**
2 5
8 0
0 7

2 7
8 1
5 0
**/