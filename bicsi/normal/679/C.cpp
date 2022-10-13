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

char A[505][505];
int Node[505][505];
int Boss[505 * 505];
int Size[505 * 505];
int Count[505 * 505];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int Find(int node) {
	if(Boss[node]) return Boss[node] = Find(Boss[node]);
	return node;
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if(a != b)
		Boss[a] = b;
}

int ans_now;
void Insert(int a, int b) {
	if(A[a][b] != '.') return;
	int node = Find(Node[a][b]);

	if(++Count[node] == 1)
		ans_now += Size[node];
}

void Erase(int a, int b) {
	if(A[a][b] != '.') return;
	int node = Find(Node[a][b]);
	
	if(--Count[node] == 0)
		ans_now -= Size[node];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; ++i) {
		cin >> (A[i] + 1);
	}

	int nodes = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			Node[i][j] = ++nodes;
	assert(nodes == n * n);

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(A[i][j] != '.') continue;

			for(int d = 0; d < 4; ++d) {
				int newi = i + dx[d];
				int newj = j + dy[d];

				if(A[newi][newj] != '.') continue;
				Union(Node[i][j], Node[newi][newj]);
			}
		}
	}

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(A[i][j] == '.')
				Size[Find(Node[i][j])] += 1;
/*
	for(int i = 1; i <= n; ++i, cerr << endl)
		for(int j = 1; j <= n; ++j)
			cerr << Find(Node[i][j]) << " ";
*/

	int sol = 0, countX = 0;
	for(int lb = 1, ub = m; ub <= n; ++lb, ++ub) {
		countX = 0;
		ans_now = 0;

		memset(Count, 0, sizeof(Count));

		for(int j = 1; j <= n; ++j) {
			for(int k = lb; k <= ub; ++k) {
				countX += (A[k][j] == 'X');
				Insert(k, j);
			}
			Insert(lb - 1, j);
			Insert(ub + 1, j);

			if(j < m) continue;

			for(int k = lb; k <= ub; ++k) {
				Insert(k, j - m);
				Insert(k, j + 1);
			}

			sol = max(sol, ans_now + countX);

			//cout << ans_now + countX << " ";

			for(int k = lb; k <= ub; ++k) {
				Erase(k, j - m);
				Erase(k, j + 1);
			}

			for(int k = lb; k <= ub; ++k) {
				countX -= A[k][j - m + 1] == 'X';
				Erase(k, j - m + 1);
			}
			Erase(lb - 1, j - m + 1);
			Erase(ub + 1, j - m + 1);
		}

		//cout << endl;
	}

	cout << sol;
	

	
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/