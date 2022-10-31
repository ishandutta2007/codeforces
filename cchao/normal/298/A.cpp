#include <cstdio>
#include <cstring>

int main(){
    int n;
    char s[1010];
    scanf("%d%s", &n, s);
    if(strchr(s,'R')!=NULL) printf("%d %d\n", strchr(s, 'R')-s+1, strrchr(s, 'R')-s+2);
    else printf("%d %d\n", strrchr(s, 'L')-s+1, strchr(s, 'L')-s);
    return 0;
}