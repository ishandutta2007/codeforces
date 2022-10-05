#include <bits/stdc++.h>
#define LL long long
using namespace std;
template <typename T> void read(T &x){
	x = 0; int f = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	x *= f;
}
inline void write(int x){if (x > 9) write(x/10); putchar(x%10+'0'); }

const int K = 1000005;
int p[K],cntp,vis[K];
int ans[1000005];
inline void init(int n = 1000000){
	for (int i = 2; i <= n; ++i){
		if (!vis[i]){
			p[++cntp] = i;
			int l = i,r = min(1ll*i*i,n+1ll);
			++ans[l],--ans[r];
		}
		for (int j = 1; j <= cntp && i * p[j] <= n; ++j){
			vis[i*p[j]] = 1;
			if (!(i%p[j])) break;
		}
	}
	ans[1] = 1;
	for (int i = 2; i <= n; ++i) ans[i] += ans[i-1];
}
int main(){
	init();
	int T,n;
	read(T);
	while (T--){
		read(n);
		write(ans[n]),putchar('\n');
	}
	return 0;
}