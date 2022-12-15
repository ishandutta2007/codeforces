#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
char s[405],t[405];
char t1[405],t2[405];
int dp[405][405];
int nxt[405][26];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        scanf("%s",s+1);
        scanf("%s",t+1);
        int ls=strlen(s+1),lt=strlen(t+1);
        for(int i=0;i<26;i++) nxt[ls+1][i]=nxt[ls+2][i]=ls+1;
        for(int i=ls;i>=1;i--){
            for(int j=0;j<26;j++) nxt[i][j]=nxt[i+1][j];
            nxt[i][s[i]-'a']=i;
        }
        /*
        for(int i=1;i<=ls;i++,puts(""))
            for(int j=0;j<4;j++)
                printf("%d ",nxt[i][j]);
                */
        int fl=0;
        for(int i=1;i<=lt;i++){
            int l1=0,l2=0;
            for(int j=1;j<=i;j++) t1[++l1]=t[j];
            for(int j=i+1;j<=lt;j++) t2[++l2]=t[j];
            //for(int j=1;j<=l1;j++) printf("%c",t1[j]);puts("");
            //for(int j=1;j<=l2;j++) printf("%c",t2[j]);puts("");
            for(int j=0;j<=l1;j++)
                for(int k=0;k<=l2;k++){
                    if(j==0&&k==0) dp[j][k]=0;
                    else if(j==0) dp[j][k]=nxt[dp[j][k-1]+1][t2[k]-'a'];
                    else if(k==0) dp[j][k]=nxt[dp[j-1][k]+1][t1[j]-'a'];
                    else dp[j][k]=min(nxt[dp[j][k-1]+1][t2[k]-'a'],nxt[dp[j-1][k]+1][t1[j]-'a']);
                    //cout<<dp[j][k]<<" "<<j<<" "<<k<<endl;
                }
            //cout<<dp[l1][l2]<<endl;
            if(dp[l1][l2]<=ls) fl=1;
        }
        puts(fl?"YES":"NO");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp