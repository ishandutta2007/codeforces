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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<int> res(n+1,0);
        function<void(int,int,int)> go=[&](int l,int r,int d)
        {
            if(l>r) return;
            int m=l;
            for(int i=l;i<=r;i++) if(a[i]>a[m]) m=i;
            res[m]=d;
            go(l,m-1,d+1);
            go(m+1,r,d+1);
        };
        go(1,n,0);
        for(int i=1;i<=n;i++) cout << res[i] << "\n";
    }
    return 0;
}