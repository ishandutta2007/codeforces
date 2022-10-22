#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int T,n,s,k,a[1010];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&n,&s,&k);
        for(int i=1;i<=k;i++) scanf("%d",&a[i]);
        sort(a+1,a+k+1);
        a[k+1]=n+1;
        int ans=2e9;
        bool pd=0;
        for(int i=1;i<=k;i++){
            if(a[i]==s) pd=1;
            if(a[i-1]!=a[i]-1){
                ans=min(ans,abs((a[i]-1)-s));
            }
            if(a[i+1]!=a[i]+1){
                ans=min(ans,abs((a[i]+1)-s));
            }
        }
        if(!pd) ans=0;
        printf("%d\n",ans);
    }
}