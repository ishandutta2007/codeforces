#include<cstdio>
int main(){
    long long an=0;
    int n;
    scanf("%d",&n);
    long long nine=9;
    int tt=1;
    while(n){
        long long r=n;
        if(r>nine)r=nine;
        nine*=10;
        an+=tt*r;
        n-=r;
        tt++;
    }
    printf("%I64d\n",an);
}