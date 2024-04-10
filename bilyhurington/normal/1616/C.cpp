#include<bits/stdc++.h>
using namespace std;
int T,n,a[110];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }int ans=2e9;
        if(n==1){puts("0");continue;}
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int cnt=0;
                for(int k=1;k<=n;k++){
                    double x=a[i]+1.0*(a[j]-a[i])/(j-i)*(k-i);
                    // printf("%d %d %d %lf\n",i,j,k,x);
                    if(abs(x-a[k])<1e-8) cnt++;
                }ans=min(ans,n-cnt);
                // printf("%d\n",cnt);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}