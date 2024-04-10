#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<psi> vs;
        vs.push_back(psi(s,0));
        string ai=s;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
                ai[j]=s[j+i];
            if((i&1)!=(n&1))
            {
                for(int j=n-i;j<n;j++)
                    ai[j]=s[n-j-1];
            }
            else
            {
                for(int j=n-i;j<n;j++)
                    ai[j]=s[j-n+i];
            }
            vs.push_back(psi(ai,i));
        }

        sort(vs.begin(),vs.end());

        db(vs[0].first)
        db(vs[0].second+1)
    }

    return 0;
}