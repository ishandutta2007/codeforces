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
        k++;
        vector<int> a(n+1,0);
        for(int i=0;i<n;i++) cin >> a[i];
        a[n]=18;
        string res;
        for(int i=0;i<n;i++)
        {
            ll mx=1;
            for(int j=1;j<=a[i+1]-a[i];j++) mx*=10;
            ll now=min(k,mx-1);
            string tmp=to_string(now);
            while((int)tmp.size()<a[i+1]-a[i]) tmp="0"+tmp;
            res=tmp+res;
            k-=now;
        }
        while(res[0]=='0') res.erase(res.begin());
        cout << res << "\n";
    }
    return 0;
}