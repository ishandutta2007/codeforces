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
        vector<int> c(4,0);
        vector<int> a(6,0);
        for(int i=1;i<=3;i++) cin >> c[i];
        for(int i=1;i<=5;i++) cin >> a[i];
        bool res=[&]()->bool
        {
            for(int i=1;i<=3;i++)
            {
                c[i]-=a[i];
                if(c[i]<0) return 0;
            }
            int m=min(c[1],a[4]);
            c[1]-=m;
            c[3]-=(a[4]-m);
            if(c[1]<0||c[3]<0) return 0;
            m=min(c[2],a[5]);
            c[2]-=m;
            c[3]-=(a[5]-m);
            if(c[2]<0||c[3]<0) return 0;
            return 1;
        }();
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}