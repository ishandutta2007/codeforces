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

const int kMaxN = 500000;

int Link[kMaxN];
int Find(int x) {
	if(Link[x] == -1) return x;
	return Link[x] = Find(Link[x]);
}
void Union(int a, int b) {
	a = Find(a); b = Find(b);
	if(a != b) Link[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Comment these lines before submitting
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);

	// Start code here
	int n;
	cin >> n;

	fill(Link, Link + n, -1);

	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		Union(i, x - 1);
	}

	set<int> Set;
	for(int i = 0; i < n; ++i) {
		Set.insert(Find(i));
	}
	cout << Set.size() << endl;


	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/