#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
ll arr[MAXN];
ll pre[MAXN][2];
ll suf[MAXN][2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n==1)printf("%lli\n",arr[0]);
    else {
        pre[0][0] = arr[0];
        for (int i = 1; i < n; i++) {
            pre[i][0] = pre[i - 1][0];
            pre[i][1] = pre[i - 1][1];
            pre[i][i % 2] += arr[i];
        }
        suf[n - 1][(n - 1) % 2] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i][0] = suf[i +1][0];
            suf[i][1] = suf[i +1][1];
            suf[i][i % 2] += arr[i];
        }
        ll ma=pre[n-1][0];
        for(int i=1;i<n;i++){
            ma=max(ma,suf[i][i%2]+pre[i-1][(i-1)%2]);
        }
        printf("%lli\n",ma);
    }
    return 0;
}