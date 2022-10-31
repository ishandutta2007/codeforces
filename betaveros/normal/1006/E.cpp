#include <iostream>
#include <vector>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define allof(s) (s).begin(), (s).end()

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

const int N = 200008;
int n, nQueries;
vector<int> graph[N];
int subtreeSize[N];
vector<int> order;
int invOrder[N];

void dfs(int v) {
	order.push_back(v);
	int size = 1;
	for (int child : graph[v]) {
		dfs(child);
		size += subtreeSize[child];
	}
	subtreeSize[v] = size;
	// return size;
}

int main() {
	cin >> n >> nQueries;
	fori (i, 2, n+1) {
		int p;
		cin >> p;
		graph[p].push_back(i);
	}
	dfs(1);

	fori (i, 0, n) {
		invOrder[order[i]] = i;
	}
	
	fori (i, 0, nQueries) {
		int start, count;
		cin >> start >> count;
		cout <<
			((count <= subtreeSize[start])
			?
			order[invOrder[start] + count - 1]
			:
			-1);
		cout << "\n";
	}
}