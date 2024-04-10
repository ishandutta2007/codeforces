#include <cstdio>
#include <cstring>

int main()
{
    char c, s[5] = "HQ9";
    int r = 0;
    while((c = getchar()) != EOF)
    {
        if(strchr(s,c)) r = 1;
    }
    puts(r? "YES" : "NO");
    return 0;
}