#include <bits/stdc++.h>
using namespace std;

const int MM = 200100;

struct dt {
	int id;
	long long a, b, c;
	void input() {
		char s[100];
		scanf("%s", s);
		strcat(s, "+");
		long long v[3] = {0};
		for (int i = 1, id = 0, dpl = 2, pf = 0; s[i]; ++i) {
			if (s[i] == '.') {
				pf = 1;
				continue;
			}
			if (s[i] == '+') {
				v[id] *= pow(10, dpl);
				pf = 0;
				dpl = 2;
				++id;
				continue;
			}
			if (s[i] == ')') {
				v[id] *= pow(10, dpl);
				pf = 0;
				dpl = 2;
				++id;
				continue;
			}
			if (s[i] == '/') continue;
			(v[id] *= 10) += s[i] - '0';
			dpl -= pf;
		}
		a = v[0], b = v[1], c = v[2];
	}
	bool operator<(const dt &o) const
	{
		return (a + b) * o.c < (o.a + o.b) * c;
	}
	bool operator!=(const dt &o) const
	{
		return (a + b) * o.c != (o.a + o.b) * c;
	}
};

dt d[MM];
int cnt[MM];

int main() {
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) d[i].id = i, d[i].input();
	sort(d, d + m);
	for (int i = 0, j; i < m;) {
		for (j = i + 1; j < m; ++j) if (d[i] != d[j]) break;
		for (int k = i; k < j; ++k) cnt[d[k].id] = j - i;
		i = j;
	}
	for (int i = 0; i < m; ++i) printf("%d%c", cnt[i], i == m - 1 ? '\n' : ' ');
	return 0;
}