#include<cstdio>
main(){
    int n,h,an=0;
    scanf("%d",&n);
    scanf("%d",&h);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        an+=1+(x>h);
    }
    printf("%d",an);
}