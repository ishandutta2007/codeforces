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
        int n,k,x;
        cin >> n >> k;
        set<int> ks;
        for(int i=0;i<n;i++)
        {
            cin >> x;
            ks.insert(x);
        }

        if(ks.size()>k)
            db(-1)
        else
        {
            db(k*100)
            for(int i=0;i<100;i++)
            {
                auto it=ks.begin();
                for(int j=0;j<k;j++)
                {
                    if(it==ks.end())
                        it=ks.begin();
                    cout << *(it) << ' ';
                    it++;
                }
            }
            cout << '\n';
        }
    }

    return 0;
}