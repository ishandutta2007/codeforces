#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,k,r,c;
    cin >> n >> m >> k >> r >> c;
    const ll mod=1000000007;
    auto fpow=[&](ll b,ll e)->ll
    {
        b%=mod;
        ll res=1;
        while(e)
        {
            if(e&1) res=(res*b)%mod;
            b=(b*b)%mod;
            e/=2;
        }
        return res;
    };
    ll ax,ay,bx,by;
    cin >> ax >> ay >> bx >> by;
    auto intersect=[&](ll al,ll ar,ll bl,ll br)->ll{return max(ll(0),min(ar,br)-max(al,bl)+1);};
    ll i=intersect(ax,ax+r-1,bx,bx+r-1)*intersect(ay,ay+c-1,by,by+c-1);
    ll u=(2*r*c-i);
    if(i==r*c) i=0;
    cout << fpow(k,r*c-i+n*m-u) << "\n";
    return 0;
}