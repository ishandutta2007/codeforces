#include<cstdio>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ",j*n+(i+j)%n+1);
        puts("");
    }
}