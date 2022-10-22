#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--)
    {
        ll k,n,a,b;
        cin >> k >> n >> a >> b;
        if(k<=n*b)
            db(-1)
        else
        {
            a-=b;
            k-=((n*b)+1);
            db(min(k/a,n))
        }
    }

    return 0;
}