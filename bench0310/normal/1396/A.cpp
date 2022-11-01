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
    if(n==1)
    {
        cout << "1 1\n";
        cout << -a[1] << "\n";
        for(int i=0;i<2;i++) cout << "1 1\n0\n";
    }
    else
    {
        cout << 1 << " " << n << "\n";
        for(int i=1;i<=n;i++) cout << -a[i]*n << " \n"[i==n];
        cout << 1 << " " << n-1 << "\n";
        for(int i=1;i<=n-1;i++) cout << (n-1)*a[i] << " \n"[i==n-1];
        cout << n << " " << n << "\n";
        cout << (n-1)*a[n] << "\n";
    }
    return 0;
}