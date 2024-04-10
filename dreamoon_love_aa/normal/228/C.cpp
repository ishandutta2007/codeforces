#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
char s[512][512];
int d[10][512][512];
int c(char cc){
    if(cc=='*')return 1;
    return 0;
}
int main(){
    int i,j,k,n,m,an=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i+1<n;i++)
        for(j=0;j+1<m;j++)
            d[1][i][j]=c(s[i][j])|(c(s[i][j+1])<<1)|(c(s[i+1][j])<<2)|(c(s[i+1][j+1])<<3);
    for(k=2;k<10;k++){
        for(i=0;i+(1<<k)<=n;i++)
            for(j=0;j+(1<<k)<=m;j++){
                d[k][i][j]=-1;
                int offset=1<<(k-1);
                int dd[4]={d[k-1][i][j],d[k-1][i][j+offset],d[k-1][i+offset][j],d[k-1][i+offset][j+offset]};
                for(int kk=0;kk<16;kk++){
                    int ii;
                    for(ii=0;ii<4;ii++){
                        if((kk>>ii)&1){
                            if(dd[ii]!=15)break;
                        }
                        else{
                            if(dd[ii]!=kk)break;
                        }
                    }
                    if(ii==4){
                        an++;
                        d[k][i][j]=kk;
                        break;
                    }
                }
            }
    }
    printf("%d\n",an);
    return 0;
}