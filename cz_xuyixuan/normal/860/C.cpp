#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
char s[MAXN][8];
int type[MAXN], flg[MAXN], val[MAXN], n;
bool used[MAXN];
int func(int pos) {
	int len = strlen(s[pos] + 1), ans = 0;
	for (int i = 1; i <= len; i++) {
		if (s[pos][i] < '0' || s[pos][i] > '9') return -1;
		ans = ans * 10 + s[pos][i] - '0';
	}
	if (s[pos][1] == '0') return -1;
	else return ans;
}
int main() {
	scanf("%d", &n);
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		scanf("\n%s%d", s[i] + 1, &type[i]);
		tot += type[i];
	}
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = func(i);
		val[i] = tmp;
		if (tmp == -1 || tmp > n) {
			flg[i] = 1;
			val[i] = -1;
			cnt1++;
		} else {
			if (type[i]) {
				if (tmp <= tot) flg[i] = 0;
				else {
					flg[i] = 2;
					cnt2++;
				}
			} else {
				if (tmp > tot) flg[i] = 0;
				else {
					flg[i] = 2;
					cnt2++;
				}
			}
		}
	}
	if (cnt1 == 0 && cnt2 == 0) {
		printf("0\n");
		return 0;
	}
	static int q1[MAXN], l1 = 0, r1 = -1;
	static int q2[MAXN], l2 = 0, r2 = -1;
	if (cnt1) {
		printf("%d\n", cnt1 + cnt2);
		for (int i = 1; i <= n; i++)
			if (val[i] != -1) used[val[i]] = true;
		for (int i = 1; i <= tot; i++)
			if (!used[i]) q1[++r1] = i;
		for (int i = tot + 1; i <= n; i++)
			if (!used[i]) q2[++r2] = i;
		static int a1[MAXN], pos1 = 1, len1 = 0;
		static int a2[MAXN], pos2 = 1, len2 = 0;
		for (int i = 1; i <= n; i++)
			if (flg[i] == 2) {
				if (type[i] == 1) a1[++len1] = i;
				else a2[++len2] = i;
			}
		while (pos1 <= len1 || pos2 <= len2) {
			while (pos1 <= len1 && l1 <= r1) {
				int tmp = a1[pos1];
				printf("move %d %d\n", val[tmp], q1[l1]);
				q2[++r2] = val[tmp];
				pos1++;
				l1++;
			}
			while (pos2 <= len2 && l2 <= r2) {
				int tmp = a2[pos2];
				printf("move %d %d\n", val[tmp], q2[l2]);
				q1[++r1] = val[tmp];
				pos2++;
				l2++;
			}
		}
		for (int i = 1; i <= n; i++)
			if (flg[i] == 1) {
				if (type[i] == 1) printf("move %s %d\n", s[i] + 1, q1[l1++]);
				else printf("move %s %d\n", s[i] + 1, q2[l2++]);
			}
	} else {
		printf("%d\n", cnt1 + cnt2 + 1);
		for (int i = 1; i <= n; i++)
			if (flg[i] == 2) {
				flg[i] = 1;
				printf("move %d 0\n", val[i]);
				s[i][1] = '0';
				s[i][2] = 0;
				val[i] = -1;
				break;
			}
		for (int i = 1; i <= n; i++)
			if (val[i] != -1) used[val[i]] = true;
		for (int i = 1; i <= tot; i++)
			if (!used[i]) q1[++r1] = i;
		for (int i = tot + 1; i <= n; i++)
			if (!used[i]) q2[++r2] = i;
		static int a1[MAXN], pos1 = 1, len1 = 0;
		static int a2[MAXN], pos2 = 1, len2 = 0;
		for (int i = 1; i <= n; i++)
			if (flg[i] == 2) {
				if (type[i] == 1) a1[++len1] = i;
				else a2[++len2] = i;
			}
		while (pos1 <= len1 || pos2 <= len2) {
			while (pos1 <= len1 && l1 <= r1) {
				int tmp = a1[pos1];
				printf("move %d %d\n", val[tmp], q1[l1]);
				q2[++r2] = val[tmp];
				pos1++;
				l1++;
			}
			while (pos2 <= len2 && l2 <= r2) {
				int tmp = a2[pos2];
				printf("move %d %d\n", val[tmp], q2[l2]);
				q1[++r1] = val[tmp];
				pos2++;
				l2++;
			}
		}
		for (int i = 1; i <= n; i++)
			if (flg[i] == 1) {
				if (type[i] == 1) printf("move %s %d\n", s[i] + 1, q1[l1++]);
				else printf("move %s %d\n", s[i] + 1, q2[l2++]);
			}
	}
	return 0;
}