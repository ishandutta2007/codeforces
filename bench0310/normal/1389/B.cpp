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
        int n,k,z;
        cin >> n >> k >> z;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<int> m(n+1,0);
        for(int i=2;i<=n;i++) m[i]=max(m[i-1],a[i-1]+a[i]);
        vector<int> s(n+1,0);
        for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
        int res=s[k+1];
        for(int i=1;i<=z;i++)
        {
            if(1+k-2*i<=1) continue;
            res=max(res,s[1+k-2*i]+i*m[1+k-2*i]);
        }
        for(int i=0;i<z;i++)
        {
            if(1+k-2*i-1<=1) continue;
            res=max(res,s[1+k-2*i-1]+i*m[1+k-2*i-1]+a[1+k-2*i-2]);
        }
        cout << res << "\n";
    }
    return 0;
}