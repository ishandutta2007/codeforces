#include <bits/stdc++.h>
using namespace std;


int n,k,d;
int a[500005];
int dp[500005];



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>d;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    dp[0]=1;
    int last=1;
    int cur;
    for (int i=1;i<=n;++i) {
        while (last<=i && a[i]-a[last]>d) ++last;
        dp[i]=dp[i-1];
        if (last-1<=i-k) {
            cur=dp[i-k];
            if (last-2>=0) cur-=dp[last-2];
            if (cur>0) ++dp[i];
        }
    }
    cout<<(dp[n]-dp[n-1] ? "YES" : "NO" );
}