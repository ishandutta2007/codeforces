#include<cstdio>
int min(int x,int y){return x<y?x:y;}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int an=(n+m)/3;
    an=min(an,m);
    an=min(an,n);
    printf("%d\n",an);
    return 0;
}