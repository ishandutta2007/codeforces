#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;
typedef pair<ld, ld> pdd;

int c1;

struct state {
	int h1, a1, h2, a2, level;
	int laststate;
	state() {}
	state(int a, int b, int c, int d, int e, int f)
		:h1(a), a1(b), h2(c), a2(d), level(e), laststate(f) {}
};

/*
void bfs(int h1i, a1i, h2i, a2i) {
	queue<int> q;
	vector<state> states;
	map<state, int> Map;
	states.push_back(state(h1i, a1i, h2i, a2i, 0, -1));
	Map[states[0]] = 0;

	state fin;
	
	q.push_back(0);
	while(q.size() > 0) {
		st = states[q.front()];
		q.pop();
		// try each of the 
	}
}
*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int h1, a1, h2, a2;
	cin >> h1 >> a1 >> c1 >> h2 >> a2;
	vector<string> options;
	while(h2 > 0) {
		if(h1 > a2 || (h2-a1 <= 0)) {
			// attack
			h2 -= a1;
			options.push_back("STRIKE");
		} else {
			h1 += c1;
			options.push_back("HEAL");
		}

		if(h2 <= 0) break;
		
		h1 -= a2;

		if(h1 <= 0) exit(1);
	}

	cout << options.size() << endl;
	for(int i=0;i<options.size();++i)
		cout << options[i] << endl;

	return 0;
}