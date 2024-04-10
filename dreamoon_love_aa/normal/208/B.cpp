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
int a[52];
bool dp[52][1<<18];
int ch(char c){
    if(c=='S')return 0;
    if(c=='D')return 1;
    if(c=='H')return 2;
    return 3;
}
bool same(int x,int y){
    return x%4==y%4||x/4==y/4;
}
int f(int x){
    if(x>=0)return a[x];
    return 0;
}
int di(char c){
    if(c>='2'&&c<='9')return c-'0';
    if(c=='A')return 1;
    if(c=='T')return 10;
    if(c=='J')return 11;
    if(c=='Q')return 12;
    return 13;
}
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        char c[4];
        scanf("%s",c);
        a[i]=di(c[0])*4+ch(c[1]);
    }
    if(n==1){
        puts("YES");
        return 0;
    }
    if(n==2){
        if((a[0]&3)==(a[1]&3)||(a[0]>>2)==(a[1]>>2))puts("YES");
        else puts("NO");
        return 0;
    }
    dp[n-1][a[n-1]|(a[n-2]<<6)|(a[n-3]<<12)]=1;
    for(i=n-1;i>0;i--){
        for(j=0;j<(1<<18);j++){
            if(dp[i][j]){
                if(same(j&63,(j>>6)&63))dp[i-1][((j>>12)<<6)|(j&63)|(f(i-3)<<12)]=1;
                if(i>=3&&same(j&63,f(i-3)))dp[i-1][(j>>6)|((j&63)<<12)]=1;
            }
        }
    }
    for(i=0;i<(1<<18);i++)
        if(dp[0][i])break;
    if(i<(1<<18))puts("YES");
    else puts("NO");
    return 0;
}