/*
 * @Author: BilyHurington
 * @Date: 2020-09-30 22:35:03
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-09-30 23:22:44
 */ 
#include<bits/stdc++.h>
using namespace std;
int T,n,l,a[100010];
double t1[100010],t2[100010];
void solve(){
    scanf("%d %d",&n,&l);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);a[n+1]=l;
    for(int i=0;i<=n;i++) t1[i+1]=1.0*(a[i+1]-a[i])/(i+1);t1[0]=0;
    for(int i=1;i<=n+1;i++) t1[i]+=t1[i-1];
    for(int i=0;i<=n;i++) t2[i]=1.0*(a[i+1]-a[i])/(n+1-i);t2[n+1]=0;
    for(int i=n;i>=0;i--) t2[i]+=t2[i+1];
    // for(int i=0;i<=n+1;i++) printf("%.10lf ",t1[i]);printf("\n");
    // for(int i=0;i<=n+1;i++) printf("%.10lf ",t2[i]);printf("\n");
    for(int i=0;i<=n;i++){
        if(t1[i+1]>=t2[i+1]&&t1[i]<=t2[i]){
            double t=max(t2[i+1],t1[i]),d;
            if(t2[i+1]>t1[i]) d=a[i+1]-a[i]-(i+1)*(t2[i+1]-t1[i]);
            else d=a[i+1]-a[i]-(n+1-i)*(t1[i]-t2[i+1]);
            // printf("%.10lf\n",d);
            printf("%.10lf\n",t+d/(n+2));
            return;
        }
    }
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}