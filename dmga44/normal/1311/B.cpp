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

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> a(n),p(m);
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<m;i++)
        {
            cin >> p[i];
            p[i]--;
        }
        sort(p.begin(),p.end());

        int ini=p[0],last=-1;
        for(int i=0;i<m;i++)
        {
            if(i && p[i]!=p[i-1]+1)
            {
                sort(a.begin()+ini,a.begin()+last+1);
                ini=p[i];
            }
            last=p[i]+1;
        }
//        cout << ini << ' ' << last << "xxx" << '\n';
        sort(a.begin()+ini,a.begin()+last+1);

        bool ok=1;
        for(int i=1;i<n;i++)
            ok&=(a[i]>=a[i-1]);
        if(ok)
            db("YES")
        else
            db("NO")
    }

    return 0;
}