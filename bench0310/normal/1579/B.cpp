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
        vector<int> b=a;
        sort(b.begin()+1,b.end());
        vector<array<int,2>> res;
        for(int i=n;i>=1;i--)
        {
            int x=-1;
            for(int j=1;j<=i;j++) if(a[j]==b[i]) x=j;
            if(x==i) continue;
            res.push_back({x,i});
            rotate(a.begin()+x,a.begin()+x+1,a.begin()+i+1);
        }
        cout << res.size() << "\n";
        for(auto [l,r]:res) cout << l << " " << r << " 1\n";
    }
    return 0;
}