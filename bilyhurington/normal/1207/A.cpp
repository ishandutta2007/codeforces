#include<cstdio>
#include<algorithm>
using namespace std;
int t,b,p,f,h,c;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d %d",&b,&p,&f,&h,&c);
        int ans=0;
        for(int i=0;i<=p;i++){
            for(int j=0;j<=f;j++){
                if(2*i+2*j<=b) ans=max(ans,i*h+j*c);
            }
        }
        printf("%d\n",ans);
    }
}