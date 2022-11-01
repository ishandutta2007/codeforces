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
    int cnt=0,res=0;
    int now=10;
    sort(a.begin(),a.end());
    for(int i=1;i<=n;i++)
    {
        now+=a[i];
        if(now>720) break;
        cnt++;
        res+=max(0,now-360);
    }
    cout << cnt << " " << res << "\n";
    return 0;
}