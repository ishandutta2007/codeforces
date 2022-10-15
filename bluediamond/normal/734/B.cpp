#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll x2,x3,x5,x6,ans=0;
    cin>>x2>>x3>>x5>>x6;
    ll t=min(x2,min(x5,x6));
    x2-=t; x5-=t; x6-=t; ans+=(ll)t*256;
    t=min(x2,x3);
    ans+=(ll)32*t;
    cout<<ans<<"\n";
}
/**

32 256

**/