#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int N = 111111;

int p[N];
map<int, int> s, pos;
vector<int> vec;
int a, b, n, ans[N], visit[N];

void dfs(int x) {
	if (visit[x]) {
		return ;
	}
	visit[x] = 1;
	vec.push_back(x);
	s[p[x]] = 1;
	
	int v = p[x];
	if (pos[a - v] != 0) {
		dfs(pos[a - v]);
	}
	if (pos[b - v] != 0) {
		dfs(pos[b - v]);
	}
}

bool check(int a) {
	for(int i = 0; i < (int)vec.size(); i++) {
		int x = p[vec[i]];
		if (x >= a || s[a - x] == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%d %d %d", &n, &a, &b);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		pos[p[i]] = i;
		
	}
	for(int i = 1; i <= n; i++) {
		if (!visit[i]) {
			s.clear();
			vec.clear();
			dfs(i);
			if (check(a)) {
				for(int j = 0; j < (int)vec.size(); j++) {
					ans[vec[j]] = 0;
				}
			} else if (check(b)) {
				for(int j = 0; j < (int)vec.size(); j++) {
					ans[vec[j]] = 1;
				}
			} else {
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	for(int i = 1; i <= n; i++) {
		printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
	return 0;
}