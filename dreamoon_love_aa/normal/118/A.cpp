#include<stdio.h>
char s[1024];
bool big(char c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y';
}
main(){
    int i;
    gets(s);
    for(i=0;s[i];i++){
        if(s[i]>='A'&&s[i]<='Z')s[i]-='A'-'a';
        if(!big(s[i])){
            printf(".%c",s[i]);
        }
    }
    puts("");
}