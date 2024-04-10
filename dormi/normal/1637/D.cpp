#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=101;
bool dp[MN][MN*MN*2];
int arra[MN],arrb[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int totalsum=0;
        ll totans=0;
        for(int i=1;i<=n;i++){
            cin>>arra[i];
            totans+=ll(arra[i])*ll(arra[i])*ll(n-2);
            totalsum+=arra[i];
        }
        for(int i=1;i<=n;i++){
            cin>>arrb[i];
            totans+=ll(arrb[i])*ll(arrb[i])*ll(n-2);
            totalsum+=arrb[i];
        }
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=totalsum;j++){
                dp[i][j]=false;
                if(j>=arra[i]&&dp[i-1][j-arra[i]])dp[i][j]=true;
                if(j>=arrb[i]&&dp[i-1][j-arrb[i]])dp[i][j]=true;
            }
        }
        ll best=LLONG_MAX;
        for(int i=0;i<=totalsum;i++){
            if(dp[n][i])best=min(best,ll(i)*ll(i)+ll(totalsum-i)*ll(totalsum-i));
        }
        printf("%lli\n",best+totans);
    }
    return 0;
}