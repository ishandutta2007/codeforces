#include <stdio.h>
int N, L, X, Y;
int d[100050];
bool exist_chk(int a) {
	int st = 1, en = N, mi;
	while(st<=en) {
		mi = (st+en)/2;
		if(a == d[mi]) return true;
		if(a > d[mi]) st = mi+1;
		else en = mi-1;
	}
	return false;
}
int main() {
	int i, chk1 = 0, chk2 = 0;
	scanf("%d %d %d %d", &N, &L, &X, &Y);
	for(i = 1; i <= N; i++) scanf("%d", &d[i]);
	for(i = 1; d[i]+X <= L; i++) {
		if(exist_chk(d[i]+X)) break;
	}
	if(d[i]+X <= L) chk1 = 1;
	for(i = 1; d[i]+Y <= L; i++) {
		if(exist_chk(d[i]+Y)) break;
	}
	if(d[i]+Y <= L) chk2 = 1;
	if(chk1 == 1 && chk2 == 1) printf("0");
	else if(chk1 == 1 && chk2 == 0) printf("1\n%d", Y);
	else if(chk2 == 1 && chk1 == 0) printf("1\n%d", X);
	else {
		for(i = 1; i <= N; i++) {
			if(d[i] < X && d[i]+Y > L) continue;
			if(exist_chk(d[i]+Y-X)) break;
		}
		if(i != N+1) {
			if(d[i] >= X) printf("1\n%d", d[i]-X);
			else printf("1\n%d", d[i]+Y);
			return 0;
		}
		for(i = 1; d[i]+X+Y <= L; i++) {
			if(exist_chk(d[i]+X+Y)) break;
		}
		if(d[i]+X+Y <= L) {
			printf("1\n%d", d[i]+X);
			return 0;
		}
		printf("2\n%d %d", X, Y);
	}
	return 0;
}