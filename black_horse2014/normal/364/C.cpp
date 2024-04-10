#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <utility>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define pb push_back
#define MX 5005
#define rep(i, n) for (int i = 0; i < n; i ++)

using namespace std;

const int p[] = {2, 3, 5, 7, 11, 13};
const int pn = 6;

int K, n, N;
int M;
int cnt[pn];

vector <int> v[pn];
vector <int> :: iterator it;
set <int> S;

int calc(int id, int val) {
	if (val > M) return 0;
	
	rep(i, id + 1) if (val % p[i] == 0) v[i].pb(val);
	
	calc(id, val * p[id]);
	if (id < n - 1) calc(id + 1, val);
}

int find() {
	rep(i, n) v[i].clear();
	memset(cnt, 0, sizeof(cnt));
	S.clear();
	calc(0, 1);
	
	rep(i, n) sort(v[i].begin(), v[i].end());
	
	int id, i;
	
	for (id = n - 1; id >= 0; id --) {
		for (it = v[id].begin(); it != v[id].end(); it ++) {
			if (S.size() == K) break;
			if (cnt[id] >= N) break;
			if (S.find(*it) != S.end()) continue;
			for (i = id; i >= 0; i --) if (*it % p[i] == 0) cnt[i] ++;
			S.insert(*it);
		}	
		if (cnt[id] < N) break;
	}
	
	if (id != -1) return 0;
	
	rep(i, n) {
		if (S.size() == K) return 1;
		for (it = v[i].begin(); it != v[i].end(); it ++) 
			if (S.find(*it) == S.end()) {
				S.insert(*it);
				if (S.size() == K) return 1;
			}
	}

	return 0;
}

int main() {
	
	cin >> K;
	M = 2*K*K;
	N = K + 1 >> 1;

	rep(i, pn) {
		n = i + 1;
		if (find()) break;	
	}
	
	int flag(0);
	while (!S.empty()) {
		if (flag ++) cout << " ";
		cout << *S.begin();
		S.erase(S.begin());
	}
	cout << endl;
	
	return 0;
}