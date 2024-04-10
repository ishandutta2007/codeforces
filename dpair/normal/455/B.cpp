#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T &x){
    x = 0;int fu = 1;
    char c = getchar();
    while(c > 57 || c < 48){
        if(c == 45) fu = -1;
        c = getchar();
    }
    while(c <= 57 && c >= 48){
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    x *= fu;
}
template <typename T>
inline void fprint(T x){
    if(x < 0) putchar(45), x = -x;
    if(x > 9) fprint(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void fprint(T x, char ch){
    fprint(x);putchar(ch);
}

int n, m;

int Trie[1500005][31], tot;
bitset <1500005> b;
char s[100005];
inline void ins(int len){
    int rt = 0;
    for (register int i = 1;i <= len;i ++){
        b[rt] = 1;
        if(!Trie[rt][s[i] - 'a']) Trie[rt][s[i] - 'a'] = ++ tot;
        rt = Trie[rt][s[i] - 'a'];
    }
}

bool dfs(int rt, bool win){
    if(!b[rt]) return win;
    for (register int i = 0;i < 26;i ++){
        if(Trie[rt][i] && !dfs(Trie[rt][i], win)) return 1;
    }
    return 0;
}

int main(){
    read(n);read(m);
    while(n --){
        scanf("%s", s + 1);
        ins(strlen(s + 1));
    }
    bool can_win = dfs(0, 0), can_lose = dfs(0, 1);
    // printf("can_win %d, can_lose %d\n", can_win, can_lose);
    if(can_win && can_lose) return printf("First\n"), 0;
    if(!can_win) return printf("Second\n"), 0;
    if(can_win && !can_lose){
        if(m & 1) printf("First\n");
        else printf("Second\n");
        return 0; 
    }
}