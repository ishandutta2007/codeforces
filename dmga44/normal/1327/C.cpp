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
#define MAXN 1000005

int xy[MAXN][2],xyt[MAXN][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<k;i++)
        cin >> xy[i][0] >> xy[i][1];
    for(int i=0;i<k;i++)
        cin >> xyt[i][0] >> xyt[i][1];
    vector<char> res;
    if(n!=1 && m!=1)
    {
        for(int i=0;i<n;i++)
            res.push_back('U');
        for(int i=0;i<m;i++)
            res.push_back('L');

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m-1;j++)
            {
                if(i&1)
                    res.push_back('L');
                else
                    res.push_back('R');
            }
            res.push_back('D');
        }
    }
    else
    {
        if(n==1)
        {
            for(int i=0;i<m;i++)
                res.push_back('L');
            for(int i=0;i<m;i++)
                res.push_back('R');
        }
        else
        {
            for(int i=0;i<n;i++)
                res.push_back('U');
            for(int i=0;i<n;i++)
                res.push_back('D');
        }
    }

    db(res.size())
    for(auto y : res)
        cout << y;
    cout << '\n';

    return 0;
}