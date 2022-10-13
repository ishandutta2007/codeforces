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

vector<int> G[500000];
double Prob[500000];
int Size[500000];

void DFS(int node) {
	Size[node] = 1;
	for(auto vec : G[node]) {
		DFS(vec);
		Size[node] += Size[vec];
	}
}
void Comp(int node) {
	Prob[node] += 1.0;
	for(auto vec : G[node]) {
		int rem_size = Size[node] - Size[vec] - 1;
		Prob[vec] = Prob[node] + 0.5 * rem_size;
		Comp(vec);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p;
	cin >> n;

	for(int i = 2; i <= n; ++i) {
		cin >> p;
		G[p].push_back(i);
	}

	DFS(1);
	Comp(1);

	cout << fixed << setprecision(10);
	for(int i = 1; i <= n; ++i)
		cout << Prob[i] << " ";

	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/