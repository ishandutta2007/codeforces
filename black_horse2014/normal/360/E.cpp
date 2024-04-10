#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstdio>
#include <queue>

#define MX 20005
#define INF 10000000000000LL
using namespace std;

int s1, s2, e;
int N, M, K, L;
int rlt[MX], id[MX];
int pr[MX], cur[MX], D[MX], U[MX];

void add(int u, int v, int w, int w1) {
	
	id[++ L] = v;
	pr[L] = cur[u];
	cur[u] = L;
	rlt[L] = w;
	D[L] = w * 2, U[L] = w1 * 2;
}

queue<int> que;
long long val[MX];

int win(int s1, int s2, int fir) {

	int i, u, v, w;
	int st = 1, en = 2;
	
	for (i = 1; i <= N; i ++) val[i] = INF;
	val[s1] = 1, val[s2] = 0;
	que.push(s1);
	que.push(s2);
	
	while (!que.empty()) {
		
		u = que.front();
		que.pop();
		for (i = cur[u]; i; i = pr[i]) {
			v = id[i];
			w = ((val[u] % 2LL == fir) ? D[i]: U[i]);
			rlt[i] = w / 2;
			if (val[u] + w < val[v]) {
				val[v] = val[u] + w;
				que.push(v);
			}
		}
	}
	return (val[e] % 2LL == fir); 
}

int main() {
	
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	cin >> N >> M >> K;
	cin >> s1 >> s2 >> e;
	
	int i, u, v, w, w1;	
	for (i = 0; i < M; i ++) {
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w, w);	
	}
	for (i = 0; i < K; i ++) {
		scanf("%d%d%d%d", &u, &v, &w, &w1);
		add(u, v, w, w1);	
	}
	
	if (win(s1, s2, 1)) {
		printf("WIN\n");
		for (i = L - K + 1; i <= L; i ++) cout << rlt[i] << " ";
		cout << endl;
	} else if(win(s2, s1, 0)) {
		printf("DRAW\n");	
		for (i = L - K + 1; i <= L; i ++) cout << rlt[i] << " ";
		cout << endl;
	} else {
		printf("LOSE\n");
	}
	return 0;	
}