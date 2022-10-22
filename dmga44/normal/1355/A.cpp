#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;

vector<int> d(ll x)
{
    if(!x)
        return {0};
    vector<int> res;
    while(x)
    {
        res.push_back(x%10);
        x/=10;
    }
    sort(all(res));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n,k;
        cin >> n >> k;
        vector<int> ds=d(n);
        k--;
        while(ds[0] && k--)
        {
            n+=(ds[0]*ds[ds.size()-1]);
            ds=d(n);
        }
        db(n)
    }

    return 0;
}