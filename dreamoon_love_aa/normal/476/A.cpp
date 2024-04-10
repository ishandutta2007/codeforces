#include<cstdio>
int main(){
    int n,m,an=-1;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++){
        if((n-i)%2==0&&(i+(n-i)/2)%m==0){
            if(an==-1||an>i+(n-i)/2)an=i+(n-i)/2;
        }
    }
    printf("%d\n",an);
}