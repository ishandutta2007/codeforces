#include <iostream>
#include <vector>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define allof(s) (s).begin(), (s).end()

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

const int N = 108;
int n;
int m;
vector<int> graph[N];
int deg[N];
bool exists[N];

int main() {
	cin >> n >> m;
	fori (i, 0, m) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
		deg[x]++;
		deg[y]++;
	}

	fori (i, 0, n) exists[i] = true;

	int nSteps = 0;
	while (true) {
		vector<int> toDelete;
		fori (i, 0, n) {
			if (exists[i] && deg[i] == 1) {
				toDelete.push_back(i);
			}
		}
		if (!toDelete.size()) {
			break;
		}
		for (const int &i : toDelete) {
			for (const int &j : graph[i]) {
				if (exists[j]) {
					deg[j]--;
				}
			}
			deg[i] = 0;
			exists[i] = false;
		}
		nSteps++;
	}

	cout << nSteps << "\n";
}