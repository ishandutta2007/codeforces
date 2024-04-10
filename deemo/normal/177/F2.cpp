#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

#define PQ priority_queue

const int XX = 1e7 + 7e6;
const int MAXN = 20;

int n, m, k;
int adj[MAXN], w[MAXN][MAXN], ms;
PQ<int> hp;

void gen(int cur = 0, int sm = 0, int ms = 0){
	if (hp.size() == k){
		if (hp.top() <= sm)	return;
		hp.pop();
		hp.push(sm);
	}
	else	hp.push(sm);

	for (; cur < n; cur++){
		int z = adj[cur]&(adj[cur]^ms);
		while (z){
			int id = z&-z;
			z-=id;
			gen(cur + 1, sm + w[cur][__builtin_ctz(id)], ms | id);
		}
	}
}

int main(){
	cin >> n >> m >> k;
	while (m--){
		int a, b, c;	cin >> a >> b >> c, a--, b--;
		w[a][b] = c;
		adj[a] |= 1<<b;
	}
	gen();
	cout << hp.top() << "\n";
	return 0;
}