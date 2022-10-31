#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define REP(i, a, b) for(int i = a; i <= b; i++)
#define PER(i, a, b) for(int i = a; i >= b; i--)
#define int long long
#define lowbit(x) x &(-x)
#define db long double
template<class T>inline void chkmax(T &x, const T &y) {if(x < y) x = y;}
template<class T>inline void chkmin(T &x, const T &y) {if(y < x) x = y;}
inline int read() {
    int x = 0, flag = 1;char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') flag = - 1;
        ch = getchar();
    }
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * flag;
}

int exgcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return d;
}

signed main() {
    int n = read(), p = read(), w = read(), d = read();
    int y;
    for (y = 0; y < w && (p - d * y) % w; ++ y);
    if (y < w){
        int x = (p - d * y) / w;
        int z = n - x - y;
        if (x >= 0 && z >= 0)
            cout << x << " " << y << " " << z << endl;
        else
            cout << -1 << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}
/*
923399641127 50915825165227299 94713 49302
*/