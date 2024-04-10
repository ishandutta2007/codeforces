#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 100010

int bit[4][11][11][N], has[128], n;

void add(int p, int c, int v){
    for (int x = p;x <= n;x += x & -x)
        for (int j = 1;j <= 10;j ++)
            bit[c][j][p % j][x] += v;
}

int ask(int c, int len, int mo, int x){
    int ans = 0;
    for (;x;x -= x & -x) ans += bit[c][len][mo][x];
    return ans;
}

int query(int c, int len, int mo, int l, int r){
    return ask(c, len, mo, r) - ask(c, len, mo, l - 1);
}

char s[N];
int main(){
    has['A'] = 0;
    has['T'] = 1;
    has['C'] = 2;
    has['G'] = 3; 
    scanf("%s", &s[1]);
    n = strlen(s+1);
    for (int i = 1; i <= n; ++i) add(i, has[s[i]], 1);  

    char ch[111];  
    int q, a, b, c;
    scanf("%d", &q);  
    while (q--) {  
        scanf("%d", &a);  
        if (a == 1) {  
            scanf("%d %s", &b, ch);  
            add(b, has[s[b]], -1);  
            add(b, has[ch[0]], 1);  
            s[b] = ch[0];  
        } else {  
            scanf("%d %d %s", &b, &c, ch);  
            int len = strlen(ch), ans = 0;  
            for (int i = 0; i < len; i ++)
                ans += query(has[ch[i]], len, (i + b) % len, b, c);
            printf("%d\n", ans);  
        }  
    }  
return 0;
}