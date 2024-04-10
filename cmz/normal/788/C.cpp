#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int k,n,top;
int a[maxn];
int f1[maxn],f2[maxn];
bool judge[maxn];
int main(){
    scanf("%d%d",&k,&n);
    for (int i=1,x;i<=n;++i){
        scanf("%d",&x);
        if (judge[x]) continue;
        judge[x]=1; a[++top]=x-k;
        if (x==k){
            printf("1");
            return 0;
        }
    }
    memset(f1,0x3f,sizeof(f1)); memset(f2,0x3f,sizeof(f2)); 
    f1[0]=f2[0]=0;
    for (int i=1;i<=top;++i){
        if (a[i]>0){
            for (int j=a[i];j<=1000000;++j) f1[j]=min(f1[j-a[i]]+1,f1[j]);
        } else {
            a[i]=-a[i];
            for (int j=a[i];j<=1000000;++j) f2[j]=min(f2[j-a[i]]+1,f2[j]);
        }
    }
    int ans=(1<<30);
    for (int i=0;i<=1000000;++i) {
        if (f1[i]>1000000||f2[i]>1000000) continue;
        if (f1[i]+f2[i]<=0) continue;
        ans=min(ans,f1[i]+f2[i]);
    }
    printf("%d",(ans==(1<<30))?-1:ans);
    return 0;
}