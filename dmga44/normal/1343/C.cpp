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
        int n,v;
        cin >> n;
        pii ac[2];
        ac[0]=ac[1]=pii(0,0);
        for(int i=0;i<n;i++)
        {
            cin >> v;
            bool ok=v>0;
            ac[ok]=max(ac[ok],pii(ac[!ok].first+1,ac[!ok].second+v));
        }

        pii ma=max(ac[0],ac[1]);
        db(ma.second)
    }

    return 0;
}