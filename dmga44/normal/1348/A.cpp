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
        if(n==2)
        {
            db(2)
        }
        else
        {
            ll s1=0,s2=0;
            for(int i=1;i<=n;i++)
            {
                if(i<n/2 || i==n)
                    s1+=(1<<i);
                else
                    s2+=(1<<i);
            }
            db(s1-s2)
        }
    }

    return 0;
}