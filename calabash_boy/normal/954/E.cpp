#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
typedef long long LL;
int n,T;
int a[maxn];
int t[maxn];
int rk[maxn],cnt;
bool cmp(int x,int y){
    return t[x]<t[y];
}
int main(){
    cin>>n>>T;
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    for (int i=0;i<n;i++){
        scanf("%d",t+i);
        t[i]-=T;
    }
    double ans =0;
    LL sum1=0,sum2=0;
    LL ans1=0,ans2=0;
    for (int i=0;i<n;i++){
        if (t[i]==0){
            ans+=a[i];
        }else{
            if (t[i]>0){
                sum1+=1LL*a[i]*t[i];
                ans1+=a[i];
            }else{
                sum2+=-1LL*a[i]*t[i];
                ans2+=a[i];
            }
        }
    }
    if (sum1==0||sum2==0){
        printf("%.9f\n",ans);
        return 0;
    }
    if (sum1==sum2){
        ans+=ans1;
        ans+=ans2;
        printf("%.9f\n",ans);
        return 0;
    }
    ans+=sum1>sum2?ans2:ans1;
    if (sum1>sum2){
        for (int i=0;i<n;i++){
            if (t[i]>0){
                rk[cnt++] = i;
            }
        }
        sort(rk,rk+cnt,cmp);
        for (int ii=0;ii<cnt;ii++){
            int i = rk[ii];
            LL temp = 1LL*a[i]*t[i];
            if (sum2>=temp){
                ans+=a[i];
                sum2-=temp;
            }else{
                ans+=1.0*sum2/t[i];
                printf("%.9f\n",ans);
                return 0;
            }
        }
    }else{
        for (int i=0;i<n;i++){
            if (t[i]<0){
                rk[cnt++] = i;
            }
        }
        sort(rk,rk+cnt,cmp);
        for (int ii =cnt-1;ii>=0;ii--){
            int i = rk[ii];
            LL temp = 1LL*a[i]*(-t[i]);
            if (sum1>=temp){
                ans+=a[i];
                sum1-=temp;
            }else{
                ans-=1.0*sum1/t[i];
                printf("%.9f\n",ans);
                return 0;
            }
        }
    }
    printf("%.9f\n",ans);
    return 0;
}