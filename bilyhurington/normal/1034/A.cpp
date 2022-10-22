#include<bits/stdc++.h>
using namespace std;
int n,num[15000010],a[300010];
bool pd[15000010];
int gcd(int x,int y){
    if(x%y==0) return y;
    return gcd(y,x%y);
}
int main(){
    scanf("%d",&n);
    int gc=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(!gc) gc=a[i];
        else gc=gcd(gc,a[i]);
    }
    bool pd1=1;
    for(int i=1;i<=n;i++){
        a[i]/=gc;
        if(a[i]!=1) pd1=0;
        num[a[i]]++;
    }
    if(pd1){
        printf("-1");
        return 0;
    }
    int ans=0,sum;
    for(int i=2;i<=15000000;i++){
        if(!pd[i]){
            sum=0;
            for(int j=i;j<=15000000;j+=i){
                sum+=num[j];
                pd[j]=1;
            }
            // if(sum>ans){
            //     printf("%d\n",i);
            // }
            ans=max(sum,ans);
        }
    }
    printf("%d",n-ans);
}