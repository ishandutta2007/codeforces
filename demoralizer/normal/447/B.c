#include<stdio.h>
#include<string.h>
int main(){
    char s[1005];int k;
    scanf("%s\n%d",s,&k);
    int w[26],n=strlen(s),m=0,t=0;
    for(int i=0;i<26;i++){
        scanf("%d",&w[i]);
        if(w[i]>m)m=w[i];
    }
    for(int i=0;i<n;i++)
        t+=w[s[i]-'a']*(i+1);
    for(int i=0;i<k;i++) t+=(n+i+1)*m;
    printf("%d",t);
}