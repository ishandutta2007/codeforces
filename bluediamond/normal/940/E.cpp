#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=100000;

int n,k;
int v[N+5];
ll dp[N+5],s[N+5];

int st=1,dr=0,deq[N+5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
        s[i]=s[i-1]+v[i];
    }
    if(k==1) {
        cout<<"0\n";
        return 0;
    }
    for(int i=1;i<=n;i++) {
        while(st<=dr && v[i]<=v[deq[dr]])
            dr--;
        deq[++dr]=i;
        if(deq[st]<=i-k)
            st++;
        dp[i]=dp[i-1]+v[i];
        if(i>=k) {
            dp[i]=min(dp[i],dp[i-k]+s[i]-s[i-k]-v[deq[st]]);
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}
/**

**/