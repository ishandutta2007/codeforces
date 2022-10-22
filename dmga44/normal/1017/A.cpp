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

    int n,a,b,c,d;
    cin >> n;
    vector<pii> res;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b >> c >> d;
        res.push_back(pii(a+b+c+d,-i));
    }

    sort(res.rbegin(),res.rend());

    int r=0;
    for(int i=0;i<n;i++)
        if(!res[i].second)
            r=i;
    db(r+1)

    return 0;
}