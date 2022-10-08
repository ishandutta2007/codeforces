//*
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <time.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef set <int>::iterator siit;
typedef set <ll>::iterator slit;

typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 32768;
const int MOD = 1000000007;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

vector <pair<int, pil>> conn[300050];

pair<pli, int> dis[300050];
bool chk[300050];
priority_queue <pli, vector <pli>, greater<pli>> H;
vector <int> ANS_list;
int main() {
	int N, M, i, j, st;
	int t1, t2;
	ll t3;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		scanf("%d %d %lld", &t1, &t2, &t3);
		conn[t1].push_back(make_pair(i, pil(t2, t3)));
		conn[t2].push_back(make_pair(i, pil(t1, t3)));
	}
	scanf("%d", &st);

	// Dijkstra
	ll ANS = 0;
	for (i = 1; i <= N; i++) dis[i] = make_pair(pli(LL_INF, 0), 0);
	dis[st] = make_pair(pli(0, st), 0);
	H.push(pli(0, st));
	
	while (!H.empty()) {
		pli tmp = H.top();
		H.pop();
		if (chk[tmp.second]) continue;
		chk[tmp.second] = true;
		if (tmp.first != 0) {
			ANS += dis[tmp.second].first.first - dis[dis[tmp.second].first.second].first.first;
			ANS_list.push_back(dis[tmp.second].second);
		}

		for (i = 0; i < conn[tmp.second].size(); i++) {
			int t1 = conn[tmp.second][i].second.first;
			ll t2 = conn[tmp.second][i].second.second;
			if (chk[t1]) continue;
			if (t2 + tmp.first < dis[t1].first.first || (t2 + tmp.first == dis[t1].first.first && dis[dis[t1].first.second].first.first < dis[tmp.second].first.first)) {
				dis[t1].first = pli(t2 + tmp.first, tmp.second);
				dis[t1].second = conn[tmp.second][i].first;
				H.push(pli(t2 + tmp.first, t1));
			}
		}
	}

	printf("%lld\n", ANS);
	for (i = 0; i < ANS_list.size(); i++) printf("%d ", ANS_list[i]);
	return 0;
}

//*/