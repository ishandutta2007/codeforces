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
char s[200000];
int stack[200000],sn,an1=-1,an2=-1,idx[200000],ma=-1,dp[200000],last[200000];
int f(int x,int y){
    if(x==0)return dp[y];
    return dp[y]-dp[x-1];
}
int main(){
    int i,j,k,n;
    memset(last,-1,sizeof(last));
    scanf("%s",s);
    dp[0]=(s[0]=='[');
    for(i=1;s[i];i++){
        dp[i]=dp[i-1]+(s[i]=='[');
    }
    for(i=0;s[i];i++){
        if(s[i]=='['){
            idx[sn]=i;
            stack[sn++]=1;
        }
        else if(s[i]=='('){
            idx[sn]=i;
            stack[sn++]=0;
        }
        else if(s[i]==']'){
            if(sn&&stack[sn-1]==1){
                int ll;
                if(idx[sn-1]&&last[idx[sn-1]-1]!=-1)ll=last[idx[sn-1]-1];
                else ll=idx[sn-1];
                last[i]=ll;
                if(f(ll,i)>ma){
                    ma=f(ll,i);
                    an1=ll,an2=i;
                }
                sn--;
            }
            else sn=0;
        }
        else if(s[i]==')'){
            if(sn&&stack[sn-1]==0){
                int ll;
                if(idx[sn-1]&&last[idx[sn-1]-1]!=-1)ll=last[idx[sn-1]-1];
                else ll=idx[sn-1];
                last[i]=ll;
                if(f(ll,i)>ma){
                    ma=f(ll,i);
                    an1=ll,an2=i;
                }
                sn--;
            }
            else sn=0;
        }
        else puts("error");
    }
    if(ma==-1){
        puts("0");
        return 0;
    }
    s[an2+1]=0;
    printf("%d\n%s\n",ma,s+an1);
    return 0;
}