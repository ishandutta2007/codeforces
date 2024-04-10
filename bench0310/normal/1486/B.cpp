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
        vector<int> x(n);
        vector<int> y(n);
        for(int i=0;i<n;i++) cin >> x[i] >> y[i];
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        if(n&1) cout << "1\n";
        else cout << (ll(x[n/2]-x[n/2-1]+1)*(y[n/2]-y[n/2-1]+1)) << "\n";
    }
    return 0;
}