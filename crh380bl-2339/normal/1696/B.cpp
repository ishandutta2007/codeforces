#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,z,i,x;
    scanf("%d",&t);
    while(t--){
        int ans=0;
        bool flag=0;
        scanf("%d",&n);
        for(i=1;i<=n;++i){
            scanf("%d",&x);
            if(x==0){
                flag=0; 
            }
            else{
                if(!flag){
                    ++ans;
                    flag=1;
                }
            }
        }
        printf("%d\n",min(ans,2));
    }
    return 0;
}