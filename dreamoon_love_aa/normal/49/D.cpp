#include<stdio.h>
char s[1024];
main(){
    int n,i,k=0;
    scanf("%d",&n);
    scanf("%s",s);
    for(i=0;i<n;i++){
        if(i&1){
            if(s[i]=='0')k++;
        }
        else{
            if(s[i]=='1')k++;
        }
    }
    if(k<n-k)printf("%d\n",k);
    else printf("%d\n",n-k);
}