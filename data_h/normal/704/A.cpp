#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;

const int N = 3e5 + 7;

int cnt[N], all[N], tot, pre, unread;
pair<int, int> info[N];
int n, q;

int main() {
	scanf("%d %d", &n, &q);

	fill(cnt + 1, cnt + n, 0);
	fill(all + 1, all + n, 0);
	tot = 0;
	unread = 0;
	pre = 0;

	for (int i = 1; i <= q; i++) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int x; scanf("%d", &x);
			all[x]++;
			unread++;
			info[++tot] = make_pair(x, all[x]);
		} else if (type == 2) {
			int x; scanf("%d", &x);
			while (cnt[x] < all[x]) {
				cnt[x]++;
				unread--;
			}
		} else if (type == 3) {
			int new_pre; scanf("%d", &new_pre);
			while (pre < new_pre) {
				++pre;
				int x = info[pre].first, t = info[pre].second;
				if (t > cnt[x]) {
					cnt[x] = t;
					unread--;
				}
			}
		}
		printf("%d\n", unread);
	}
}