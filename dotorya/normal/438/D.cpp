#include <stdio.h>
const int MX = 131072;
struct data {
	long long mx, sum;
} it[MX*2+50];
long long MAX(long long a, long long b) {
	if(a<b) return b;
	else return a;
}
void update(int pos, long long num) {
	int t = pos;
	it[t].mx = num, it[t].sum = num;
	while(t > 1) {
		t /= 2;
		it[t].mx = MAX(it[2*t].mx, it[2*t+1].mx);
		it[t].sum = it[2*t].sum + it[2*t+1].sum;
	}
	return;
}
void modulo(int node, int st, int en, int l, int r, long long MOD) {
	if(node >= MX) {
		update(node, it[node].mx%MOD);
		return;
	}
	if(it[node].mx < MOD) return;
	int mi = (st+en)/2;
	if(r <= mi) {
		modulo(node*2, st, mi, l, r, MOD);
		return;
	}
	if(l >= mi+1) {
		modulo(node*2+1, mi+1, en, l, r, MOD);
		return;
	}
	modulo(node*2, st, mi, l, mi, MOD);
	modulo(node*2+1, mi+1, en, mi+1, r, MOD);
	return;
}
long long get_sum(int st, int en) {
	long long t = 0;
	if(st == en) return it[st].sum;
	if(st % 2 == 1) {
		t += it[st].sum;
		st++;
	}
	if(st == en) return t + it[st].sum;
	if(en % 2 == 0) {
		t += it[en].sum;
		en--;
	}
	return t + get_sum(st/2, en/2);
}
int main() {
	int N, M, i, j, chk, t1, t2;
	long long t, t3;
	scanf("%d %d", &N, &M);
	for(i = 0; i < N; i++) {
		scanf("%lld", &t);
		update(MX+i, t);
	}
	for(i = 1; i <= M; i++) {
		scanf("%d", &chk);
		if(chk == 1) {
			scanf("%d %d", &t1, &t2);
			printf("%lld\n", get_sum(MX+t1-1, MX+t2-1));
		}
		if(chk == 2) {
			scanf("%d %d %lld", &t1, &t2, &t3);
			modulo(1, 1, MX, t1, t2, t3);
		}
		if(chk == 3) {
			scanf("%d %d", &t1, &t2);
			update(t1+MX-1, t2);
		}
	}
	return 0;
}