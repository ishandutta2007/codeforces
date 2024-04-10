#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
#define MAXN 200005

int dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int res=0,n=s.size();
    s=s+s;
    dp[0]=1;
    for(int i=1;i<s.size();i++)
    {
        dp[i]=dp[i-1]+1;
        if(s[i]==s[i-1])
            dp[i]=1;
        res=max(res,dp[i]);
    }
    res=min(res,n);
    db(res)

    return 0;
}