#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define MAXN 300005

ll a[MAXN],b[MAXN],c[MAXN],n;

bool check(ll x)
{
    b[0]=-a[0];
    c[n-1]=(n-1)*x-a[n-1];
    for(ll i=1;i<n;i++)
    {
        b[i]=max(b[i-1],-i*x-a[i]);
        c[n-i-1]=max(c[n-i],(n-i-1)*x-a[n-i-1]);
    }

    bool ok=1;
    for(int i=0;i<n;i++)
    {
        ok&=(-(i*x)>=b[i]);
        ok&=((i*x)>=c[i]);
    }
    return ok;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    int res=0;
    for(int k=(1<<29);k;k>>=1)
        if(check(res+k))
            res+=k;
    db(res)

    return 0;
}