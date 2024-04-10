/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*******************Debugging defines*************************/

#define ok_dump() cerr<<"OK\n"
#define var_dump(x) cerr<<#x": "<<x<<'\n'
#define arr_dump(x, n) {cerr<<#x"[]: ";\
	for(int _=1;_<=n;++_) cerr<<x[_]<<" ";cerr<<'\n';}

/*************************************************************/

char G[1005][1005];

void addEdge(int a, int b) {
	G[a][b] = G[b][a] = 'Y';
}

int main() {	
//	assert(freopen("input.txt", "r", stdin));
	int k;
	cin >> k;

	int node = 104;
	int len = 1;
	int leg = 100;

	for(int i = 3; i <= 102; ++i) {
		addEdge(i, i - 1);
	}

	addEdge(1, 104);

	//Drumuri de lungime 100
	for(int step = 0; (1 << step) <= k; ++step) {

		if(k & (1 << step)) {
			addEdge(node, leg);
		}

		addEdge(node, node + 1);
		addEdge(node, node + 2);
		addEdge(node + 1, node + 3);
		addEdge(node + 2, node + 3);

		node = node + 3;
		len += 2;
		leg -= 2;
	}

	for(int i = 1; i <= node; ++i)
		for(int j = 1; j <= node; ++j) {
			if(G[i][j] == 0) {
				G[i][j] = 'N';
			}
		}

	cout << node << '\n';

	for(int i = 1; i <= node; ++i)
		cout << G[i] + 1 << '\n';
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/