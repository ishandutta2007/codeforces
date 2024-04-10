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
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    auto out=[&](vector<int> res={})
    {
        cout << res.size() << "\n";
        for(int x:res) cout << x << " ";
        cout << "\n";
        exit(0);
    };
    if(sum&1) out();
    vector<bool> dp(sum+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=sum-a[i];j>=0;j--)
        {
            if(dp[j]) dp[j+a[i]]=1;
        }
    }
    if(dp[sum/2]==0) out();
    array<int,2> mn={30,0};
    for(int i=1;i<=n;i++)
    {
        int p=0;
        while((a[i]%2)==0)
        {
            p++;
            a[i]/=2;
        }
        mn=min(mn,{p,i});
    }
    out({mn[1]});
    return 0;
}