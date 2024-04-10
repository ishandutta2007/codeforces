#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN], r[MAXN], t[MAXN], b[MAXN];
int main() {
	int n, m, cnt = 0;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]), b[i] = a[i];
	for(int i = 0; i < m; i++) {
		int t1, r1;
		scanf("%d%d", &t1, &r1);
		while(cnt > 0 && r1 > r[cnt-1]) cnt--;
		t[cnt] = t1, r[cnt] = r1; cnt++;
	}
	r[cnt] = 0;
	sort(b, b+r[0]);
	int br = r[0]-1, bl = 0;
	for(int i = 1; i <= cnt; i++) {
		for(int j = r[i-1]-1; j >= r[i]; j--) {
			if(t[i-1] == 1) a[j] = b[br--];
			else a[j] = b[bl++];
		}
	}
	for(int i = 0; i < n; i++) printf("%d ", a[i]);
}