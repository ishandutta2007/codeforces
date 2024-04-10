#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 5111;

char map[N][N];
int n, m;
int s[N];
int num[N];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%s", map[i] + 1);
	}
	
	int ans = 0;
	
	for(int i = m; i >= 1; i--) {
		for(int j = 1; j <= n; j++) {
			num[s[j]]--;
			if (map[j][i] == '1')
				s[j]++;
			else
				s[j] = 0;
			num[s[j]]++;
		}
		
		int h = 0, w = 6000;
		
		for(int j = m; j >= 1; j--) {
			h += num[j];
			ans = max(ans, h * j);
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}