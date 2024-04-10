#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
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
        int a,b,c,n;
        cin >> a >> b >> c >> n;
        if((a+b+c+n)%3==0 && max(a,max(b,c))<=(a+b+c+n)/3)
            db("YES")
        else
            db("NO")
    }

    return 0;
}