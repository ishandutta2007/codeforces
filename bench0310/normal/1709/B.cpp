#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<ll> l(n+1,0);
    for(int i=1;i<n;i++) l[i]=l[i-1]+max(0,a[i]-a[i+1]);
    vector<ll> r(n+2,0);
    for(int i=n;i>1;i--) r[i]=r[i+1]+max(0,a[i]-a[i-1]);
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        if(x<y) cout << l[y-1]-l[x-1] << "\n";
        else cout << r[y+1]-r[x+1] << "\n";
    }
    return 0;
}