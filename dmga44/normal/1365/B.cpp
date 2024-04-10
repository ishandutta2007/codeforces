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
        int n,a,b;
        cin >> n;
        vector<int> as(n);
        int ok=0,cant=0;
        for(int i=0;i<n;i++)
        {
            cin >> a;
            as[i]=a;
            if(i)
                cant+=(as[i]>=as[i-1]);
        }
        for(int i=0;i<n;i++)
        {
            cin >> b;
            ok|=(1<<b);
        }

        if(cant==n-1 || ok==3)
            db("Yes")
        else
            db("No")
    }
    return 0;
}