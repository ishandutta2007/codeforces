#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,ll> ppi;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,r;
    cin >> n >> m >> r;
    int mi=1000;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        mi=min(mi,x);
    }

    int ma=0;
    for(int i=0;i<m;i++)
    {
        int x;
        cin >> x;
        ma=max(ma,x);
    }

    if(ma>mi)
        db((r%mi)+((r/mi)*ma))
    else
        db(r)

    return 0;
}