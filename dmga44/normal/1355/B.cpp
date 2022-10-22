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
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin >> a[i];

        sort(all(a));

        int last=0;
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(i-last+1==a[i])
            {
                res++;
                last=i+1;
            }
        }
        db(res)
    }

    return 0;
}