#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 100005

int a[MAXN];

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
        for(int i=0;i<n;i++)
            cin >> a[i];
        int mi=1e9+5;
        int ma=0;
        int r2=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==-1)
            {
                if(i && a[i-1]!=-1)
                {
                    mi=min(mi,a[i-1]);
                    ma=max(ma,a[i-1]);
                }
                if(i<n-1 && a[i+1]!=-1)
                {
                    mi=min(mi,a[i+1]);
                    ma=max(ma,a[i+1]);
                }
            }
            if(i && a[i-1]!=-1 && a[i]!=-1)
                r2=max(r2,abs(a[i]-a[i-1]));
        }
        if(mi==1e9+5)
        {
            cout << "0 0\n";
            continue;
        }
        int r1=(mi+ma)/2;
        r2=max(r2,max(abs(r1-mi),abs(r1-ma)));
        cout << r2 << ' ' << r1 << '\n';
    }

    return 0;
}