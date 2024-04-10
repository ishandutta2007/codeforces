#include <cstdio>
#include <cstring>
#include <iostream>
#define Mod 1000000007
char s[110];
int main() {
    scanf("%s", s);
    long long ans = 0, tmp = 1;
    for(int i = strlen(s) - 1; i >= 0; --i) {
        ans = ((ans*2 % Mod) + (s[i]=='1'?1:0)*(tmp)) % Mod;
        tmp = (tmp * 4) % Mod;
    }
    std::cout << ans << std::endl;
    return 0;
}