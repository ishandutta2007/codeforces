#include <bits/stdc++.h>
using namespace std;




string s,ss;
int dp[5005][5005];
int f1[5005];
int f2[5005];

inline void get_lcp(string a,string b){
    memset(dp,0,sizeof(dp));
    int n,m;
    n=a.size(); m=b.size();
    for (int i=n-1;i>=0;--i)
        for (int j=m-1;j>=0;--j)
            dp[i][j] = ( a[i] == b[j] ? dp[i+1][j+1]+1 : 0);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>ss;
    get_lcp(s,s);
    int n=s.size();
    int m=ss.size();
    for (int i=0;i<n;++i) {
        int last=0;
        for (int j=0;j<n;++j)
            if (i!=j) last=max(last,dp[i][j]);
        ++last;
        f1[i]=last;
    }
    get_lcp(ss,ss);
    for (int i=0;i<m;++i) {
        int last=0;
        for (int j=0;j<m;++j)
            if (i!=j) last=max(last,dp[i][j]);
        ++last;
        f2[i]=last;
    }
    get_lcp(s,ss);
    int ans=1e9;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (dp[i][j]>=max(f1[i],f2[j])) ans=min(ans,max(f1[i],f2[j]));
    cout<< (ans==1e9 ? -1 : ans);
}