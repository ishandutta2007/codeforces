#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define M 300001

int par[M], centroid[M], size[M], maxi[M],n,q;
vector<int> child[M];

void cz(int node) { 
	size[node] ++;
	for (int i: child[node]) cz(i), size[node] += size[i];
}

void calc(int node) {
	if (child[node].size() == 0) {
		centroid[node] = node; 
		return;
	}
	for (int i: child[node]) {
		calc(i);
		if (size[i] > size[maxi[node]]) maxi[node] = i;
	}
	if (2*size[maxi[node]] <= size[node]) {
		centroid[node] = node;
		return;
	}
	int cur = centroid[maxi[node]];
	while (2*size[cur] < size[node]) cur = par[cur];
	centroid[node] = cur;
}

int main() {
	cin >> n >> q;
	FOR(i,2,n+1) cin >> par[i], child[par[i]].push_back(i);
	cz(1), calc(1);
	F0R(i,q) {
		int x; cin >> x;
		cout << centroid[x] << endl;
	}
}