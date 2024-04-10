#include <iostream>
using namespace std;
int a[102][31], b[102][31], ans[102][102][31];
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i){
		int x;
		cin >> x;
		for (int j = 0; j <= 30; ++ j)
			if (x & (1 << j))
				a[i][j] = 1;
	}
	for (int i = 1; i <= m; ++ i){
		int x;
		cin >> x;
		for (int j = 0; j <= 30; ++ j)
			if (x & (1 << j))
				b[i][j] = 1;
	}
	for (int j = 0; j <= 30; ++ j){
		for (int x = 1; x <= n; ++ x)
			for (int y = 1; y <= m; ++ y)
				if (a[x][j] && b[y][j]){
					ans[x][y][j] = 1;
					a[x][j] = 0;
					b[y][j] = 0;
				}
		int cntx = 0, cnty = 0;
		for (int x = 1; x <= n; ++ x)
			if (a[x][j])
				++ cntx;
		for (int y = 1; y <= m; ++ y)
			if (b[y][j])
				++ cnty;
		if (cntx == 0 && (cnty & 1) == 1 || cnty == 0 && (cntx & 1) == 1){
			cout << "NO" << endl;
			return 0;
		}
		if (cnty){
			for (int y = 1; y <= m; ++ y)
				if (b[y][j])
					ans[1][y][j] ^= 1;
		}
		else{
			for (int x = 1; x <= n; ++ x)
				if (a[x][j])
					ans[x][1][j] ^= 1;
		}
	}
	cout << "YES" << endl;
	for (int x = 1; x <= n; ++ x){
		for (int y = 1; y <= m; ++ y){
			int cnt = 0;
			for (int j = 0; j <= 30; ++ j)
				if (ans[x][y][j])
					cnt += (1 << j);
			cout << cnt << " ";
		}
		cout << endl;
	}
}
/*
#include <iostream>
#include <cstdio>
#define maxn 100005
using namespace std;
char str[maxn];
int s[maxn], s2[maxn], ss[maxn];
int n, m, q;
int main(){
	cin >> n >> m >> q;
	cin >> str;
	for (int i = n; i; -- i)
		s[i] = str[i - 1];
	cin >> str;
	for (int i = m; i; -- i)
		s2[i] = str[i - 1];
	for (int i = 1; i <= n - m + 1; ++ i){
		bool flag = false;
		for (int j = i; j <= i + m - 1; ++ j)
			if (s[j] != s2[j - i + 1]){
				flag = true;
				break;
			}
		ss[i] = ss[i - 1] + (! flag);
	}
	while (q --){
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", ss[r - m + 1] - ss[l - 1]);
	}
}
*/