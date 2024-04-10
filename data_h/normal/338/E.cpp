#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 160000;

int n, len, h, a[MAXN], b[MAXN], ans = 0, left[MAXN], right[MAXN];
vector<pair<int, int> > vec;
int c[MAXN], top;

int isGood(int a[], int b[], int h) {
	for(int i = 1; i <= len; i++)
		if (a[i] + b[len - i + 1] < h)
			return 0;
	return 1;
}

void insert(int c[], int &top, int val) {
	if (val < 0) {
		val = -val;
		for(int i = 1; i <= top; i++) {
			if (c[i] == val) {
				for(++i; i <= top; i++) {
					c[i - 1] = c[i];
				}
				top--;
				return;
			}
		}
	} else {
		c[++top] = val;
		for(int i = top - 1; i >= 1; i--)
			if (c[i + 1] < c[i]) {
				swap(c[i + 1], c[i]);
			} else {
				return;
			}
	}
}

int main() {
	scanf("%d %d %d", &n, &len, &h);
	for(int i = 1; i <= len; i++)
		scanf("%d", &b[i]);
	sort(b + 1, b + len + 1);
	vec.clear();
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		vec.push_back(make_pair(a[i], i));
	}
	sort(vec.begin(), vec.end());
	int Y = sqrt(n);
	if (len <= 500) {
		top = 0;
		for(int i = 1; i <= n; i++) {
			insert(c, top, a[i]);
			if (i - len > 0)
				insert(c, top, -a[i - len]);
			if (i >= len)
				ans += isGood(c, b, h);
		}
	} else {
		int X = len - Y;
		for(int st = 1; st <= n && st + len - 1 <= n; st += Y) {
			for(int i = 0; i <= len + 1; i++) {
				left[i] = i - 1;
				right[i] = i + 1;
			}
			bool flag = true;
			int pos = left[len + 1];
			for(int i = 0; i < n; i++) {
				//printf("%d %d\n", vec[i].first, vec[i].second);
				if (vec[i].second >= st + Y && vec[i].second < st + len) {
					while (pos && vec[i].first + b[pos] >= h) {
						pos = left[pos];
					}
					pos = right[pos];
					if (pos > len || vec[i].first + b[pos] < h) {
						flag = false;
						break;
					}
					right[left[pos]] = right[pos];
					left[right[pos]] = left[pos];
					pos = right[pos];
					if (pos > len)
						pos = left[pos];
				}
			}
			if (!flag)
				continue;
			top = 0;
			for(int i = st; i < st + Y; i++)
				c[++top] = a[i];
			sort(c + 1, c + top + 1);
			for(int i = st; i < st + Y; i++) {
				if (i + len > n + 1)
					break;
				pos = left[len + 1];
				flag = true;
				for(int j = 1; j <= top; j++, pos = left[pos]) {
					if (c[j] + b[pos] < h) {
						flag = false;
						break;
					}
				}
				ans += flag ? 1 : 0;
				insert(c, top, -a[i]);
				insert(c, top, a[i + len]);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}