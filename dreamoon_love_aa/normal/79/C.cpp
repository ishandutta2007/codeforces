#include<stdio.h>
#include<algorithm>
#include<string.h>
bool used[100010];
char s[100010];
int d[100010];
main(){
    int n,len,len2,i,j,an1=0,an2=0,m=0;
    char s2[16];
    gets(s);
    len=strlen(s);
    scanf("%d",&n);
    gets(s2);
    while(n--){
        gets(s2);
        len2=strlen(s2);
        for(i=0;i+len2<=len;i++){
            if(strncmp(s+i,s2,len2)==0){
                if(d[i+len2-1]==0||d[i+len2-1]>len2){
                    d[i+len2-1]=len2;
                }
            }
        }
    }
    int left,right;
    for(left=right=0;left<len;left++){
        while(right<len){
            if(d[right]==0||right-d[right]<left-1)right++;
            else break;
        }
        if(right-left>an1){
            an1=right-left;
            an2=left;
        }
    }
    printf("%d %d\n",an1,an2);
}