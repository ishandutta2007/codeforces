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
#define MAXN 400005

int a[MAXN],f[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        for(int i=0;i<=2*k;i++)
            f[i]=0;
        vector<pii> v,v2;
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<n/2;i++)
        {
            f[a[i]+a[n-i-1]]++;
            v.push_back(pii(min(a[i],a[n-i-1]),max(a[i],a[n-i-1])));
            v2.push_back(pii(max(a[i],a[n-i-1]),min(a[i],a[n-i-1])));
        }

        sort(all(v));
        sort(all(v2));

        int res=2*n;
        for(int i=2;i<=2*k;i++)
        {
            int p1=lower_bound(all(v2),pii(i-k,0))-v2.begin();
            int p2=n/2-(lower_bound(all(v),pii(i,0))-v.begin());
            res=min(res,n/2-f[i]+p1+p2);
        }
        db(res)
    }

    return 0;
}
/**
4
4 2
1 2 1 2
4 3
1 2 2 1
8 7
6 1 1 7 6 3 4 6
6 6
5 2 6 1 3 4
**/