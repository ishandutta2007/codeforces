#include <cstdio>
#include <cstring>
#define M 1000010
char a[M], b[M];
int main(){
    scanf("%s%s", a, b);
    int la = strlen(a), lb = strlen(b);
    if(strcmp(a,b)==0 || (la==lb && strchr(a,'1') && strchr(b,'1')))
        puts("YES");
    else puts("NO");
    return 0;
}