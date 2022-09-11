#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 5012
int back[SIZE],dp[SIZE];
struct data{
    int w,h,No;
    bool operator<(data b)const{
        return w<b.w;
    }
}a[SIZE];
void track(int x){
    if(back[x]!=-1)track(back[x]);
    if(back[x]!=-1)putchar(' ');
    printf("%d",a[x].No);
}
main(){
    int n,w,h,i,j,an=0;
    scanf("%d%d%d",&n,&w,&h);
    for(i=0;i<n;i++){
        scanf("%d%d",&a[i].w,&a[i].h);
        a[i].No=i+1;
    }
    sort(a,a+n);
    for(i=0;i<n;i++){
        if(a[i].w<=w||a[i].h<=h)dp[i]=0;
        else{
            dp[i]=1;
            back[i]=-1;
            for(j=0;j<i;j++){
                if(dp[j]==0)continue;
                if(a[j].w<a[i].w&&a[j].h<a[i].h&&dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    back[i]=j;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        if(dp[i]>an){
            an=dp[i];
            j=i;
        }
    }
    if(an==0)puts("0");
    else{
        printf("%d\n",an);
        track(j);
        puts("");
    }
}