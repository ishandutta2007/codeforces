#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n,d;
        cin >> n >> d;
        int cont=0,p=9;
        while(p<=d)
        {
            cont++;
            p*=10;
            p+=9;
        }
        db(cont*n)
    }

    return 0;
}