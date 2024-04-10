/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*******************Debugging defines*************************/

#define ok_dump() cerr<<"OK\n"
#define var_dump(x) cerr<<#x": "<<x<<'\n'
#define arr_dump(x, n) do{cerr<<#x"[]: ";\
     for(int _=0;_<n;++_) cerr<<x[_]<<" ";cerr<<'\n';}while(0)

/*************************************************************/

const int kMaxN = 300005;
vector<int> G[kMaxN];
int Parent[25][kMaxN], Diam[kMaxN], Centroid[kMaxN], Low[kMaxN];
int D[kMaxN], Size[kMaxN];

int kth(int node, int k) {
	for(int i = 0; k; ++i) {
		if(k & 1)
			node = Parent[i][node];
		k /= 2;
	}
	return node;
}

void DFS(int node) {
	Centroid[node] = node;
	Low[node] = node;
	Size[node] = 1;

	int go = 0;
	for(auto vec : G[node]) {
		D[vec] = D[node] + 1;
		DFS(vec);
		Size[node] += Size[vec];
		if(Size[vec] > Size[go]) {
			go = vec;
		}
	}

	if(go == 0) return;
	Low[node] = Low[go];

	int ans = Low[node];
	for(int i = 20; i >= 0; --i) {
		int ask = Parent[i][ans];
		if(ask == 0 || D[ask] <= D[node]) continue;

		if(Size[ask] <= Size[node] / 2)
			ans = ask;
	}

	Centroid[node] = Parent[0][ans];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	scanf("%d %d", &n, &m);


	for(int i = 2; i <= n; ++i) {
		scanf("%d", &Parent[0][i]);
		G[Parent[0][i]].push_back(i);
	}


	for(int i = 1; i <= 20; ++i) {
		for(int node = 1; node <= n; ++node) {
			Parent[i][node] = Parent[i - 1][Parent[i - 1][node]];
		}
	}

	DFS(1);

	//arr_dump(Centroid, n + 1);

	int a;
	while(m--) {
		scanf("%d", &a);
		printf("%d\n", Centroid[a]);
	}
	
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/