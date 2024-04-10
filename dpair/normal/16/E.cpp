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

double dp[1 << 20 | 1];

double p[21][21];

int n, c[1 << 20 | 1];
vector <int> vec[21];

inline double die(int x, int num){
    double ret = 0, pos = c[num];
    for (register int i = 0;i < n;i ++){
        if(num & (1 << i)) ret += p[i][x] / pos;
    }
    return ret;
}

inline string fix(int num){
    string ret;
    for (register int i = 0;i < n;i ++){
        if(num & (1 << i)) ret[i] = '1';
        else ret[i] = '0';
    }
    return ret;
}

int main(){
    read(n);
    for (register int i = 0;i < (1 << n);i ++){
        int x = i;
        while(x){
            if(x & 1) c[i] ++;
            x >>= 1;
        }
        vec[c[i]].push_back(i);
    }
    for (register int i = 0;i < n;i ++){
        for (register int j = 0;j < n;j ++){
            scanf("%lf", &p[i][j]);
        }
    }
    dp[(1 << n) - 1] = 1;
    for (register int k = n - 1;k >= 1;k --){
        for (register int i = 0;i < vec[k].size();i ++){
            int num = vec[k][i];
            for (register int j = 0;j < n;j ++){
                if(!(num & (1 << j))){
                    dp[num] += 2.0 * dp[num | (1 << j)] * die(j, num) / (double)(k + 1);
                }
            }
            // printf("num = %s, dp[num] = %.6lf\n", fix(num).c_str(), dp[num]);
        }
    }
    for (register int i = 0;i < n;i ++) printf("%.6lf ", dp[1 << i]);
    putchar(10);
    return 0;
}