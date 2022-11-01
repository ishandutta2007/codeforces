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
        vector<int> a(n+2,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        int now=0;
        auto mv=[&](int i,int x){now+=(x*((a[i-1]<a[i]&&a[i]>a[i+1])||(a[i-1]>a[i]&&a[i]<a[i+1])));};
        for(int i=2;i<=n-1;i++) mv(i,1);
        int res=now;
        auto ch=[&](int i,int na)
        {
            int tmp=a[i];
            for(int j=max(2,i-1);j<=min(n-1,i+1);j++) mv(j,-1);
            a[i]=na;
            for(int j=max(2,i-1);j<=min(n-1,i+1);j++) mv(j,1);
            res=min(res,now);
            for(int j=max(2,i-1);j<=min(n-1,i+1);j++) mv(j,-1);
            a[i]=tmp;
            for(int j=max(2,i-1);j<=min(n-1,i+1);j++) mv(j,1);
        };
        for(int i=1;i<=n;i++)
        {
            for(int b:{a[i-1],a[i+1]}) for(int j=b-1;j<=b+1;j++) ch(i,j);
        }
        cout << res << "\n";
    }
    return 0;
}