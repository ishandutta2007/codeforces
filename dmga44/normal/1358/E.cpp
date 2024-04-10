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
#define MAXN 1000005

ll a[MAXN];
ll ac[MAXN];
ll ak[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,x;
    cin >> n;
    ll sum=0;
    for(int i=0;i<(n+1)/2;i++)
    {
        cin >> a[i];
        sum+=a[i];
        ak[i+1]=ak[i]+a[i];
    }
    cin >> x;
    for(int i=(n+1)/2;i<n;i++)
    {
        a[i]=x;
        ak[i+1]=ak[i]+a[i];
    }
    if(sum+(n/2)*x>0)
    {
        db(n)
        return 0;
    }
//    for(int i=0;i<=n;i++)
//        cout << ak[i] << ' ';
//    cout << '\n';
    ll k=n/2;
    bool okk=1,okk_1=1;
    for(int i=0;i+k<=n;i++)
        okk&=(ak[i+k]>ak[i]);
    for(int i=0;i+k+1<=n;i++)
        okk_1&=(ak[i+k+1]>ak[i]);
    if(okk)
    {
        db(k)
        return 0;
    }
    if(okk_1)
    {
        db(k+1)
        return 0;
    }
//    db("xxx")

    ac[0]=x*(n/2);
    for(ll i=1;i<=(n+1)/2;i++)
        ac[i]=ac[i-1]+(a[(n+1)/2-i]-x);
//    for(int i=0;i<=(n+1)/2;i++)
//        cout << ac[i] << ' ';
//    cout << '\n';
    for(ll i=(n+1)/2-1;i>=0;i--)
        ac[i]=min(ac[i],ac[i+1]);
    for(ll i=0;i<=(n+1)/2;i++)
        if(ac[i]+x*i>0)
        {
            db(k+i)
            return 0;
        }
    db(-1)

    return 0;
}
/**
5
2 2 -8
2

6
-2 -2 6
-1
**/