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

int n;
char a[205][205];

int main(){
    int T;read(T);
    while(T --){
        read(n);
        for (register int i = 1;i <= n;i ++) scanf("%s", a[i] + 1);
        int num1 = a[1][2], num2 = a[2][1], num3 = a[n][n - 1], num4 = a[n - 1][n];
        num1 -= 48;num2 -= 48;num3 -= 48;num4 -= 48;
        if(num1 == num2){
            if(num3 == num4){
                if(num1 == num3) printf("2\n1 2\n2 1\n");
                else printf("0\n");
            }
            else{
                if(num1 == num3) printf("1\n%d %d\n", n, n - 1);
                else printf("1\n%d %d\n", n - 1, n);
            }
        }
        else{
            if(num3 == num4){
                if(num1 == num3) printf("1\n1 2\n");
                else printf("1\n2 1\n");
            }
            else{
                if(num1 == num3) printf("2\n%d %d\n2 1\n", n, n - 1);
                else printf("2\n%d %d\n2 1\n", n - 1, n);
            }
        }
    }
}