#include<cstdio>
int main(){
    int n,an=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        an+=(c-a+1)*(d-b+1);
    }
    printf("%d\n",an);
    return 0;
}