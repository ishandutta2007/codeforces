#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;

int par[505];
int sz[505];
vector<int> ch[505];

vector<int> S;
int getq;

priority_queue<pii, vector<pii>, greater<pii> > pq;

void query(int v) {
	printf("%d\n", S.size());
	for(int i : S) printf("%d ", i);
	puts("");
	printf("1\n1\n");
	printf("%d\n", v);
	fflush(stdout);
	scanf("%d", &getq);
}

void dnc(vector<pii> cand, int v, int num) {
	//for(pii i : cand) printf("%d ", i.first); puts("cand");
	if(!num) return;
	if(cand.size() == 0) return;
	int s = 0;
	for(pii i : cand) s += i.second;
	if(s == num) {
		for(pii i : cand) par[i.first] = v;
		return;
	}
	//puts("go");
	if(cand.size() == 1) return;
	int n = cand.size();
	//printf("%d Nnnnn\n", n);
	vector<pii> lft;
	vector<pii> rgt;
	S.clear();
	for(int i = 0; i < n / 2; i++) {
		lft.push_back(cand[i]);
		for(int j : ch[cand[i].first]) {
			S.push_back(j);
		}
	}

	query(v);
	int tmp = getq;
	dnc(lft, v, getq);

	for(int i = n / 2; i < n; i++) {
		rgt.push_back(cand[i]);
	}
	dnc(rgt, v, num - tmp);
}

int main() {
	scanf("%d", &N);
	sz[1] = N;

	for(int i = 2; i <= N; i++) {
		S.clear();
		for(int j = 2; j <= N; j++) S.push_back(j);
		query(i);
		sz[i] = getq;
	}

	for(int i = 2; i <= N; i++) pq.push({sz[i], i});
	for(int i = 1; i <= N; i++) ch[i].push_back(i);

	while(pq.size()) {
		int nsz = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		vector<pii> v;

		for(int i = 2; i <= N; i++) {
			if(par[i]) continue;
			if(i == now) continue;
			v.push_back({i, sz[i]});
		}
		dnc(v, now, nsz - 1);
		for(int i = 1; i <= N; i++) {
			if(par[i] == now) {
				ch[now].push_back(i);
				for(int j : ch[i]) ch[now].push_back(j);
			}
			sort(ch[now].begin(), ch[now].end());
			ch[now].erase(unique(ch[now].begin(), ch[now].end()), ch[now].end());
		}
	}

	for(int i = 2; i <= N; i++) if(!par[i]) par[i] = 1;

	// for(int i = 2; i <= N; i++) {
	// 	printf("%d: ", i);
	// 	for(int j : ch[i]) printf("%d ", j); puts("");
	// }

	puts("ANSWER");
	for(int i = 2; i <= N; i++) printf("%d %d\n", i, par[i]);
	fflush(stdout);

	return 0;
}