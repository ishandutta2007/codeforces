#include<stdio.h>
#include<string.h>
bool used[26];
main(){
    int n,i,j,l;
    char s[128];
    scanf("%d",&n);
    scanf("%s",s);
    l=strlen(s);
    for(i=0;i+i<l-1;i++){
        if(s[i]=='?')s[i]=s[l-1-i];
        else{
            if(s[l-1-i]=='?')s[l-1-i]=s[i];
            else if(s[i]!=s[l-1-i])break;
        }
    }
    if(i+i<l-1)puts("IMPOSSIBLE");
    else{
        int x=0,r=0;
        for(i=0;i<l;i++)
            if(s[i]!='?')used[s[i]-'a']=1;
            else x++;
        for(i=0;i<n;i++)
            if(!used[i])r++;
        if(r>(x+1)/2)puts("IMPOSSIBLE");
        else{
            r=n-1;
            for(i=(l-1)/2;i>=0;i--){
                if(s[i]=='?'){
                    while(r>=0&&used[r])r--;
                    if(r<0)s[i]=s[l-1-i]='a';
                    else s[i]=s[l-1-i]=r+'a',used[r]=1;
                }
            }
            puts(s);
        }
    }
    scanf(" ");
}