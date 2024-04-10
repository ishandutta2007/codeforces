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
        map<int,int> c;
        int m=0;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            m=max(m,++c[a[i]]);
        }
        int now=m;
        int res=0;
        while(now<n)
        {
            res++;
            int cnt=min(n-now,now);
            res+=cnt;
            now+=cnt;
        }
        cout << res << "\n";
    }
    return 0;
}