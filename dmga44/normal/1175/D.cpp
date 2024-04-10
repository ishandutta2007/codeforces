#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 300005

ll a[MAXN],ac[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=n-1;i>=0;i--)
        ac[i]=ac[i+1]+a[i];
    vector<ll> r;
    for(int i=1;i<n;i++)
        r.push_back(ac[i]);

    sort(r.rbegin(),r.rend());

    ll res=ac[0];
    k--;
    for(int i=0;i<k;i++)
        res+=r[i];
    db(res)

    return 0;
}