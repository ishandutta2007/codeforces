#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,x;
    cin >> n;
    vector<int> res,p1;
    x=sqrt(n);
    for(int i=1;i<=n;i++)
    {
        p1.push_back(i);
        if(i%x==0 || i==n)
        {
            reverse(p1.begin(),p1.end());
            for(auto y : p1)
                res.push_back(y);
            p1.clear();
        }
    }

    for(auto y : res)
        cout << y << ' ';

    return 0;
}