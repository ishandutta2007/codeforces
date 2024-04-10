#include <iostream>
#include <cstdio>
#define maxn 2003
using namespace std;
char s[maxn][maxn], have[maxn][maxn];
int way[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
int read(){
	int cnt = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		ch = getchar();
	while ('0' <= ch && ch <= '9'){
		cnt = cnt * 10 + ch - '0';
		ch = getchar();
	}
	return cnt;
}
int main(){
	int n = read(), m = read();
	for (int i = 1; i <= n; ++ i)
		cin >> s[i];
	for (int i = 2; i < n; ++ i)
		for (int j = 1; j < m - 1; ++ j){
			bool flag = false;
			for (int k = 0; k < 8; ++ k)
				if (s[i + way[k][0]][j + way[k][1]] == '.'){
					flag = true;
					break;
				}
			if (flag == false)
				for (int k = 0; k < 8; ++ k)
					have[i + way[k][0]][j + way[k][1]] = true;
		}
	bool ans = false;
	for (int i = 1; i <= n; ++ i)
		for (int j = 0; j < m; ++ j)
			if (s[i][j] == '#' && ! have[i][j]){
				ans = true;
				break;
			}
	if (! ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}