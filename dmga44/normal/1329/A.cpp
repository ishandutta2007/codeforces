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

    int n,m;
    cin >> n >> m;
    vector<int> l(m);
    ll sum=0;
    for(int i=0;i<m;i++)
    {
        cin >> l[i];
        sum+=l[i];
    }
    if(sum<n)
    {
        db(-1)
        return 0;
    }

    int nn=n;
    vector<int> res(m+1);
    res[m]=n+1;
    for(int i=m-1;i>=0;i--)
    {
        if(i+1!=n)
        {
            if(i+l[i]<=n)
            {
                res[i]=res[i+1]-l[i];
                n-=l[i];
            }
            else
            {
                int x=n-i;
                n=i;
                res[i]=res[i+1]-x;
            }
        }
        else
        {
            res[i]=res[i+1]-1;
            n--;
        }
    }

    bool ok=1;
    for(int i=0;i<m;i++)
        ok&=(res[i]+l[i]-1<=nn);

    if(ok)
    {
        for(int i=0;i<m;i++)
            cout << res[i] << ' ';
        cout << '\n';
    }
    else
        db(-1)

    return 0;
}