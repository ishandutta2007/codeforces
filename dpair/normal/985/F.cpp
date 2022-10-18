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
typedef long long LL;
const LL MOD1 = 998244353;
const LL MOD2 = 1000000007;
const LL base1 = 131ll;
const LL base2 = 2ll;

int n, k;
char a[200005];
LL h1[26][200005], h2[26][200005], b1[200005], b2[200005];

inline LL gt1(int num, int l, int r){return (h1[num][r] - (h1[num][l - 1] * b1[r - l + 1] % MOD1) + MOD1) % MOD1;}
inline LL gt2(int num, int l, int r){return (h2[num][r] - (h2[num][l - 1] * b2[r - l + 1] % MOD2) + MOD2) % MOD2;}

int main(){
    read(n);read(k);
    b1[0] = b2[0] = 1;
    for (register int i = 1;i <= n;i ++){
        b1[i] = (b1[i - 1] * base1) % MOD1;
        b2[i] = (b2[i - 1] * base2) % MOD2;
    }
    scanf("%s", a + 1);
    for (register int i = 1;i <= n;i ++){
        for (register int j = 0;j < 26;j ++){
            h1[j][i] = (h1[j][i - 1] * base1 + (j == a[i] - 'a')) % MOD1;
            h2[j][i] = (h2[j][i - 1] * base2 + (j == a[i] - 'a')) % MOD2;
        }
    }
    while(k --){
        LL num1 = 0, num2 = 0, Num1 = 0, Num2 = 0;
        int l1, l2, len;read(l1);read(l2);read(len);
        int r1 = l1 + len - 1, r2 = l2 + len - 1;
        for (register int i = 0;i < 26;i ++){
            LL num;
            num = gt1(i, l1, r1);
            num1 = (num1 + num * num % MOD1 * num % MOD1) % MOD1;
            num = gt1(i, l2, r2);
            Num1 = (Num1 + num * num % MOD1 * num % MOD1) % MOD1;
            num = gt2(i, l1, r1);
            num2 = (num2 + num * num % MOD2 * num % MOD2) % MOD2;
            num = gt2(i, l2, r2);
            Num2 = (Num2 + num * num % MOD2 * num % MOD2) % MOD2;
        }
        if(num1 == Num1 && num2 == Num2) printf("YES\n");
        else printf("NO\n");
    }
}