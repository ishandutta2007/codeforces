#include<stdio.h>
#include<string.h>
char s[12][19]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
main(){
    int n,i;
    char t[19];
    scanf("%s%d",t,&n);
    for(i=0;strcmp(s[i],t);i++);
    printf("%s\n",s[(i+n)%12]);
}