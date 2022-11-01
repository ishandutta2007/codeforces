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
        vector<int> w(n+1,0);
        for(int i=1;i<=n;i++) cin >> w[i];
        int res=0;
        int r=n+1;
        ll a=0,b=0;
        for(int l=1;l<=n;l++)
        {
            a+=w[l];
            while(r-1>=1&&a>b) b+=w[--r];
            if(l>=r) break;
            if(a==b) res=max(res,l+n-r+1);
        }
        cout << res << "\n";
    }
    return 0;
}