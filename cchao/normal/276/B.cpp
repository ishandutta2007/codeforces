#include <cstdio>
#include <cstring>
int f(char *s){
    int cnt[128]={0}, tmp = 0;
    for(int i = 0; i < strlen(s); ++i)
        cnt[s[i]]++;
    for(int i = 0; i < 128; ++i)
        if(cnt[i]&1) tmp++;
    return tmp<=1 ? 1 : 0;
}
int main(){
    char s[1010];
    scanf("%s", s);
    if(f(s) || (strlen(s)&1)) puts("First");
    else puts("Second");
    return 0;
}