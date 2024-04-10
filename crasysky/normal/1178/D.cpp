#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#define Pr pair <int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int P = 998244353;
const int maxn = 2000006;
const int INF = 1000000000;
int a[maxn], sl[maxn], sr[maxn];
bool isprime(int x){
    for (int i = 2; i * i <= x; ++ i)
        if (x % i == 0)
            return false;
    return true;
}
int read(){
	int c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f;
}
int main(){
    int n = read(), p = n;
    for (; ! isprime(p); ++ p);
    cout << p << endl;
    for (int i = 1; i < n; ++ i)
        cout << i << " " << i + 1 << endl;
    cout << n << " " << 1 << endl;
    for (int i = 1; i <= p - n; ++ i)
        cout << i << " " << n - i << endl;
}