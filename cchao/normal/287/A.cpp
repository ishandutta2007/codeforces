#include <cstdio>
char s[10][10];
int ok(){
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j){
            if(s[i][j] == s[i][j+1] &&
               s[i][j] == s[i+1][j] &&
               s[i][j] == s[i+1][j+1]) return 1;
        }
    return 0;
}
int test(){
    if(ok()) return 1;
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j){
            s[i][j] = s[i][j]=='.' ? '#' : '.';
            if(ok()) return 1;
            s[i][j] = s[i][j]=='.' ? '#' : '.';
        }
    return 0;
}
int main(){
    for(int i = 0; i < 4; ++i) scanf("%s", s[i]);
    puts(test()?"YES" : "NO");
    return 0;
}