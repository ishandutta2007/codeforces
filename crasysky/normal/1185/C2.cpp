#include <iostream>
#include <cstdio>
using namespace std;
int t[1000006], cnt[102];
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &t[i]);
	for (int i = 1; i <= n; ++ i){
		int s = 0, have = m - t[i];
		for (int j = 1; j <= 100; ++ j){
			int x = min(cnt[j], have / j);
			s += x;
			have -= x * j;
		}
		printf("%d ", i - 1 - s);
		cnt[t[i]] ++;
	}
}