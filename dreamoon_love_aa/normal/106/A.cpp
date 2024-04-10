#include<stdio.h>
int f(char c){
    if(c>='0'&&c<='9')return c-'0';
    if(c=='T')return 10;
    if(c=='J')return 11;
    if(c=='Q')return 12;
    if(c=='K')return 13;
    if(c=='A')return 14;
}
int main(){
    char s1[8],s2[8],s3[8];
    scanf("%s%s%s",s1,s2,s3);
    if(s2[1]==s1[0]){
        if(s3[1]!=s1[0]){
            puts("YES");
            return 0;
        }
        else{
            if(f(s2[0])>f(s3[0]))puts("YES");
            else puts("NO");
        }
    }
    else{
        if(s2[1]!=s3[1])puts("NO");
        else{
            if(f(s2[0])>f(s3[0]))puts("YES");
            else puts("NO");
        }
    }
    return 0;
}