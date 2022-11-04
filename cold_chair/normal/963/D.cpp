#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
using namespace std;

const int N = 4e5 + 5;

char s[N], t[N]; int len, len2;

int n, k[N], d[N], d0;

int m0;
int he[N], rank[N], SA[N], tp[N],tax[N];
void rsort() {
    fo(i, 1, m0) tax[i] = 0; 
    fo(i, 1, len) tax[rank[tp[i]]] ++;
    fo(i, 1, m0) tax[i] += tax[i - 1];
    fd(i, len, 1) SA[tax[rank[tp[i]]] --] = tp[i];
}
int cmp(int *f, int a, int b, int c) {return f[a] == f[b] && f[a + c] == f[b + c];}
void B_SA() {
    fo(i, 1, len) rank[i] = s[i], tp[i] = i;
    m0 = 127; rsort();
    for(int w = 1, p = 1; p < len; m0 = p, w *= 2) {
        p = 0; fo(i, len - w + 1, len) tp[++ p] = i;
        fo(i, 1, len) if(SA[i] > w) tp[++ p] = SA[i] - w;
        rsort(); swap(tp, rank); rank[SA[1]] = p = 1;
        fo(i, 2, len) rank[SA[i]] = cmp(tp, SA[i - 1], SA[i], w) ? p : ++ p;
    }
    int j, k = 0;
    for(int i = 1; i <= len; he[rank[i ++]] = k)
        for(k = k ? k - 1 : 0, j = SA[rank[i] - 1]; s[i + k] == s[j + k]; k ++);
}

int pd(int x) {
	fo(i, SA[x], SA[x] + len2 - 1) {
		if(i > len) return 0;
		if(s[i] < t[i - SA[x] + 1]) return 0;
		if(s[i] > t[i - SA[x] + 1]) return 1;
	}
	return 2;
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%s", s + 1); len = strlen(s + 1);
	B_SA();
	scanf("%d", &n);
	fo(i, 1, n) {
		scanf("%d", &k[i]);
		scanf("%s", t + 1); len2 = strlen(t + 1);
		int ans = 0;
		for(int l = 1, r = len; l <= r; ) {
			int m = l + r >> 1;
			int p = pd(m); if(p == 2) ans = m;
			if(p) r = m - 1; else l = m + 1;
		}
		int ans2 = -1;
		for(int l = 1, r = len; l <= r; ) {
			int m = l + r >> 1;
			int p = pd(m); if(p == 2) ans2 = m;
			if(p == 1) r = m - 1; else l = m + 1;
		}
		if(ans2 - ans + 1 < k[i]) {
			printf("-1\n"); continue;
		}
		d0 = 0;
		fo(j, ans, ans2) d[++ d0] = SA[j];
		sort(d + 1, d + d0 + 1);
		int sum = len;
		d[0] = 0;
		fo(j, 1, d0 - k[i] + 1)
			sum = min(sum, d[j + k[i] - 1] + len2 - d[j]);
		printf("%d\n", sum);
	}
}