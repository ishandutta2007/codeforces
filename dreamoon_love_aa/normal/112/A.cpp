#include<stdio.h>
char s1[128],s2[138];
void To(char s[]){
    int i;
    for(i=0;s[i];i++){
        if(s[i]>='A'&&s[i]<='Z')s[i]-='A'-'a';
    }
}
main(){
    int i;
    scanf("%s%s",s1,s2);
    To(s1);
    To(s2);
    for(i=0;s1[i];i++){
        if(s1[i]!=s2[i])break;
    }
    if(s1[i]==s2[i])puts("0");
    else if(s1[i]<s2[i])puts("-1");
    else puts("1");
}