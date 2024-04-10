#include <cstdio>
#include <cstring>
char s[100];

int f() {
    if(s[0]!='1') return 0;
    for(int i = 0; s[i]; ++i)
        if(s[i] != '1' && s[i] != '4') return 0;
    if(strstr(s, "444")) return 0;
    return 1;
}

int main() {
    scanf("%s", s);
    puts(f() ? "YES" : "NO");
    return 0;
}