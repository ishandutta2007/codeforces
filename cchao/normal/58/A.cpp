#include <cstring>
#include <cstdio>
int check(char *s)
{
    char check[10] = "hello";
    char *c = s;
    for(int k = 0;k < 5; k++)
    {
        c = strchr(c,check[k]);
        if(c == NULL) return 0;
        else c++;
    }
    return 1;
}
int main()
{
    char s[200];
    scanf("%s",s);
    if(check(s)) puts("YES");
    else puts("NO");
    return 0;
}