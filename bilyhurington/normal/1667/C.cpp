#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    if(n==3){
        puts("2\n1 1\n2 2");
        return 0;
    }int ans;
    for(ans=1;ans<=n;ans++){
        if(ans&1){
            int x=ans/2;
            if(x&1){
                if(((n-ans)+1)/2*2-1<=x&&(n-ans)/2*2<=x+1) break;
            }else{
                if((n-ans)/2*2<=x&&((n-ans)+1)/2*2-1<=x+1) break;
            }
        }else{
            int x=ans/2-1;
            if(x&1){
                if(((n-ans+1)+1)/2*2-1<=x+2&&(n-ans+1)/2*2<=x+1) break;
            }else{
                if((n-ans+1)/2*2<=x+2&&((n-ans+1)+1)/2*2-1<=x+1) break;
            }
        }
    }
    if(ans&1){
        int x=ans/2;
        printf("%d\n",ans);
        for(int i=1;i<=x;i++) printf("%d %d\n",i,x+1-i);
        for(int i=1;i<=x+1;i++) printf("%d %d\n",n+1-i,n+1-(x+2-i));
    }else{
        int x=ans/2-1;
        printf("%d\n",ans);
        for(int i=1;i<=x;i++) printf("%d %d\n",i,x+1-i);
        for(int i=1;i<=x+1;i++) printf("%d %d\n",n+1-i,n+1-(x+2-i));
        printf("%d %d\n",x+1,x+1);
    }
    return 0;
}