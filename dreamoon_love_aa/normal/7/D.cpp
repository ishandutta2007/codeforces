#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define SIZE 5000002
char s[SIZE+SIZE];
int dp[SIZE+SIZE];
void Z_Value(int len){
    int i,j,l,r=1;
    for(i=1;i<len;i++){
        j=(i<r)?min(dp[i-l],r-i):0;
        for(;i+j<len&&s[i+j]==s[j];j++);
        r=max(r,i+j);
        l=i;
        dp[i]=j;
    }
}
main(){
    int len,an=0,i;
    gets(s);
    len=strlen(s);
    for(i=0;i<len;i++)s[len+i]=s[len-1-i];
    Z_Value(len+len);
    for(dp[0]=0,i=1;i<=len;i++){
        if(dp[len+len-i]==i)an+=dp[i]=dp[i/2]+1;
        else dp[i]=0;
    }
    printf("%d\n",an);
}