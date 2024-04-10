#include<cstdio>
int main(){
    int n,m,an;
    scanf("%d%d",&n,&m);
    if(m-1>=n-m)an=m-1;
    else an=m+1;
    if(n==1)an=n;
    printf("%d",an);
    return 0;
}