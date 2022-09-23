#include <bits/stdc++.h>

using namespace std;

int N;
char ans[1010];
bool chk[30];
char K[30];

char query1(int i) {
	printf("? 1 %d\n", i);
	fflush(stdout);
	char c; scanf(" %c", &c);
	return c;
}

int query2(int l, int r) {
	printf("? 2 %d %d\n", l, r);
	fflush(stdout);
	int x; scanf("%d", &x);
	return x;
}

int main() {
	scanf("%d", &N);
	int M = query2(1, N);
	ans[1] = query1(1);
	int cur = 1;
	for(int i = 2; i <= M; i++) {
		int l = cur + 1, r = N;
		while(l <= r) {
			int m = l + r >> 1;
			int t = query2(1, m);
			if(t >= i) r = m - 1;
			else l = m + 1;
		}
		// l
		ans[l] = query1(l);

		l = cur + 1, r = N;
		while(l <= r) {
			int m = l + r >> 1;
			int t = query2(1, m);
			if(t > i) r = m - 1;
			else l = m + 1;
		}
		// r
		cur = r;
	}
	int cnt = 0;
	for(int i = 1; i <= N; i++) {
		if(ans[i]) { cnt++; continue; }
		int l = 1, r = cnt;
		while(l <= r) {
			int m = l + r >> 1;
			int c = 0;
			for(int j = 0; j < 26; j++) chk[j] = false;
			int j;
			for(j = i - 1; j >= 1; j--) {
				if(!chk[ans[j] - 'a']) c++;
				chk[ans[j] - 'a'] = true;
				if(c >= m) { K[m] = ans[j]; break; }
			}
			int t = query2(j, i);
			if(t == m) r = m - 1;
			else l = m + 1;
		}
		ans[i] = K[l];
	}
	printf("! ");
	for(int i = 1; i <= N; i++) printf("%c", ans[i]); puts("");
	fflush(stdout);
	return 0;
}