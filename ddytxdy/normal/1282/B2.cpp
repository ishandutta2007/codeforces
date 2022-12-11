#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int t,n,p,k,a[N],ans;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&p,&k);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+1,a+n+1);ans=0;
        for(int i=0,now=0;i<k;i++){
            now+=a[i];if(now>p)break;ans=max(ans,i);
            for(int j=k,dat=0;j+i<=n;j+=k){
                dat+=a[i+j];if(dat+now>p)break;
                ans=max(ans,i+j);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}