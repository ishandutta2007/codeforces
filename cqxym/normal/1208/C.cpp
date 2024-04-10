#include<cstdio>
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        	printf("%d ",(i/4*(n/4)+j/4)*16+i%4*4+j%4);
        }
        puts("");
    }
    return 0;
}