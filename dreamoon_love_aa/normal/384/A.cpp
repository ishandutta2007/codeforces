#include<cstdio>
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",(n*n+1)/2);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%c",(i+j)%2?'.':'C');
        puts("");
    }
    return 0;
}