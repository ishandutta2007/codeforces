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
        ll s=0;
        int len=min(n,k);
        for(int i=1;i<len;i++) s+=a[i];
        ll opt=0;
        for(int i=len;i<=n;i++)
        {
            s+=a[i];
            opt=max(opt,s);
            s-=a[i-len+1];
        }
        ll res=opt+ll(len)*(len-1)/2;
        if(k<=n) cout << res << "\n";
        else cout << opt+ll(k-1)*n-(ll(n)*(n-1)/2) << "\n";
    }
    return 0;
}