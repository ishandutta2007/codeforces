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
        vector<array<int,2>> a(n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i][0];
            a[i][1]=i+1;
        }
        ranges::sort(a,greater<>());
        int l=-1,r=1;
        vector<int> x(n+1,0);
        ll res=0;
        for(auto [p,i]:a)
        {
            if(abs(l)>=abs(r)) x[i]=r++;
            else x[i]=l--;
            res+=(ll(2)*p*abs(x[i]));
        }
        cout << res << "\n";
        for(int i=0;i<=n;i++) cout << x[i] << " \n"[i==n];
    }
    return 0;
}