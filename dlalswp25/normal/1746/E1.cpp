#include <bits/stdc++.h>

using namespace std;

char buf[20];

bool query(vector<int>& q) {
	printf("? %d ", q.size());
	for(int i : q) printf("%d ", i); puts("");
	fflush(stdout);
	scanf("%s", buf);
	if(buf[0] == 'Y') return true;
	else return false;
}

bool guess(int x) {
	printf("! %d\n", x);
	fflush(stdout);
	scanf("%s", buf);
	if(buf[1] == '(') return false;
	else return true;
}

void solve2(vector<int> v) {
	bool t = guess(v[0]);
	if(t) return;
	guess(v[1]);
}

int main() {
	int N; scanf("%d", &N);
	vector<int> V;
	for(int i = 1; i <= N; i++) V.push_back(i);
	while(V.size() > 3) {
		int sz = V.size();
		vector<int> q1, q2, nv;
		for(int i = 0; i < sz / 2; i++) q1.push_back(V[i]);
		bool r1 = query(q1);
		if(r1) {
			for(int i = sz / 2; i < sz * 3 / 4; i++) q2.push_back(V[i]);
			bool r2 = query(q2);
			nv = q1;
			if(r2) {
				for(int i = sz / 2; i < sz * 3 / 4; i++) nv.push_back(V[i]);
			}
			else {
				for(int i = sz * 3 / 4; i < sz; i++) nv.push_back(V[i]);
			}
		}
		else {
			for(int i = 0; i < sz / 4; i++) q2.push_back(V[i]);
			bool r2 = query(q2);
			if(r2) {
				for(int i = 0; i < sz / 4; i++) nv.push_back(V[i]);
			}
			else {
				for(int i = sz / 4; i < sz / 2; i++) nv.push_back(V[i]);
			}
			for(int i = sz / 2; i < sz; i++) nv.push_back(V[i]);
		}
		V = nv;
	}
	if(V.size() == 3) {
		vector<int> q = {V[0]};
		bool r = query(q);
		if(!r) {
			bool r2 = query(q);
			if(!r2) {
				solve2({V[1], V[2]});
				return 0;
			}
		}
		bool t = guess(V[0]);
		if(t) return 0;
		q = {V[1]};
		r = query(q);
		if(r) guess(V[1]);
		else guess(V[2]);
		return 0;
	}
	solve2(V);
	return 0;
}