#include<stdio.h>
#define L long long
const int p=1e9+7;
L f[100001][3],F[100001];
int main(){
	int n,m,x;
    scanf("%d%d",&n,&m);
    f[1][0]=f[1][1]=1;
    f[2][0]=f[2][1]=2;
    F[1]=2;
	F[2]=4;
	x=n>m?n:m;
    for(register int i=3;i<=x;i++){
        f[i][1]=(f[i-1][0]+f[i-2][0])%p;
        f[i][0]=(f[i-1][1]+f[i-2][1])%p;
        F[i]=(f[i][0]+f[i][1])%p;
    }
    printf("%lld",(F[n]+F[m]-2+p)%p);
    return 0;
}