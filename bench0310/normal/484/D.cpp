#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    ll one=-a[1];
    ll two=a[1];
    for(int i=1;i<=n;i++)
    {
        ll now=max(one+a[i],two-a[i]);
        if(i<n)
        {
            one=max(one,now-a[i+1]);
            two=max(two,now+a[i+1]);
        }
        else cout << now << "\n";
    }
    return 0;
}