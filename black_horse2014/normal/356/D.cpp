#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <memory.h>
#include <time.h>
#include <list>
#include <deque>
#include <functional>
#include <iterator>

using namespace std;
	
#define MX 70005
	
struct Bag {
	int w, id;
}B[MX];

bool operator<(const Bag &b1, const Bag &b2) {
	return b1.w < b2.w;
}

struct Data {
	int w, in, id;	
}rlt[MX];

bool operator<(const Data &d1, const Data &d2) {
	return B[d1.id].id < B[d2.id].id;	
}

int N, S, id[MX], prev[MX];
bool chk[MX];
int cnt[MX];

int main() {
	
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	int i, j, k, l, tot(1), t, g;
	memset(prev, -1, sizeof prev);
	scanf("%d%d", &N, &S);
	for (i = 0; i < N; i++) {
		scanf("%d", &B[i].w);
		B[i].id = i;
	}

	sort(B, B + N);
	S -= B[N-1].w;
	for (i = 0; i < N - 1; i++) cnt[B[i].w]++;

	if (S < 0) {
		puts("-1");
		return 0;			
	}	

	id[tot++] = N-1;
	chk[0] = 1, l = 0, prev[0] = -1;
	for (i = 0; i < N - 1; i++) {
		if (i && B[i].w == B[i-1].w) continue;
		for (j = l; j >= 0; j--) if (chk[j]) {
			for (k = 0; k < cnt[B[i].w]; k++) {
				t = j + B[i].w * (k+1);
				if (t > S) break;
				if (prev[t] >= i && prev[t] < i + cnt[B[i].w]) break; 
				if (chk[t]) break;
				chk[t] = 1; l = max(l, t);
				prev[t] = i + k;	
			}
		}	
	} 
	if (!chk[S]) {
		puts("-1");
		return 0;
	}
	i = S;
	while (prev[i] != -1) {
		id[tot++] = prev[i];
		i -= B[prev[i]].w;	
	} 
	id[0] = -1;
	sort(id + 1, id + tot);
	for (i = 1; i < tot; i++) {
		for (j = id[i] - 1; j > id[i-1]; j--) {
			rlt[j+1].w = B[j+1].w - B[j].w;
			rlt[j+1].in = j;	
		}	
		rlt[id[i-1]+1].w = B[id[i-1]+1].w;
		rlt[id[i-1]+1].in = -1;
	}
	for (i = 0; i < N; i++) rlt[i].id = i;
	sort(rlt, rlt + N);
	for (i = 0; i < N; i++) {
		printf("%d", rlt[i].w);
		if (rlt[i].in == -1) printf(" 0\n");
		else			     printf(" 1 %d\n", B[rlt[i].in].id+1);	
	}

	return EXIT_SUCCESS;
}