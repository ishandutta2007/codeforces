#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <map>

using namespace std;

int gcd(int a,int b) {return b==0 ? a : gcd(b,a%b);}

char str[500002];
int dp[500002][26];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k;
    scanf("%d%d\n",&n,&k);
    gets(str);
    int l=strlen(str);
    for(int i=1;i<=l;++i) {
        int mn1[27]={0},mn2[27]={0};
        mn1[0]=dp[i-1][0];
        for(int j=1;j<k;++j)
            mn1[j]=min(mn1[j-1],dp[i-1][j]);
        mn2[k-1]=dp[i-1][k-1];
        for(int j=k-2;j>=0;--j)
            mn2[j]=min(mn2[j+1],dp[i-1][j]);
        for(int j=0;j<k;++j) {
            dp[i][j]=((str[i-1]-'A')!=j)+min((j<(k-1) ? mn2[j+1] : 2000000000),(j>0 ? mn1[j-1] : 2000000000));
        }
    }
    int cur=0,cnt=0;
    for(int j=0;j<k;++j)
        if (dp[l][j]<dp[l][cur]) cur=j;
    if (str[l-1]!='A'+cur) ++cnt;
    str[l-1]='A'+cur;
    for(int i=l-1;i>0;--i) {
        int mn=cur==0 ? 1 : 0;
        for(int j=0;j<k;++j) {
            if (j==cur) continue;
            if (dp[i][j]<dp[i][mn]) mn=j;
        }
        cur=mn;
        if (str[i-1]!='A'+cur) ++cnt;
        str[i-1]='A'+cur;
    }
    printf("%d\n",cnt);
    puts(str);
    return 0;
}