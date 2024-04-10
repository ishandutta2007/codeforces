#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string a,b,c;
        cin >> a >> b >> c;
        int n=a.size();
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            bool add=0;
//            if(a[i]==b[i])
//                add=1;
            if(a[i]==c[i] || b[i]==c[i])
                add=1;
            ok&=add;
        }
        if(ok)
            db("YES")
        else
            db("NO")
    }

    return 0;
}