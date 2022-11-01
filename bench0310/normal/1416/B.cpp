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
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            sum+=a[i];
        }
        if((sum%n)!=0)
        {
            cout << "-1\n";
            continue;
        }
        int goal=sum/n;
        vector<array<int,3>> res;
        auto op=[&](int i,int j,int x)
        {
            res.push_back({i,j,x});
            a[i]-=i*x;
            a[j]+=i*x;
        };
        for(int i=2;i<=n;i++)
        {
            if((a[i]%i)!=0) op(1,i,(i-(a[i]%i)));
            op(i,1,a[i]/i);
        }
        for(int i=2;i<=n;i++) op(1,i,goal);
        cout << res.size() << "\n";
        for(auto [i,j,x]:res) cout << i << " " << j << " " << x << "\n";
    }
    return 0;
}