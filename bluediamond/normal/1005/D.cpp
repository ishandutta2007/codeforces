#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=200000;
int n,dp[N+5],s[N+5];
int lst[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a;
    cin>>a;
    n=a.size();
    a="x"+a;
    for(int i=1;i<=n;i++) {
        s[i]=s[i-1]+(a[i]-'0');
        s[i]%=3;
    }
    lst[0]=0;
    lst[1]=lst[2]=-1;
    for(int i=1;i<=n;i++) {
        dp[i]=dp[i-1];
        if(lst[s[i]]!=-1)
            dp[i]=max(dp[i],dp[lst[s[i]]]+1);
        lst[s[i]]=i;
    }
    cout<<dp[n]<<"\n";
    return 0;
}
/**
**/