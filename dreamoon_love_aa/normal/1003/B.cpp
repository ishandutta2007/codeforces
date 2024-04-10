#include<cstdio>
char s[514];
int main() {
    int AA[2]={},x;
    scanf("%d%d%d",&AA[0],&AA[1],&x);
    if(AA[0]>AA[1]){
        for(int i = 0; i <= x; i ++) {
            if(i % 2 == 0) {
                AA[0]--;
                s[i] = '0';
            }
            else {
                AA[1]--;
                s[i] = '1';
            }
        }
    }
    else{
        for(int i = 0; i <= x; i ++) {
            if(i % 2 == 0) {
                AA[1]--;
                s[i] = '1';
            }
            else {
                AA[0]--;
                s[i] = '0';
            }
        }
    }
    for(int i = 0; i <= x; i++){
        while(AA[s[i]-'0']){
            AA[s[i]-'0']--;
            putchar(s[i]);
        }
        printf("%c",s[i]);
    }
    puts("");
    return 0;
}