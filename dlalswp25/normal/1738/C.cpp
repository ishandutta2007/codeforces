#include <bits/stdc++.h>

using namespace std;

const int MX = 100;

int N;
int D[105][105][2];

int f(int e, int o, int cur) {
	if(!e && !o) return cur;
	if(e + o == 1) {
		return (cur + (e ? 0 : 1)) % 2;
	}
	int& ret = D[e][o][cur];
	if(ret != -1) return ret;
	if(e) {
		if((e < 2 || f(e - 2, o, cur) == 0) && (o < 1 || f(e - 1, o - 1, cur) == 0)) return ret = 0;
	}
	if(o) {
		if((e < 1 || f(e - 1, o - 1, 1 - cur) == 0) && (o < 2 || f(e, o - 2, 1 - cur) == 0)) return ret = 0;
	}
	return ret = 1;
}

int main() {
	for(int i = 0; i <= MX; i++) {
		for(int j = 0; j <= MX; j++) D[i][j][0] = D[i][j][1] = -1;
	}
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		int o = 0, e = 0;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			(a & 1 ? o : e)++;
		}
		puts(f(e, o, 0) == 0 ? "Alice" : "Bob");
	}
	return 0;
}