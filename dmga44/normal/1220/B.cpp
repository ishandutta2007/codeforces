#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 1005

ll a[MAXN][MAXN],res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];

    ll x=0;
    for(int i=1;i<n;i++)
        x=__gcd(x,a[0][i]);

    vector<int> divs;
    for(int i=1;i<=sqrt(x)+1;i++)
        if(x%i==0)
        {
            divs.push_back(i);
            divs.push_back(x/i);
        }

    for(auto y : divs)
    {
        res[0]=y;
        for(int i=1;i<n;i++)
            res[i]=a[0][i]/y;
        bool ok=1;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<n;j++)
                ok&=(a[i][j]==(res[i]*res[j]));
        if(ok)
        {
            for(int i=0;i<n;i++)
                cout << res[i] << ' ';
            cout << '\n';
            return 0;
        }
    }

    return 0;
}