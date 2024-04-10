#include <stdio.h>
int main(){
    char c[55],a=0,b=0;
    scanf("%s",c);
    for(int i=0;;i++){
        if(c[i]=='4')a++;
        if(c[i]=='7')b++;
        if(c[i]=='\0')break;
    }
    if(a||b)printf("%d",b>a?7:4);
    else printf("-1");
}