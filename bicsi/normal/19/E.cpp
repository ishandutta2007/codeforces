#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 500005;

int A[kMaxN], B[kMaxN];

vector<int> G[kMaxN], Tree[kMaxN];
int EdgeIndex[kMaxN];
int D[kMaxN];
char Color[kMaxN];
vector<int> Bad, Answer;

long long needHash = 0;
long long Add[kMaxN];

bool DFSColor(int node, char color) {
	bool ret = true;
	Color[node] = color;

	for(auto ei : G[node]) {
		int vec = node ^ A[ei] ^ B[ei];

		if(!Color[vec]) {
			Tree[node].push_back(vec);
			D[vec] = D[node] + 1;
			EdgeIndex[vec] = ei;

			ret &= DFSColor(vec, color ^ 'r' ^ 'b');
		} else if(D[vec] < D[node] && ei != EdgeIndex[node]) {
			// vec is an ancestor of node
			long long hash = 1LL * rand() * rand();
			Add[vec] -= hash;
			Add[node] += hash;

			if(Color[vec] == Color[node]) {
				ret = false;
				Bad.push_back(ei);
				needHash += hash;
			}
		}
	}

	return ret;
}

long long DFSSolve(int node) {

	long long nowHash = Add[node];
	for(auto vec : Tree[node])
		nowHash += DFSSolve(vec);

	if(nowHash == needHash && D[node])
		Answer.push_back(EdgeIndex[node]);
	return nowHash;
}

int main() {
	//freopen("sol.in", "r", stdin);
	srand(time(0));

	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= m; ++i) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(i);
		G[B[i]].push_back(i);
	}

	int start = -1;

	for(int i = 1; i <= n; ++i) {
		if(!Color[i]) {
			if(DFSColor(i, 'r') == 0) {
				if(start != -1) {
					cout << 0 << endl;
					return 0;
				}
				start = i;
			}
		}
	}

	if(start == -1) {
		cout << m << endl;
		for(int i = 1; i <= m; ++i)
			cout << i << " ";
		cout << endl;

		return 0;
	}

	DFSSolve(start);
	if(Bad.size() == 1) {
		Answer.push_back(Bad.back());
	}

	sort(Answer.begin(), Answer.end());
	assert(unique(Answer.begin(), Answer.end()) == Answer.end());
	
	cout << Answer.size() << endl;
	for(auto x : Answer)
		cout << x << " ";
	cout << endl;

	return 0;
}