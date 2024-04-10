#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <deque>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define allof(s) (s).begin(), (s).end()

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

const int N = 200008;
int n;
vector<int> graph[N];

vector<int> order;
int invOrder[N];

deque<int> q;
bool visited[N];

bool solve() {
	q.push_back(1);
	int orderIx = 0;
	while (q.size()) {
		int next = q.front();
		q.pop_front();

		assert(!visited[next]);
		visited[next] = true;

		if (order[orderIx] != next) {
			return false;
		}
		orderIx++;

		for (int w : graph[next]) {
			if (!visited[w]) {
				q.push_back(w);
			}
		}
	}

	assert(orderIx == n);
	return true;
}

int main() {
	cin >> n;
	fori (i, 0, n-1) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	fori (i, 0, n) {
		int x;
		cin >> x;
		invOrder[x] = (int) order.size();
		order.push_back(x);
	}

	fori (i, 1, n+1) {
		sort(allof(graph[i]), [](int a, int b){
			return invOrder[a] < invOrder[b];
		});
	}

	if (solve()) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}