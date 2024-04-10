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
        ll k;
        cin >> n >> k;
        vector<int> a(n);
        int c=(1<<30);
        int d=-(1<<30);
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            c=min(c,a[i]);
            d=max(d,a[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(k&1) cout << d-a[i] << " \n"[i==n-1];
            else cout << a[i]-c << " \n"[i==n-1];
        }
    }
    return 0;
}