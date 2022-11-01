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
        int idx=n;
        ll res=0;
        while(idx>1)
        {
            while(idx>1&&a[idx-1]<=a[idx]) idx--;
            if(idx==1) break;
            int d=a[idx-1]-a[idx];
            res+=d;
            a[idx]+=d;
        }
        cout << res << "\n";
    }
    return 0;
}