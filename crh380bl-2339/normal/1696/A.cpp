#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,z,i,x;
    scanf("%d",&t);
    while(t--){
        int ans=0;
        scanf("%d%d",&n,&z);
        for(i=1;i<=n;++i){
            scanf("%d",&x);
            ans=max(ans,z|x);
        }
        printf("%d\n",ans);
    }
    return 0;
}