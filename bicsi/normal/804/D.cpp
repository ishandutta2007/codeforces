#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 500000;

int Link[kMaxN], Down[kMaxN], Viz[kMaxN], Depth[kMaxN], CC[kMaxN], Diam[kMaxN];
vector<int> G[kMaxN], Nodes[kMaxN], Freq[kMaxN];
vector<double> Suff[kMaxN];
int n;

int DFSDown(int node, int par, int cc) {
	CC[node] = cc;
	Nodes[cc].push_back(node);

	int ret = 0;

	if(par != -1)
		G[node].erase(find(G[node].begin(), G[node].end(), par));
	
	for(auto vec : G[node]) {
		if(vec != par)
			ret = max(ret, 1 + DFSDown(vec, node, cc));
	}

	Down[node] = ret;
	return ret;
}
void DFSUp(int node, int up) {
	// cerr << node << ": " << up << endl;
	Depth[node] = max(Down[node], up);
	if(G[node].empty()) return;
	
	if(G[node].size() == 1) {
		DFSUp(G[node].back(), up + 1);
		return;
	}

	// more than 2
	sort(G[node].begin(), G[node].end(), [](int a, int b) {
		return Down[a] > Down[b];
	});

	for(auto vec : G[node]) {
		DFSUp(vec, 1 + max(up, 1 + Down[G[node][vec == G[node][0]]]));
	}
}

void ComputeDepths() {
	int ccs = 0;
	for(int i = 1; i <= n; ++i) {
		if(!CC[i]) {
			DFSDown(i, -1, ++ccs);
			DFSUp(i, 0);

			// Get diam
			for(auto node : Nodes[ccs])
				Diam[ccs] = max(Diam[ccs], Depth[node]);
			Freq[ccs].resize(Diam[ccs] + 1);
			Suff[ccs].resize(Diam[ccs] + 2);
			for(auto node : Nodes[ccs])
				Freq[ccs][Depth[node]] += 1;
		
			for(int i = Diam[ccs]; i >= 0; --i)
				Suff[ccs][i] = Suff[ccs][i + 1] + Freq[ccs][i];
			for(int i = Diam[ccs]; i >= 0; --i)
				Suff[ccs][i] += Suff[ccs][i + 1];
		}		
	}
}

double Compute(int a, int b) {
	if(a == b) return -1;
	if(Diam[a] > Diam[b]) swap(a, b);
/*
	cerr << "Computing for: " << a << " " << b << endl;
	cerr << "A.k.a.: {";
	for(auto x : Nodes[a]) cerr << x << " "; 
	cerr << "}, {";
	for(auto x : Nodes[b]) cerr << x << " "; 
	cerr << "}\n";
	cerr << "Diams: " << Diam[a] << " " << Diam[b] << endl;

	cerr << "Freq arrays:\n";
	for(auto x : Freq[a]) cerr << x << " "; cerr << endl;
	for(auto x : Suff[b]) cerr << x << " "; cerr << endl;
	cerr << "------\n";
*/
	double ans = 0;
	for(int d1 = 0, d2 = Diam[b]; d1 <= Diam[a] && d2 >= 0; ++d1, --d2) {
		ans += Suff[b][d2] * Freq[a][d1];	
	}
	ans /= Nodes[a].size() * Nodes[b].size();
	// cerr << "ans without diam: " << ans << endl;

	return Diam[b] + ans;
}

map<pair<int, int>, double> PreComp;
double Solve(int a, int b) {
	a = CC[a];
	b = CC[b];

	if(a > b) swap(a, b);
	if(PreComp.find({a, b}) != PreComp.end())
		return PreComp[{a, b}];

	PreComp[{a, b}] = Compute(a, b);
	return PreComp[{a, b}];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m, q;
	cin >> n >> m >> q;

	for(int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	ComputeDepths();

	cerr << "Computed Depths!\n";
	// cout << Diam[1] << endl;

	cout << fixed << setprecision(12);
	while(q--) {
		int a, b;
		cin >> a >> b;
		double ret = Solve(a, b);
		if(ret < -0.5) cout << -1 << '\n';
		else cout << ret << '\n';
	}

	return 0;
}