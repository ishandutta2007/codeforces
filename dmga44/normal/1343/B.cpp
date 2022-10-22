#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
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
        int n;
        cin >> n;
        if((n/2)&1)
            db("NO")
        else
        {
            db("YES")
            for(int i=2;i<=n;i+=2)
                cout << i << ' ';
            for(int i=1;i<n-2;i+=2)
                cout << i << ' ';
            cout << (n-1)+(n/2) << '\n';
        }
    }

    return 0;
}