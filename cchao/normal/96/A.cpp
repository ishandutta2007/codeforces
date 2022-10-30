#include <cstdio>
#include <cstring>
int main()
{
    char s[200];
    scanf("%s",s);
    puts(strstr(s,"1111111") || strstr(s,"0000000") ? "YES" : "NO");
    return 0;
}