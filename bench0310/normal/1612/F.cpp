#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int q;
    cin >> q;
    set<array<int,2>> s;
    for(int i=0;i<q;i++)
    {
        int a,b;
        cin >> a >> b;
        if(n<m) swap(a,b);
        s.insert({a,b});
    }
    if(n<m) swap(n,m);
    vector<int> dp(m+1,0);
    dp[1]=1;
    auto chmax=[&](int &a,int b){a=max(a,b);};
    int res=0;
    while(dp[m]<n)
    {
        res++;
        vector<int> ndp(m+1,0);
        for(int a=1;a<=m;a++)
        {
            int b=dp[a];
            if(b==0) continue;
            int x=s.contains({b,a});
            chmax(ndp[a],min(n,a+b+x));
            chmax(ndp[min(m,a+b+x)],b);
        }
        dp=ndp;
    }
    cout << res << "\n";
    return 0;
}