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
#define MAXN 200005

int a[MAXN],b[MAXN];

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

        bool res=1;
        bool a1=0,a2=0;
        for(int i=0;i<n;i++)
        {
            cin >> b[i];
            bool ok=(b[i]==a[i]);
            if(b[i]<a[i] && a1)
                ok=1;
            if(b[i]>a[i] && a2)
                ok=1;
            res&=ok;

            if(a[i]==-1)
                a1=1;
            if(a[i]==1)
                a2=1;
        }
        if(res)
            db("YES")
        else
            db("NO")
    }
    return 0;
}