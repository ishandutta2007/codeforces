#include <stdio.h>
int d1[100050], d2[100050];
int rev_point1[100050], rev_point2[100050], rev_point[200050];
int N1, N2, cnt1, cnt2, cnt;
int ans[200050];
void input() {
	int i;
	cnt1 = cnt2 = 0;
	scanf("%d", &N1);
	for(i = 1; i <= N1; i++) {
		scanf("%d", &d1[i]);
		if(i >= 2 && d1[i] != d1[i-1]) {
			cnt1++;
			rev_point1[cnt1] = i-1;
		}
	}
	rev_point1[cnt1+1] = N1;
	scanf("%d", &N2);
	for(i = 1; i <= N2; i++) {
		scanf("%d", &d2[i]);
		if(i >= 2 && d2[i] != d2[i-1]) {
			cnt2++;
			rev_point2[cnt2] = i-1;
		}
	}
	rev_point2[cnt2+1] = N2;
	return;
}
void get_ans() {
	int t1=1, t2=1, c=1, i, j;
	cnt = 0;
	if(cnt1 > cnt2) {
		for(i = 1; i <= cnt2+1; i++) {
			for(j = rev_point1[i-1]+1; j <= rev_point1[i]; j++) {
				ans[c] = d1[j];
				printf("%d ", j);
				c++;
			}
			for(j = rev_point2[i-1]+1; j <= rev_point2[i]; j++) {
				ans[c] = d2[j];
				printf("%d ", j+N1);
				c++;
			}
		}
		for(i = cnt2+2; i <= cnt1+1; i++) {
			for(j = rev_point1[i-1]+1; j <= rev_point1[i]; j++) {
				ans[c] = d1[j];
				printf("%d ", j);
				c++;
			}
		}
	}
	else if(cnt1 < cnt2) {
		for(i = 1; i <= cnt1+1; i++) {
			for(j = rev_point2[i-1]+1; j <= rev_point2[i]; j++) {
				ans[c] = d2[j];
				printf("%d ", j+N1);
				c++;
			}
			for(j = rev_point1[i-1]+1; j <= rev_point1[i]; j++) {
				ans[c] = d1[j];
				printf("%d ", j);
				c++;
			}
		}
		for(i = cnt1+2; i <= cnt2+1; i++) {
			for(j = rev_point2[i-1]+1; j <= rev_point2[i]; j++) {
				ans[c] = d2[j];
				printf("%d ", j+N1);
				c++;
			}
		}
	}
	else if(d1[1] == d2[1] || d1[N1] == 1) {
		for(i = 1; i <= cnt1+1; i++) {
			for(j = rev_point1[i-1]+1; j <= rev_point1[i]; j++) {
				ans[c] = d1[j];
				printf("%d ", j);
				c++;
			}
			for(j = rev_point2[i-1]+1; j <= rev_point2[i]; j++) {
				ans[c] = d2[j];
				printf("%d ", j+N1);
				c++;
			}
		}
	}
	else {
		for(i = 1; i <= cnt2+1; i++) {
			for(j = rev_point2[i-1]+1; j <= rev_point2[i]; j++) {
				ans[c] = d2[j];
				printf("%d ", j+N1);
				c++;
			}
			for(j = rev_point1[i-1]+1; j <= rev_point1[i]; j++) {
				ans[c] = d1[j];
				printf("%d ", j);
				c++;
			}
		}
	}
	for(i = 1; i <= N1+N2; i++) {
		if(ans[i] != ans[i+1]) {
			cnt++;
			rev_point[cnt] = i;
		}
	}
	printf("\n%d\n", cnt);
	for(i = 1; i <= cnt; i++) printf("%d ", rev_point[i]);
	return;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	get_ans();
	return 0;
}