#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++) cin >> p[i];
        vector<array<int,2>> one(n+1);
        one[1]={p[1],1};
        for(int i=2;i<=n;i++) one[i]=min(one[i-1],{p[i],i});
        vector<array<int,2>> two(n+1);
        two[n]={p[n],n};
        for(int i=n-1;i>=1;i--) two[i]=min(two[i+1],{p[i],i});
        array<int,3> res={0,0,0};
        for(int i=2;i<=n-1;i++)
        {
            if(one[i-1][0]<p[i]&&p[i]>two[i+1][0]) res={one[i-1][1],i,two[i+1][1]};
        }
        if(res[0]!=0) cout << "YES\n" << res[0] << " " << res[1] << " " << res[2] << "\n";
        else cout << "NO\n";
    }
    return 0;
}