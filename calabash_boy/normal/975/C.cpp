
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
typedef long long LL;
LL a[maxn];
LL sum[maxn],k[maxn];
LL used[maxn];
int n,q;
int main(){
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++){
        scanf("%I64d",a+i);
    }
    for (int i=1;i<=q;i++){
        scanf("%I64d",k+i);
    }
    for (int i=1;i<=n;i++){
        sum[i] = sum[i-1]+a[i];
    }
    for (int i=1,now =1;i<=q;i++){
        int temp = lower_bound(sum+1,sum+n+1,sum[now-1]+used[now]+k[i])-sum;
        if (temp<=n){
            if (sum[now-1]+used[now]+k[i]==sum[n]){
                printf("%d\n",n);
                now =1;
                used[now] =0;
            }else{
                if (sum[now-1]+used[now]+k[i]==sum[temp]){
                    temp++;
                }
                if (temp>n){
                    printf("%d\n",n);
                    now =1;
                    used[now]=1;
                }else{
                    printf("%d\n",n-temp+1);
                    if (temp==now){
                        used[now]+=k[i];
                    }else{
                        used[temp] =sum[now-1]+used[now]+k[i]-sum[temp-1];
                        now = temp;
                    }
                }
            }
        }else{
            printf("%d\n",n);
            now =1;
            used[now]=0;
        }
    }
}