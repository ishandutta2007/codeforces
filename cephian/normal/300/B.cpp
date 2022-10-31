#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int> > graph;
bool hit[50];
graph G;

void cl(vector<int>& v, int a) {
	hit[a] = 1;
	v.push_back(a);
	for (int i = 0; i < G[a].size(); ++i)
		if (!hit[G[a][i]])
			cl(v, G[a][i]);
}

vector<vector<int> > a3, a2;
vector<int> a1;

int main() {
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	G = graph(n, vector<int>());
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		G[--a].push_back(--b);
		G[b].push_back(a);
	}
	fill(hit, hit + n, 0);
	for (int i = 0; i < n; ++i) {
		if (hit[i])
			continue;
		vector<int> v;
		cl(v, i);
		if (v.size() == 3)
			a3.push_back(v);
		else if (v.size() == 2)
			a2.push_back(v);
		else if (v.size() == 1)
			a1.push_back(v[0]);
		else
			goto end;
	}

	if (a2.size() > a1.size())
		goto end;

	while (a2.size()) {
		a3.push_back(*a2.rbegin());
		(*a3.rbegin()).push_back(*a1.rbegin());
		a2.pop_back();
		a1.pop_back();
	}

	while (!a1.empty()) {
		vector<int> v;
		int e = a1.size();
		v.push_back(a1[e - 1]);
		v.push_back(a1[e - 2]);
		v.push_back(a1[e - 3]);
		a1.pop_back();
		a1.pop_back();
		a1.pop_back();
		a3.push_back(v);
	}

	for (int i = 0; i < a3.size(); ++i)
		cout << a3[i][0] + 1 << " " << a3[i][1] + 1 << " " << a3[i][2] + 1 << "\n";

	return 0;
	end: ;
	cout << "-1\n";
	return 0;
}