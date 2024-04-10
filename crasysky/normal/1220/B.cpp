#include <iostream>
#include <cstdio>
#include <map>
#define fi first
#define se second
using namespace std;
int r[1003], a[1003][1003];
map <int, int> mp;
int read(){
	int c = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c;
}
int main(){
	int n = read();
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			a[i][j] = read();
	for (int i = 2; i <= n; ++ i)
		for (int j = 1; j * j <= a[1][i]; ++ j)
			if (a[1][i] % j == 0){
				++ mp[j];
				if (j != a[1][i] / j)
					++ mp[a[1][i] / j];
			}
	for (map <int, int> :: iterator it = mp.begin(); it != mp.end(); ++ it){
		pair <int, int> p = *it;
		if (p.se == n - 1){
			r[1] = p.fi;
			for (int i = 2; i <= n; ++ i)
				r[i] = a[1][i] / r[1];
			bool flag = false;
			for (int i = 2; i <= n && ! flag; ++ i)
				for (int j = i + 1; j <= n; ++ j)
					if (1LL * r[i] * r[j] != a[i][j]){
						flag = true;
						break;
					}
			if (! flag){
				for (int i = 1; i <= n; ++ i)
					cout << r[i] << " ";
				cout << endl;
				return 0;
			}
		}
	}
}