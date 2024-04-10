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
        vector<ll> x,y;
        for(int i=0;i<2*n;i++)
        {
            ll a,b;
            cin >> a >> b;
            if(a==0) y.push_back(abs(b));
            else x.push_back(abs(a));
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        double res=0;
        for(int i=0;i<n;i++) res+=sqrt(x[i]*x[i]+y[i]*y[i]);
        cout << fixed << setprecision(15) << res << "\n";
    }
    return 0;
}