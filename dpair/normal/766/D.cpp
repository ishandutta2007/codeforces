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
inline char next_char(){
    char ch = getchar();
    while(ch == 9 || ch == 10 || ch == 32) ch = getchar();
    return ch;
}

int n, m, q;

int fa[100005], val[100005];

map <string, int> re;
//0  1 
int find(int x){
    if(fa[x] == x) return x;
    int tmp = fa[x];
    fa[x] = find(fa[x]);
    val[x] ^= val[tmp];
    return fa[x];
}
string s;
int main(){
    int tot = 0;
    read(n);read(m);read(q);
    while(n --){
        string sschara;
        cin >> sschara;
        re[sschara] = ++ tot;
        fa[tot] = tot;
    }
    while(m --){
        int x;read(x);
        x --;
        int sans, papyrus;
        cin >> s;sans = re[s];cin >> s;papyrus = re[s];
        int gaster = find(sans), toby = find(papyrus);
        if(gaster == toby){
            if((val[sans] ^ val[papyrus]) == x) printf("YES\n");
            else printf("NO\n"); 
        }
        else{
            printf("YES\n");
            fa[gaster] = toby;
            val[gaster] = x ^ val[sans] ^ val[papyrus];
        }
    }
    while(q --){
        int undyne, alphys;
        cin >> s;undyne = re[s];cin >> s;alphys = re[s];
        int asgore = find(undyne), toriel = find(alphys);
        if(asgore == toriel){
            fprint((val[undyne] ^ val[alphys]) + 1, 10);
        }
        else fprint(3, 10);
    }
}