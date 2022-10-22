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
        string t;
        cin >> t;
        bool ok=1;
        for(int i=0;i<t.size();i++)
            ok&=t[i]==t[0];
        if(ok)
        {
            db(t)
            continue;
        }
        for(int i=0;i<t.size();i++)
            cout << "01";
        cout << '\n';
    }

    return 0;
}