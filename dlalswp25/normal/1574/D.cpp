#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
vector<int> A[15];
map<vector<int>, int> mp;
vector<int> X[2020202];
bool chk[2020202];
bool ban[2020202];
int id;
priority_queue<pii> pq;

int get_id(vector<int>& v) {
	auto it = mp.find(v);
	if(it != mp.end()) return it -> second;
	mp[v] = ++id;
	X[id] = v;
	return id;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int k; scanf("%d", &k);
		for(int j = 0; j < k; j++) {
			int x; scanf("%d", &x);
			A[i].push_back(x);
		}
	}

	scanf("%d", &M);
	for(int i = 1; i <= M; i++) {
		vector<int> v;
		for(int j = 1; j <= N; j++) {
			int x; scanf("%d", &x);
			v.push_back(x);
		}
		ban[get_id(v)] = true;
	}

	int s = 0;
	for(int i = 1; i <= N; i++) s += A[i].back();
	vector<int> v;
	for(int i = 1; i <= N; i++) v.push_back(A[i].size());
	int t = get_id(v);
	chk[t] = true;
	pq.emplace(s, t);

	// for(int i = 1; i <= id; i++) {
	// 	printf("%d - ", i);
	// 	for(int j : X[i]) printf("%d ", j); puts("");
	// }

	while(pq.size()) {
		s = pq.top().first;
		t = pq.top().second;
		v = X[t];
		if(!ban[t]) {
			for(int i : v) printf("%d ", i); puts("");
			break;
		}
		pq.pop();

		for(int i = 0; i < N; i++) {
			if(v[i] <= 1) continue;
			s -= A[i + 1][v[i] - 1];
			s += A[i + 1][v[i] - 2];
			v[i]--;
			t = get_id(v);
			if(!chk[t]) {
				pq.emplace(s, t);
				chk[t] = true;
			}
			v[i]++;
			s += A[i + 1][v[i] - 1];
			s -= A[i + 1][v[i] - 2];
		}
	}

	return 0;
}