#include <bits/stdc++.h>
using namespace std;




int n,a[100005];
bool dp[100005];

inline void check(int x){
    if (n/x<3) return;
    for (int i=1;i<=n;++i) {
        if (a[i]==0) dp[i]=false;
        else {
            if (i-x<=0) {
                if (!a[n+i-x]) dp[i]=false;
                else dp[i]=true;
            } else dp[i]=dp[i-x];
        }
    }
    for (int i=n-x+1;i<=n;++i)
    if (dp[i]) {
        cout<<"YES";
        exit(0);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
    if (n%i==0) {
        check(i);
        if (n/i!=i)
        check(n/i);
    }
    cout<<"NO";
}