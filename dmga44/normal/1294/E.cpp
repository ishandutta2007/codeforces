#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    vector<vector<int> > a;
    for(int i=0;i<n;i++)
    {
        vector<int> add(m);
        for(int j=0;j<m;j++)
            cin >> add[j];
        a.push_back(add);
    }

    int res=0;
    for(int i=0;i<m;i++)
    {
        vector<int> ks(n);
        for(int j=0;j<n;j++)
            ks[j]=j+n;

        for(int j=0;j<n;j++)
        {
            if((a[j][i]-1)%m==i)
            {
                int pos=(a[j][i]-1)/m;
                if(pos<n)
                    ks[(j-pos+n)%n]--;
            }
        }

        int mi=2*n;
        for(int j=0;j<n;j++)
        {
            mi=min(mi,ks[j]);
//            cout << ks[j] << ' ';
        }
//        cout << '\n';
//        db(mi)
        res+=mi;
    }
    db(res)

    return 0;
}