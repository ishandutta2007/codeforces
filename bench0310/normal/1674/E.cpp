#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    int res=(1<<30);
    for(int i=1;i+1<=n;i++)
    {
        int p=max({(a[i]+1)/2,(a[i+1]+1)/2,(a[i]+a[i+1]+2)/3});
        res=min(res,p);
    }
    for(int i=1;i+2<=n;i++)
    {
        int m=min(a[i],a[i+2]);
        res=min(res,m+(a[i]-m+1)/2+(a[i+2]-m+1)/2);
    }
    ranges::sort(a);
    res=min(res,(a[1]+1)/2+(a[2]+1)/2);
    cout << res << "\n";
    return 0;
}