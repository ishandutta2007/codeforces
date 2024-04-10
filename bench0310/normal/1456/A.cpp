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
        int n,p,k;
        cin >> n >> p >> k;
        string s;
        cin >> s;
        int x,y;
        cin >> x >> y;
        s="$"+s;
        vector<int> c(n+1,0);
        for(int i=n;i>=1;i--) c[i]=(s[i]=='1')+(i+k<=n?c[i+k]:0);
        int res=(1<<30);
        for(int i=p;i<=n;i++) res=min(res,(i-p)*y+((n-i)/k+1-c[i])*x);
        cout << res << "\n";
    }
    return 0;
}