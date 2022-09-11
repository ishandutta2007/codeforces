#include<stdio.h>
char s[8][256][256];
int pow(int x,int y){
    int an=1;
    while(y){
        if(y&1)
            an*=x;
        x*=x;
        y>>=1;
    }
    return an;
}
void Go(int x,int n){
    int i,j,k,kk,l=pow(n,x);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            if(s[0][i][j]=='*'){
                for(k=0;k<l;k++)
                    for(kk=0;kk<l;kk++)
                        s[x][i*l+k][j*l+kk]='*';
            }
            else{
                for(k=0;k<l;k++)
                    for(kk=0;kk<l;kk++)
                        s[x][i*l+k][j*l+kk]=s[x-1][k][kk];
            }
        }
}
main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k,l,i;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%s",s[0][i]);
    for(i=1;i<k;i++)Go(i,n);
    l=pow(n,k);
    for(i=0;i<l;i++)puts(s[k-1][i]);
}