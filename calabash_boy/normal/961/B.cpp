

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int a[maxn],sum[maxn];
int t[maxn];
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for (int i=1;i<=n;i++){
        scanf("%d",t+i);
    }
    int ans =0;
    for (int i=1;i<=n;i++){
        sum[i] = sum[i-1];
        if (t[i]){
            ans+=a[i];
        }else{
            sum[i]+=a[i];
        }
    }
    int ans2 =0;
    for (int i=1;i<=n-k+1;i++){
        ans2 = max(ans2,sum[i+k-1]-sum[i-1]);
    }
    cout<<ans+ans2<<endl;
    return 0;
}