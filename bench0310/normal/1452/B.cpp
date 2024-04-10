#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n+1,0);
        ll sum=0;
        ll m=0;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            sum+=a[i];
            m=max(m,a[i]);
        }
        m=max(m,(sum+(n-2))/(n-1));
        cout << m*(n-1)-sum << "\n";
    }
    return 0;
}