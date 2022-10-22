#include<bits/stdc++.h>
using namespace std;
int n,k,a[1010],f[1000010];
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=1000005;i++) f[i]=1e9;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int minn=a[1];
    for(int i=1;i<=n;i++) a[i]-=minn;
    for(int i=2;i<=n;i++){
        for(int j=a[i];j<=1000005;j++){
            f[j]=min(f[j],f[j-a[i]]+1);
        }
    }
    for(int i=0;i<=1000005;i++){
        if(f[i]<=k) printf("%d ",i+k*minn);
    }
}