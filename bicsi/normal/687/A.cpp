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

vector<int> A, B, G[100005];
bool Viz[100005];
bool Color[100005];

void dfs(int node, int col) {
	Viz[node] = 1;
	if(col == 0) A.push_back(node);
	else B.push_back(node);
	Color[node] = col;

	for(auto vec : G[node]) {
		if(!Viz[vec])
			dfs(vec, col ^ 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	while(m--) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for(int i = 1; i <= n; ++i)
		if(!Viz[i])
			dfs(i, 0);

	bool good = true;
	for(int i = 1; i <= n; ++i)
		for(auto vec : G[i]) {
			if(Color[vec] == Color[i])
				good = false;
		}

	if(good) {
		//cout << "Yes\n";
		cout << A.size() << '\n';
		for(auto a : A) cout << a << " ";
		cout << '\n' << B.size() << '\n';
		for(auto b : B) cout << b << " ";
		cout << '\n';
	} else {
		cout << "-1\n";
	}
	
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/