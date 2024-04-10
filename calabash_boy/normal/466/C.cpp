#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+100;
typedef long long ll;
ll a[maxn];
int n;
ll sum[maxn];
int cnt[maxn];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%lld",a+i);
        sum[i] = sum[i-1] + a[i];
    }
    ll SUM = sum[n];
    if (abs(SUM) % 3 != 0 || n <3){
        puts("0");
        return 0;
    }
    SUM /=3;
    for (int i=1;i<=n;i++){
        cnt[i] = cnt[i-1];
        if (sum[i] == SUM)cnt[i] ++;
    }
    SUM <<=1 ;
    ll ans = 0;
    for (int i=n;i>=3;i--){
        if (sum[i-1] == SUM){
            ans += cnt[i-2];
        }
    }
    cout<<ans<<endl;
    return 0;
}