#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
#define MAXN 100005

int xy[MAXN][2];
map<pii,int> f;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> xy[i][0] >> xy[i][1];
        if(i)
        {
            int dx=xy[i][0]-xy[i-1][0];
            int dy=xy[i][1]-xy[i-1][1];
            f[pii(dx,dy)]++;
            f[pii(-dx,-dy)]++;
        }
    }
    int dx=xy[0][0]-xy[n-1][0];
    int dy=xy[0][1]-xy[n-1][1];
    f[pii(dx,dy)]++;
    f[pii(-dx,-dy)]++;

    bool ok=1;
    for(auto y : f)
        if(y.second!=2)
            ok=0;

    if(ok)
        db("YES")
    else
        db("NO")

    return 0;
}