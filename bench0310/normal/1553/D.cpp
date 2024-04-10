#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        string s,t;
        cin >> s >> t;
        s+="$";
        t+="$";
        int n=s.size();
        int m=t.size();
        array<int,2> dp={0,0};
        int one=((n-1)&1)^((m-1)&1);
        for(int i=0;i<n;i++)
        {
            if(dp[1-(i&1)]==0)
            {
                if((i&1)==one&&s[i]==t[0]) dp[i&1]=1;
            }
            else if(dp[1-(i&1)]<m&&s[i]==t[dp[1-(i&1)]]) dp[i&1]=max(dp[i&1],dp[1-(i&1)]+1);
        }
        if(dp[0]==m||dp[1]==m) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}