#include<bits/stdc++.h>
#define n2 499122177
#define int long long
using namespace std;
const int mod=998244353;
int n,k,pian,x,y,z;
void FWT(int *a,int kp){
    for(register int p=2,q=1;p<=(1<<k);p<<=1,q<<=1){
        for(register int i=0;i<(1<<k);i+=p){
            for(register int j=0;j<q;j++){
                int x=a[i+j],y=a[i+j+q];
                if(kp==1){
                    a[i+j]=x+y;
                    a[i+j+q]=x-y;
                }
                else{
                    a[i+j]=1ll*(x+y)*kp%mod;
                    a[i+j+q]=1ll*(x-y+mod)*kp%mod;
                }
            }
        }
    }
}
long long pw(long long x,int k){
    long long ans=1;
    while(k){
        if(k&1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        k/=2;
    }
    return ans;
}
struct node{
    int a,b,c;
}p[100010];
int num1[200010],num2[200010],num3[200010],ans[200010];
signed main(){
    scanf("%lld %lld",&n,&k);
    scanf("%lld %lld %lld",&x,&y,&z);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld %lld",&p[i].a,&p[i].b,&p[i].c);
        pian^=p[i].a;
        p[i].b^=p[i].a;
        p[i].c^=p[i].a;
        num1[p[i].b]++;
        num2[p[i].c]++;
        num3[p[i].b^p[i].c]++;
    } 
    FWT(num1,1);
    FWT(num2,1);
    FWT(num3,1);
    // for(int i=0;i<(1<<k);i++) printf("%lld ",num1[i]);
    // printf("\n");
    // for(int i=0;i<(1<<k);i++) printf("%lld ",num2[i]);
    // printf("\n");
    // for(int i=0;i<(1<<k);i++) printf("%lld ",num3[i]);
    // printf("\n");
    for(int i=0;i<(1<<k);i++){
        int tmp=(num1[i]+num2[i]+num3[i]+n)/4;
        ans[i]=pw((x+y+z)%mod,tmp)*pw((x+y-z+mod)%mod,(num1[i]+n-2*tmp)/2)%mod*pw((x-y+z+mod)%mod,(num2[i]+n-2*tmp)/2)%mod*pw((x-y-z+mod)%mod,(num3[i]+n-2*tmp)/2)%mod;
    }
    FWT(ans,n2);
    for(int i=0;i<(1<<k);i++) printf("%lld ",ans[i^pian]);
}