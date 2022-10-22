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
#define MAXN 400005

ll a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,x;
    cin >> n >> x;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        a[i+n]=a[i];
    }
    n*=2;
    ll sum=0,l=0,r=0,ac=0;
    ll res=0;
    while(r<n)
    {
        ac+=(a[r]*(a[r]+1))/2;
        sum+=a[r];
        r++;
        while(sum>=x)
        {
            ac-=(a[l]*(a[l]+1))/2;
            sum-=a[l];
            l++;
        }

        ll sob=x-sum;
        if(l==0)
            res=max(res,ac);
        else
        {
            ll v=(sob*(sob-1))/2;
            res=max(res,ac+sob*a[l-1]-v);
        }
    }
    db(res)

    return 0;
}