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
int dp[5010],d[5010],tt;
int go(int x){
    tt++;
    int i;
    d[dp[x-2]]=tt;
    for(i=2;i<x;i++)d[dp[i-2]^dp[x-i-1]]=tt;
    i=0;
    while(d[i]==tt)i++;
    return i;
}
int get(char s[]){
    int i,j;
    int res=0;
    for(i=0;s[i];){
        if(!i||!s[i+1]){
            i++;
            continue;
        }
        for(j=i;s[j-1]==s[j+1];j++);
        res^=dp[j-i];
        if(i==j)i++;
        else i=j;
    }
    return res;
}
int main(){
    char s[5010];
    int i,j,k,n;
    dp[1]=1;
    for(i=2;i<5000;i++){
        dp[i]=go(i);
    }
    scanf("%s",s);
    int res=get(s);
    if(res){
        puts("First");
        for(i=1;s[i];i++){
            if(s[i-1]!=s[i+1])continue;
            char c=s[i];
            s[i]=0;
            if(!(get(s)^get(s+i+1))){
                printf("%d\n",i+1);
                break;
            }
            s[i]=c;
        }
    }
    else{
        puts("Second");
    }
    return 0;
}