#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
long long C[64][64];
int main(){
    int i,j,k,n,m,t;
    long long an=0;
    for(i=0;i<32;i++){
        C[i][0]=1;
        for(j=1;j<=i;j++)C[i][j]+=C[i-1][j-1]+C[i-1][j];
    }
    scanf("%d%d%d",&n,&m,&t);
    for(i=4;i<t;i++)
        an+=C[n][i]*C[m][t-i];
    cout<<an<<endl;
    return 0;
}