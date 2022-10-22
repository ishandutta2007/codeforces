#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ll,pii> pip;

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
        vector<int> res;
        for(int i=2;i<=32000;i++)
        {
            if(n%i==0 && res.size()<2)
            {
                n/=i;
                res.push_back(i);
            }
        }

        if(n!=1 && res.size()==2 && res[0]!=n && res[1]!=n)
            res.push_back(n);

        if(res.size()==3)
        {
            db("YES")
            for(int y : res)
                cout << y << ' ';
            cout << '\n';
        }
        else
            db("NO")
    }

    return 0;
}