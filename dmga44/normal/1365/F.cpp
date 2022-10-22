#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;

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
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<n;i++)
            cin >> b[i];
        bool ok=1;
        if(n&1)
            ok&=(a[n/2]==b[n/2]);
        vector<pii> pa,pb;
        for(int i=0;i<n/2;i++)
        {
            int u=a[i];
            int v=a[n-i-1];
            if(u>v)
                swap(u,v);
            pa.push_back(pii(u,v));
            u=b[i];
            v=b[n-i-1];
            if(u>v)
                swap(u,v);
            pb.push_back(pii(u,v));
        }

        sort(all(pa));
        sort(all(pb));

        for(int i=0;i<n/2;i++)
            ok&=(pa[i]==pb[i]);
        if(ok)
            db("Yes")
        else
            db("No")
    }

    return 0;
}