#include<stdio.h>
#include<string.h>
char s[1024];
int d[1024],n;
main(){
    scanf("%s",s);
    int i,l=strlen(s);
    for(i=0;i<l;i++)
        if(s[i]=='@')d[n++]=i;
    for(i=1;i<n;i++)
        if(d[i]-d[i-1]<3)break;
    if(n==0||i<n||d[0]<1||d[n-1]+1==l)puts("No solution");
    else{
        i=0;
        int j;
        for(j=0;j<n;j++){
            while(i<=d[j]+1){
                putchar(s[i]);
                i++;
            }
            if(j!=n-1)putchar(',');
        }
        while(i<l)putchar(s[i++]);
        puts("");
    }
}