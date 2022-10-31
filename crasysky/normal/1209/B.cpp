#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
string s;
int cnt[10004];
int main(){
	int n;
	cin >> n;
	cin >> s;
	for (int i = 1; i <= n; ++ i){
		int a, b;
		cin >> a >> b;
		if (s[i - 1] == '1'){
			for (int j = 0; j < b; ++ j)
				++ cnt[j];
		}
		for (int j = 0, f = (s[i - 1] == '0'); b + a * j <= 240; ++ j, f ^= 1){
			int t = b + a * j;
			if (f)
				for (int k = t; k <= min(240, b + a * (j + 1) - 1); ++ k)
					++ cnt[k];
		}
	}
	int ans = 0;
	for (int i = 0; i <= 240; ++ i)
		ans = max(ans, cnt[i]);
	cout << ans << endl;
}