#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1000006;
string s;
int a[maxn], mn[20], mx[20], smx[20], smn[20];
int main(){
	int T;
	cin >> T;
	while (T --){
		memset(mn, 0, sizeof(mn));
		memset(mx, 0, sizeof(mx));
		memset(smx, 0, sizeof(smx));
		memset(smn, 0, sizeof(smn));
		int n;
		cin >> n;
		cin >> s;
		for (int i = 1; i <= n; ++ i)
			a[i] = s[i - 1] - '0';
		for (int j = 0; j <= 9; ++ j){
			for (int i = 1; i <= n; ++ i)
				if (a[i] == j){
					mn[j] = i;
					break;
				}
			for (int i = n; i; -- i)
				if (a[i] == j){
					mx[j] = i;
					break;
				}
		}
		int L = 10, l = mx[0];
		for (int i = 1; i <= 9; ++ i)
			if (mn[i] && mn[i] < l){
				L = i - 1;
				break;
			}
			else if (mx[i])
				l = max(l, mx[i]);
		int R = 0, r = mn[9] == 0 ? n + 1 : mn[9];
		for (int i = 8; i; -- i)
			if (mx[i] && mx[i] > r){
				R = i + 1;
				break;
			}
			else if (mn[i])
				r = min(r, mn[i]);
		if (R - L <= 1){
			for (int i = 1; i <= n; ++ i)
				if (a[i] <= L)
					putchar('1');
				else
					putchar('2');
			cout << endl;
		}
		else{
			if (R - L > 2)
				puts("-");
			else{
				smx[0] = mx[0];
				for (int i = 1; i <= 9; ++ i)
					smx[i] = max(smx[i - 1], mx[i]);
				smn[10] = n + 1;
				for (int i = 9; i; -- i)
					if (mn[i] == 0)
						smn[i] = smn[i + 1];
					else
						smn[i] = min(smn[i + 1], mn[i]);
				int x = smx[L], y = smn[R];
				bool flag = false;
				for (int i = y; i <= x; ++ i)
					if (a[i] == L + 1){
						flag = true;
						break;
					}
				if (flag)
					puts("-");
				else{
					for (int i = 1; i <= n; ++ i){
						if (a[i] <= L)
							putchar('1');
						else if (a[i] >= R)
							putchar('2');
						else if (i >= x)
							putchar('1');
						else
							putchar('2');
					}
					cout << endl;
				}
			}
		}
	}
}