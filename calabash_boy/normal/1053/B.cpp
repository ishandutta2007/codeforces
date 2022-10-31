#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+100;
typedef long long LL;
int sum[maxn][2];
int sum_a[maxn];
LL a[maxn];
int n;
LL ans =0;
int main(){
    scanf("%d",&n);
    LL tot = 0;
    sum[0][0] =1;
    for (int i=1;i<=n;i++){
        scanf("%lld",a+i);
        a[i] = __builtin_popcountll(a[i]);
        tot += a[i];
        tot &=1;
        sum_a[i] = tot;
        sum[i][0] = sum[i-1][0];
        sum[i][1] = sum[i-1][1];
        sum[i][tot] ++;
        LL maxVal = a[i];
        int sumVal = 0;
        for (int j=0;j<=128;j++){
            int R = i;
            int L = i-j;
            if (L <1)continue;
            maxVal = max(maxVal,a[L]);
            sumVal += a[L];
            if (sum_a[L-1] == tot && 2*maxVal <= sumVal)ans++;
        }
        int L = i-128-1;
        if (L>=1){
            ans += sum[L-1][tot];
        }
    }
    cout<<ans<<endl;
    return 0;
}