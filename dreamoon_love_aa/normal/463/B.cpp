#include<cstdio>
int main(){
    int n;
    int now=0,e=0,an=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x>now){
            e-=x-now;
            if(e<0){
                an-=e;
                e=0;
            }
        }
        else{
            e+=now-x;
        }
        now=x;
    }
    printf("%d\n",an);
    return 0;
}