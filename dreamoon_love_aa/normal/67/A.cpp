#include<stdio.h>
char s[1024];
int an[1024],bfs[1024],used[1024];
int max(int x,int y){return x>y?x:y;}
main(){
    int n,i,j,k;
    scanf("%d%s",&n,s);
    an[0]=1;
    for(i=1;i<n;i++){
        if(s[i-1]=='R')an[i]=an[i-1]+1;
        else if(s[i-1]=='=')an[i]=an[i-1];
        else an[i]=1;
    }
    for(i=n-2;i>=0;i--){
        if(s[i]=='L')an[i]=max(an[i],an[i+1]+1);
        else if(s[i]=='=')an[i]=an[i+1];
    }
    for(i=0;i<n;i++){
        if(i)putchar(' ');
        printf("%d",an[i]);
    }
    puts("");
}