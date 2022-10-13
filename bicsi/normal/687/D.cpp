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

const int kMaxM = 1000005;
const int kMaxN = 1005;

int A[kMaxM], B[kMaxM], C[kMaxM], Order[kMaxM];

int Set[kMaxN];
vector<int> Nodes[kMaxN];
bool Color[kMaxN];

int n;

bool ProcessEdge(int ei) {
	//cerr << "Processing edge " << ei << "...\n";
	
	int a = A[ei], b = B[ei];
	if(Set[a] == Set[b]) 
		return Color[a] != Color[b];

	// Avem union

	bool toxor = (Color[a] == Color[b]);
	a = Set[a]; b = Set[b];

	if(Nodes[a].size() > Nodes[b].size())
		swap(a, b);

	for(auto x : Nodes[a]) {
		Set[x] = b;
		Nodes[b].push_back(x);
		Color[x] ^= toxor;
	}

	return true;
}

void Init() {
	for(int i = 1; i <= n; ++i) {
		Set[i] = i;
		Nodes[Set[i]].clear();
		Nodes[Set[i]].push_back(i);
		Color[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int m, q;
	scanf("%d %d %d", &n, &m, &q);

	for(int i = 1; i <= m; ++i) {
		scanf("%d %d %d", A + i, B + i, C + i);
		Order[i] = i;
	}

	sort(Order + 1, Order + m + 1, [](int a, int b) {
		return C[a] > C[b];
	});

	

	for(int i = 1; i <= q; ++i) {
		int l, r;
		int sol = -1;
		scanf("%d %d", &l, &r);

		//cerr << "\n\n\n";

		Init();

		for(int ii = 1; ii <= m; ++ii) {
			int i = Order[ii];

			if(i >= l && i <= r)
				if(!ProcessEdge(i)) {
					sol = C[i];
					//cerr << "BAD!\n";
					break;
				}
		}
		printf("%d\n", sol);
	}
	
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/