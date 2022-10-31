#include <bits/stdc++.h>
using namespace std;

int n,start,x;

const int N = 50005;
int a[N];
int val[N]={},nxt[N]={};

bool is_nxt[N]={};
const int K = 1000;

constexpr int INF = 2e9+5;

int r() {
	return abs((rand()<<16) ^ rand());
}

int main() {
	srand(time(0));
	srand(rand()^283492384792);
	srand(rand()*9323942^2034920);
	scanf("%d%d%d",&n,&start,&x),--start;
	for(int i = 0; i < n; ++i)
		a[i] = i;
	swap(a[0],a[start]);
	for(int i = 1; i < n; ++i)
		swap(a[i],a[i+r()%(n-i)]);
	fill(val,val+n,-1);
	fill(nxt,nxt+n,-1);
	int done = 0;
	for(int i = 0; i < n; ++i) {
		if(done == K) break;
		if(is_nxt[a[i]]) continue;
		printf("? %d\n",a[i]+1),fflush(stdout);
		scanf("%d%d",&val[a[i]],&nxt[a[i]]);
		if(nxt[a[i]] != -1) is_nxt[--nxt[a[i]]] = true;
		++done;
	}
	if(val[start] >= x) {
		printf("! %d\n",val[start]),fflush(stdout);
		return 0;
	}
	int b = start, ub = INF;
	for(int i = 0; i < n; ++i) {
		if(val[i] != -1) {
			if(val[i] >= x && val[i] < ub)
				ub = val[i];
			if(val[i] < x && (val[i] > val[b]))
				b = i;
		}
	}
	for(int i = 1; i < K; ++i) {
		int c = nxt[b];
		if(c == -1) break;
		if(val[c] == -1) {
			printf("? %d\n",c+1),fflush(stdout);
			scanf("%d%d",&val[c],&nxt[c]);
			if(nxt[c] != -1) --nxt[c];
		}
		if(val[c] >= x) {
			ub = min(ub,val[c]);
			break;
		}
		b = c;
	}
	if(ub == INF) printf("! -1\n"),fflush(stdout);
	else printf("! %d\n",ub),fflush(stdout);
}