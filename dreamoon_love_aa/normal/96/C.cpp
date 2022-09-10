#include<stdio.h>
#include<string.h>
bool big[128];
char stop[128][128];
char s[128],c[4];
bool used[128];
int l[128];
main(){
    int n,i,j,k,len;
    char next;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",stop[i]);
        l[i]=strlen(stop[i]);
        for(j=0;j<l[i];j++)
            if(stop[i][j]>='A'&&stop[i][j]<='Z')stop[i][j]-='A'-'a';
    }
    scanf("%s%s",s,c);
    if(c[0]=='a')next='b';
    else next='a';
    len=strlen(s);
    for(i=0;i<len;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            s[i]-='A'-'a';
            big[i]=1;
        }
    }
    for(i=0;i<n;i++)
        for(j=0;j+l[i]<=len;j++){
            for(k=0;k<l[i];k++)
                if(stop[i][k]!=s[j+k])break;
            if(k==l[i]){
                for(k=0;k<l[i];k++)used[j+k]=1;
            }
        }
    for(i=0;i<len;i++){
        if(used[i]){
            if(s[i]==c[0]){
                if(big[i])printf("%c",next+'A'-'a');
                else printf("%c",next);
            }
            else{
                if(big[i])printf("%c",c[0]+'A'-'a');
                else printf("%c",c[0]);
            }
        }
        else{
            if(big[i])printf("%c",s[i]+'A'-'a');
            else printf("%c",s[i]);
        }
    }
    puts("");
}