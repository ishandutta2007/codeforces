#include<stdio.h>
#include<iostream>
using namespace std;
long long dp[10][64];
int abs(int x){return x<0?-x:x;}
main(){
    long long an=0;
    int x,i,j;
    char s[64];
    gets(s);
    for(i=0;i<10;i++)dp[i][0]=1;
    for(i=0;s[i+1];i++){
        x=s[i+1]-'0';
        for(j=0;j<10;j++){
            if((j+x)&1){
                dp[(j+x+1)/2][i+1]+=dp[j][i];
                dp[(j+x)/2][i+1]+=dp[j][i];
            }
            else{
                dp[(j+x)/2][i+1]+=dp[j][i];
            }
        }
    }
    for(j=0;j<10;j++)an+=dp[j][i];
    for(i=0;s[i+1];i++){
        if(abs(s[i]-s[i+1])>1)break;
    }
    if(!s[i+1])an--;
    cout<<an<<endl;
}