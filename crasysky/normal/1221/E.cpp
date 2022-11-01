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
const int maxn = 1000006;
int a, b, arr[maxn];
string s;
bool t2(int x){ return b <= x && x < a; }
bool t3(int x){ return a <= x && x < 2 * b; }
bool t4(int x){ return x >= 2 * b && x >= a; }
int read(){
    int c = 0, f = 1; char ch = getchar();
    while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c * f;
}
int main(){
    int q = read();
    while (q --){
        a = read(), b = read();
        cin >> s;
        int n = s.length(), m = 0, last = 0;
        for (int i = 0; i < n; ++ i)
            if (s[i] == 'X'){
                if (last)
                    arr[++ m] = last;
                last = 0;
            }
            else
                ++ last;
        if (last)
            arr[++ m] = last;
        int cnt2 = 0, cnt3 = 0, cnt4 = 0;
        for (int i = 1; i <= m; ++ i)
            if (t2(arr[i]))
                ++ cnt2;//win segments
            else if (t3(arr[i]))
                ++ cnt3;//compared segments
            else if (t4(arr[i]))
                ++ cnt4;//divided segment;
        if (cnt2 || cnt4 > 1)
            puts("NO");
        else{
            if (cnt4){
                bool flag = false;
                int len = 0;
                for (int i = 1; i <= m; ++ i)
                    if (t4(arr[i])){
                        len = arr[i];
                        break;
                    }
                for (int i = 0; i <= len - a; ++ i){
                    int x = i, y = len - a - i;
                    if (t2(x) || t2(y))
                        continue;
                    if (t4(x) || t4(y))
                        continue;
                    int c = cnt3 + t3(x) + t3(y);
                    if (c % 2 == 0){
                        puts("YES");
                        flag = true;
                        break;
                    }
                }
                if (! flag)
                    puts("NO");
            }
            else{
                if (cnt3 % 2 == 1)
                    puts("YES");
                else
                    puts("NO");
            }
        }
    }
}