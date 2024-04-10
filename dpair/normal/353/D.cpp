#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int main(){
    scanf("%s", s + 1);
    int it = 1, ans = 0, cnt = 0;
    while(s[it] == 'F' && it <= strlen(s + 1)) it ++;
    for (register int i = it;i <= strlen(s + 1);i ++){
        if(s[i] == 'F') ans = max(ans + 1, cnt);
        else cnt ++;
    }
    printf("%d\n", ans);
}