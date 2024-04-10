#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> ppp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll sum=0,n,k,i=1;
    cin >> n >> k;
    while(1)
    {
        sum+=i;
        if(sum>=k && i+sum-k==n)
        {
            db(sum-k)
            return 0;
        }
        i++;
    }

    return 0;
}