//*
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <functional>
#define MOD 1000000007
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef set<int>::iterator siit;

char ANS[400050];
set <pair<pii, int>> in;
set <int> conn[400050];
int cnt[400050];

vector <pii> V;
int Q[1000050];

int DFS(int node, int chk) {
	while (!conn[node].empty()) {
		set <int>::iterator it = conn[node].begin();
		int t = *it;
		conn[node].erase(it);
		conn[t].erase(node);

		chk = DFS(t, chk);

		pii tmp;
		if (node > 200000) tmp = pii(t, node - 200000);
		else tmp = pii(node, t - 200000);

		set <pair<pii, int>>::iterator it2 = in.lower_bound(make_pair(tmp, 0));
		ANS[it2->second] = (chk == 1) ? 'r' : 'b';
		chk = 1 - chk;
	}
	return chk;
}

int X[400050];
int main() {
	int N, i, t1, t2;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &t1, &t2);
		in.insert(make_pair(pii(t1, t2), i));
		conn[t1].insert(t2+200000);
		conn[t2 + 200000].insert(t1);
	}

	// deleting edges until all vertex's degree become even
	int st = 1, en = 1;
	for (i = 1; i <= 400000; i++) {
		if (conn[i].size() % 2 == 1) Q[en++] = i;
	}
	while (st < en) {
		t1 = Q[st];
		if (conn[t1].size() % 2 == 0) {
			st++;
			continue;
		}
		set <int>::iterator it = conn[t1].begin();
		t2 = *it;

		V.push_back(pii(t1, t2));
		
		conn[t1].erase(t2);
		conn[t2].erase(t1);
		if (conn[t2].size() % 2 == 1) Q[en++] = t2;
		st++;
	}
	
	// Euler Path
	for (i = 1; i <= 400000; i++) {
		if (conn[i].size() == 0) continue;
		DFS(i, 0);
	}

	// updating other values
	while (!V.empty()) {
		pii tmp = V.back();
		pii tmp2;
		V.pop_back();
		if (tmp.first > 200000) tmp2 = pii(tmp.second, tmp.first - 200000);
		else tmp2 = pii(tmp.first, tmp.second - 200000);
		
		set <pair<pii, int>>::iterator it = in.lower_bound(make_pair(tmp2, 0));
		if (X[tmp.second] == 1) {
			ANS[it->second] = 'b';
			X[tmp.first]--;
			X[tmp.second]--;
		}
		else {
			ANS[it->second] = 'r';
			X[tmp.first]++;
			X[tmp.second]++;
		}
	}
	printf("%s", ANS);
	return 0;
}
//*/