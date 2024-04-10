#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn = 1000006;
int a[maxn], pre[maxn];
string s;
int read(){
	int c = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c;
}
int main(){
	int T = read();
	while (T --){
		string s;
		cin >> s;
		int n = s.length(), last = 0;
		for (int i = 1; i <= n; ++ i){
			a[i] = s[i - 1] - '0';
			pre[i] = last;
			if (a[i] == 1)
				last = i;
		}
		int ans = 0;
		for (int i = 1; i <= n; ++ i)
			if (a[i] == 1){
				int s = 0;
				for (int j = 1; i + j - 1 <= n && j <= 20; ++ j){
					s = (s << 1) | a[i + j - 1];
					if (j <= s && s <= i + j - 1 - pre[i])
						++ ans;	
				}
			}
		cout << ans << endl;
	}
}