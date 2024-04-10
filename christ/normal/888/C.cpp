#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int lst[200];
int dom[200];
int main () {
    scanf("%s",s+1);
    memset(dom,-1,sizeof dom);
    int n = strlen(s+1);
    for (int i = 1; i <= n; i++) {
        dom[s[i]] = max(dom[s[i]],i-lst[s[i]]);
        lst[s[i]] = i;
    }
    int ret = INT_MAX;
    for (int i = 0; i < 200; i++) {
        dom[i] =max(dom[i],n+1-lst[i]);
        ret = min(ret,dom[i]);
    }
    printf("%d\n",ret);
    return 0;
}