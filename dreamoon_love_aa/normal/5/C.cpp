#include<stdio.h>
char s[1000100];
int d[1000100],dp[1000100];
main(){
    int i,an=0,an2=1,m=0;
    scanf("%s",s+1);
    for(i=1;s[i];i++){
        if(s[i]=='(')d[m++]=i;
        else{
            if(m){
                m--;
                dp[i]=i-d[m]+dp[d[m]-1]+1;
                if(dp[i]>an){
                    an=dp[i];
                    an2=1;
                }
                else if(dp[i]==an)an2++;
            }
            else m=0;
        }
    }
    printf("%d %d\n",an,an2);
}