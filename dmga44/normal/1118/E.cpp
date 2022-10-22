#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,k;
    cin >> n >> k;
    if(n>k*(k-1))
    {
        db("NO")
        return 0;
    }

    db("YES")
    for(ll i=1;i<k && n;i++)
        for(ll j=1;j<=k && n;j++)
        {
            ll cant=i+j;
            if(cant>k)
                cant-=k;
            cout << j << ' ' << cant << '\n';
            n--;
        }
    return 0;
}