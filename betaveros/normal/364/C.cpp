#include <cstdio>
#include <cinttypes>
#include <map>
#include <cstring>
#include <algorithm>
#include <queue>
#define fori(i,s,e) for (int i = s; i < ((int)e); i++)

using namespace std;

class smooth {
	vector<int> ps;
	priority_queue<int,vector<int>,greater<int> > q;
	public:
	smooth(vector<int> pps): ps(pps) { q.push(1); }
	int nxt() {
		int ret = q.top();
		q.pop();
		fori (i, 0, ps.size()) {
			q.push(ret * ps[i]);
			if (ret % ps[i] == 0) break;
		}
		return ret;
	}
};
void makeSet5(int k) {
	vector<int> pps;
	pps.push_back(2);
	pps.push_back(3);
	pps.push_back(5);
	smooth s(pps);
	fori (_, 0, 20) s.nxt();
	fori (i, 0, k) {
		if (i) printf(" ");
		printf("%d", s.nxt());
	}
	printf("\n");
}
void makeSet11(int k) {
	// ok above ~300
	vector<int> pps;
	pps.push_back(2);
	pps.push_back(3);
	pps.push_back(5);
	pps.push_back(7);
	pps.push_back(11);
	smooth s(pps);
	fori (_, 0, 1115) s.nxt();
	fori (i, 0, k) {
		if (i) printf(" ");
		printf("%d", s.nxt());
	}
	printf("\n");
}

int main() {
	int k;
	scanf("%d", &k);
	if (k < 300) makeSet5(k);
	else makeSet11(k);
}