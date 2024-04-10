#include <bits/stdc++.h>
using namespace std;

//   

vector<int> lists[10009]; bool used[10009]; int match[10009];

bool DFS(int V) {
    used[V] = true;
    for (int i = 0; i < lists[V].size(); i++) {
        int u = lists[V][i]; int w = match[u];
        if (w < 0 || (used[w] == false && DFS(w) == true)) {
            match[V] = u;
            match[u] = V;
            return true;
        }
    }
    return false;
}

void inits() {
	for (int i = 0; i <= 10008; i++) used[i] = false;
}

int N, M, D, P[10009], C[10009], K[10009], ans = 0, finalans[10009];
int BASE = 5002; vector<int> pot[10009]; bool forced[10009];

int main() {
	for (int i = 0; i <= 10008; i++) match[i] = -1;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> P[i];
	for (int i = 1; i <= N; i++) cin >> C[i];
	cin >> D;
	for (int i = 1; i <= D; i++) { cin >> K[i]; forced[K[i]] = true; }
	for (int i = 1; i <= N; i++) {
		if (forced[i] == false) pot[P[i]].push_back(i);
	}
	
	int cx = 0;
	for (int i = D; i >= 1; i--) {
		while (true) {
			if (ans < cx) break;
			vector<int>vec2;
			for (int j = 0; j < pot[cx].size(); j++) {
				lists[C[pot[cx][j]]].push_back(cx + BASE);
				lists[cx + BASE].push_back(C[pot[cx][j]]);
				vec2.push_back(C[pot[cx][j]]);
				vec2.push_back(cx + BASE);
			}
			for (int pos : vec2) {
				inits();
				if (match[pos] == -1) ans += (int)DFS(pos);
			}
			cx++;
		}
		finalans[i] = cx - 1;
		int id = K[i];
		if (P[id] >= cx) pot[P[id]].push_back(id);
		
		vector<int> vec1;
		if (P[id] < cx) {
			lists[C[id]].push_back(P[id] + BASE); 
			lists[P[id] + BASE].push_back(C[id]);
			vec1.push_back(C[id]);
			vec1.push_back(P[id] + BASE);
		}
		
		for (int pos : vec1) {
			inits();
			if (match[pos] == -1) ans += (int)DFS(pos);
		}
	}
	for (int i = 1; i <= D; i++) printf("%d\n", finalans[i]);
	return 0;
}