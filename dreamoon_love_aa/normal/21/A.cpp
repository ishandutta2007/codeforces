#include<stdio.h>
char s[999];
char valid(char c){
    if(c>='0'&&c<='9')return 1;
    if(c>='a'&&c<='z')return 1;
    if(c>='A'&&c<='Z')return 1;
    if(c=='_')return 1;
    return 0;
}
int main(){
    int i=0,j=0,k;
    gets(s);
    for(i=0;valid(s[i]);i++);
    if(s[i]!='@'||i==0||i>16)puts("NO");
    else{
        i++;
        for(j=i;valid(s[j])||s[j]=='.';j++);
        if(j-i==0||j-i>32)
            puts("NO");
        else{
            for(k=i;k<j;k=i){
                while(k<j&&valid(s[k]))k++;
                if(k-i==0||k-i>16){
                    puts("NO");
                    return 0;
                }
                i=k+1;
                if(s[i-1]=='.'&&i>=j){
                    puts("NO");
                    return 0;
                }
            }
            if(!s[j]){
                puts("YES");
                return 0;
            }
            if(s[j]!='/')puts("NO");
            else{
                for(k=j+1;valid(s[k]);k++);
                if(s[k]||k-j-1>16||k==j+1)puts("NO");
                else puts("YES");
            }
        }
    }
    return 0;
}