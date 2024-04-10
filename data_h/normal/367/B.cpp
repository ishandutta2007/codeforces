#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<int> result;

const int N = 222222;

int a[N], b[N];
int n, m, p;
map<int, int> cnt;
int wr, visit[N];

void insert(int x) {
	int tmp = (++cnt[x]);
	if (tmp == 1) {
		wr++;
	} else if (tmp == 0) {
		wr--;
	}
}

void delet(int x) {
	int tmp = (--cnt[x]);
	if (tmp == 0) {
		wr--;
	} else if (tmp == -1) {
		wr++;
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &p);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}	
	wr = 0;
	for(int i = 1; i <= m; i++) {
		int x;
		scanf("%d", &x);
		if (cnt[x] == 0)
			wr++;
		cnt[x]--;
	}
	for(int i = 1; i <= n; i++) {
		if (visit[i])
			continue;
		for(int j = i, k = i; j <= n; j += p) {
			while((k - j) / p < m && k <= n) {
				insert(a[k]);
				k += p;
			}
			if (wr == 0)
				result.push_back(j);
			delet(a[j]);
			visit[j] = 1;
		}
	}
	sort(result.begin(), result.end());
	printf("%d\n", (int)result.size());
	for(int i = 0; i < (int)result.size(); i++){
		printf("%d ", result[i]);
	}
	return 0;
}