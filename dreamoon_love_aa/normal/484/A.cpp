#include<cstdio>
int get(long long x,int id){
    return (x>>id)&1;
}
int main(){
    long long x,y;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d%I64d",&x,&y);
        if(x==y){
            printf("%I64d\n",x);
            continue;
        }
        long long an;
        for(int i=60;i>=0;i--){
            if(get(x,i)!=get(y,i)){
                int tmp=0;
                for(int j=0;j<=i;j++)tmp+=get(y,j);
                if(tmp<=i){
                    an=(x^(x&((1LL<<i)-1)))|((1LL<<i)-1);
                }
                else{
                    an=y;
                }
                break;
            }
        }
        printf("%I64d\n",an);
    }
}