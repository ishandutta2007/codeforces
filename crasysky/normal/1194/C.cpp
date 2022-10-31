#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn = 100005;
string a, b, p;
int c[maxn];
int read(){
    int c = 0, f = 1; char ch = getchar();
    while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c * f;;
}
int main(){
    int q = read();
    while (q --){
        cin >> a >> b >> p;
        for (int i = 1; i <= 26; ++ i)
            c[i] = 0;
        for (int i = 0; i < p.length(); ++ i)
            ++ c[p[i] - 'a' + 1];
        int j = 0;
        bool flag = false;
        for (int i = 0; i < b.length(); ++ i)
            if (j < a.length() && a[j] == b[i])
                ++ j;
            else if (c[b[i] - 'a' + 1])
                -- c[b[i] - 'a' + 1];
            else{
                flag = true;
                break;
            }
        if (flag || j < a.length())
            puts("NO");
        else
            puts("YES");
    }
}