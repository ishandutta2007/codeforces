#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    while(q--)
    {
        int n,m;
        cin >> n >> m;
        int ac=0,l1=m,l2=m,t,l,r;
        bool res=1;
        for(int i=0;i<n;i++)
        {
            cin >> t >> l >> r;
            l1-=(t-ac);
            l2+=(t-ac);
            ac=t;
            l1=max(l1,l);
            l2=min(l2,r);
            res&=(l1<=l2);
        }
        if(res)
            db("YES")
        else
            db("NO")
    }

    return 0;
}