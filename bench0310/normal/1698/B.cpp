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
        int n,k;
        cin >> n >> k;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        int c=0;
        for(int i=2;i<=n-1;i++) c+=(a[i]>a[i-1]+a[i+1]);
        if(k==1) cout << (n-1)/2 << "\n";
        else cout << c << "\n";
    }
    return 0;
}