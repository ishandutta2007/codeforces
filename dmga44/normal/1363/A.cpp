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
        int n,x;
        cin >> n >> x;
        vector<int> a(n);
        bool ok=0,ok2=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            ok|=(a[i]&1);
            ok2|=(!(a[i]&1));
            sum+=(a[i]&1);
        }

        if(!ok)
            db("No")
        else
        {
            if(x==n)
            {
                if(sum&1)
                    db("Yes")
                else
                    db("No")
            }
            else if(x&1)
                db("Yes")
            else if(ok2)
                db("Yes")
            else
                db("No")
        }
    }

    return 0;
}