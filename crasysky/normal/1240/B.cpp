#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <set>
#define Pr pair <int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn = 1000006;
const int P = 1e9 + 7;
int l[maxn], r[maxn];
int read(){
	int c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f;
}
int main(){
    int T = read();
    while (T --){
        int n = read();
        for (int i = 1; i <= n; ++ i)
            l[i] = r[i] = 0;
        for (int i = 1; i <= n; ++ i){
            int a = read();
            if (! l[a])
                l[a] = i;
            r[a] = i;
        }
        int c = 0, mx = 0, s = 0, last = 0;
        for (int i = 1; i <= n; ++ i){
            if (l[i] == 0)
                continue;
            ++ s;
            if (i == 1 || last < l[i])
                ++ c, last = r[i];
            else
                mx = max(mx, c), c = 1, last = r[i];
        }
        mx = max(mx, c);
        cout << s - mx << endl;
    }
}