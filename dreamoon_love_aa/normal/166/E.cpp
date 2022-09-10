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
#define MOD 1000000007
using namespace std;
long long A[32][2][2],a[32][2];
int main(){
    int i,j,k,n,now=0;
    scanf("%d",&n);
    A[0][0][1]=1;
    A[0][1][1]=2;
    A[0][1][0]=3;
    a[0][0]=1;
    while(n){
        if(n&1){
            for(i=0;i<2;i++)
                for(j=0;j<2;j++){
                    a[now+1][i]+=A[now][i][j]*a[now][j];
                    a[now+1][i]%=MOD;
                }
        }
        else for(i=0;i<2;i++)a[now+1][i]=a[now][i];
        n>>=1;
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                for(k=0;k<2;k++){
                    A[now+1][i][k]+=A[now][i][j]*A[now][j][k];
                    A[now+1][i][k]%=MOD;
                }
        now++;
    }
    cout<<a[now][0];
    return 0;
}