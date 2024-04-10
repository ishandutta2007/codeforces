#include <bits/stdc++.h>
using namespace std;

int n,dp[200005][10];


inline string solve(string s) {
    n=s.size();
    s="#"+s;
    int x;
    for (int i=1;i<=n;++i) {
        for (int j=0;j<=9;++j)
            dp[i][j]=dp[i-1][j];
        x=s[i]-'0';
        dp[i][x]^=1;
    }
    int z;
    for (int i=n;i>0;--i) {
        z=0;
        x=s[i]-'0';


        for (int j=0;j<=9;++j)
            if (dp[i-1][j]) ++z;
        int last=-1;
        for (int j=0;j<x;++j)  if (j>0 || i>1) {
            if (dp[i-1][j] && n-i+1>=z) last=j;
            else if (n-i-1>=z) last=j;
        }
        if (last==-1) continue;
        multiset<int> ss;
        for (int j=0;j<=9;++j)
            if (dp[i-1][j]) ss.insert(j);
        if (dp[i-1][last]) ss.erase(ss.find(last));
        else ss.insert(last);
        string res="";
        for (int j=1;j<i;++j)
            res+=s[j];
        res+=char(last+'0');
        int xx=n-i;
        xx-=ss.size();
        for (int j=1;j<=xx;++j)
            ss.insert(9);
        while (!ss.empty()) {
            xx=*ss.rbegin();
            res+=char('0'+xx);
            ss.erase(ss.find(xx));
        }
        return res;
    }
    string res="";
    for (int i=1;i<=n-2;++i)
        res+="9";
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    while (n--) {
        string s;
        cin>>s;
        cout<<solve(s)<<'\n';
    }
}