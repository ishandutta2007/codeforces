#include<stdio.h>
#include<string.h>
int main(){
    char s[100005];
    scanf("%s",s);
    int n=strlen(s),k=s[n-1]-'0',t=-1,j,i;
    for(i=0;i<n;i++){
        int r=s[i]-'0';
        if(r%2)continue;
        t=r;j=i;
        if(r<k){
            s[n-1]=r+'0';
            s[i]=k+'0';
            break;
        }
    }
    if(i==n){
        if(t==-1){printf("-1");return 0;}
        s[n-1]=t+'0';
        s[j]=k+'0';
    }
    printf("%s",s);
}