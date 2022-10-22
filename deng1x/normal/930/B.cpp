#include <bits/stdc++.h>

#define MAXN (5010)

int n, ans;
int cnt[26];
char s[MAXN];

int main(){
	scanf("%s", s);
	n = strlen(s);
	for (int i = 'a'; i <= 'z'; ++ i){
		std::vector<int> vec;
		for (int j = 0; j < n; ++ j){
			if(i == s[j]){
				vec.push_back(j);
			}
		}
		int now = 0;
		for (int j = 1; j < n; ++ j){
			for (auto p : vec){
				++ cnt[s[(p + j) % n] - 'a'];
			}
			int a = 0;
			for (int k = 0; k < 26; ++ k){
				a += cnt[k] == 1;
				cnt[k] = 0;
			}
			now = std::max(now, a);
		}
		ans += now;
	}
	printf("%.15lf\n", 1.0 * ans / n);
	return 0;
}