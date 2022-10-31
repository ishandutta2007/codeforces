#include <iostream>
#include <cstdio>
#include <vector>
#define maxn 100005
using namespace std;
int p[maxn], s[maxn];
vector <int> G[maxn];
int main(){
	int n;
	cin >> n;
	for (int i = 2; i <= n; ++ i){
		scanf("%d", &p[i]);
		G[p[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &s[i]);
	long long ans = 0;
	for (int i = 1; i <= n; ++ i){
		if (s[i] == -1){
			if (G[i].size() == 0)
				continue;
			s[i] = s[G[i][0]];
			for (int j = 1; j < G[i].size(); ++ j)
				s[i] = min(s[i], s[G[i][j]]);
		}
		if (s[i] < s[p[i]]){
			cout << -1 << endl;
			return 0;
		}
		ans += s[i] - s[p[i]];
	}
	cout << ans << endl;
}