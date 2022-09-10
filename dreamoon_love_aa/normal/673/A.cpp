#include<cstdio>
main(){
    int n;
    scanf("%d",&n);
    int an=15;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x>an)break;
        an=x+15;
     
    }
    if(an>90)an=90;
    printf("%d",an);

}