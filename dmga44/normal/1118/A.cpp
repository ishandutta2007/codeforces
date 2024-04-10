#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    while(q--)
    {
        ll n,a,b;
        cin >> n >> a >> b;
        if(b>=a*2)
            db(n*a)
        else
            db(((n/2)*b)+((n&1)*a))
    }

    return 0;
}