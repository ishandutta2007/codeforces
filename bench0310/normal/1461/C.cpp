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
        int n,m;
        cin >> n >> m;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        int idx=n;
        for(;idx>=1;idx--) if(a[idx]!=idx) break;
        double p=1;
        while(m--)
        {
            int r;
            double b;
            cin >> r >> b;
            if(r>=idx) p*=(1-b);
        }
        if(idx==0) p=0;
        cout << fixed << setprecision(14) << 1-p << "\n";
    }
    return 0;
}