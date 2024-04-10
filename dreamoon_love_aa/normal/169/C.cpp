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
#define SIZE 5100
#define MOD 1000000007
char s[SIZE],t[SIZE];
long long dp[SIZE][SIZE];
inline int to(char c){return c-'a';}
int main(){
    int an=0;
    int i,j,k,n,sl,tl;
    scanf("%s%s",s+1,t+1);
    sl=strlen(s+1);
    tl=strlen(t+1);
    for(i=1;i<=sl;i++){
        for(j=1;j<=tl;j++){
            if(s[i]==t[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                an+=dp[i][j];
                an%=MOD;
            }
            dp[i][j]+=dp[i][j-1];
            dp[i][j]%=MOD;
        }
    }
    cout<<an<<endl;
    return 0;
}