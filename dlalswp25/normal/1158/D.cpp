#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;

struct point {
	int id;
	ll x, y;
	bool chk;
}P[2010];

ll cross(ll x1, ll y1, ll x2, ll y2) {
	return x1 * y2 - x2 * y1;
}
ll ccw(ll x, ll y, ll x1, ll y1, ll x2, ll y2) {
	ll t = cross(x1 - x, y1 - y, x2 - x, y2 - y);
	if(t == 0) return 0;
	if(t > 0) return 1;
	return -1;
}

int pv = 0;

bool cmp(point s, point t) {
	if(ccw(P[N + 1].x, P[N + 1].y, s.x, s.y, t.x, t.y) > 0) return true;
	return false;
}

vector<int> v;
char S[2010];

int main() {
	scanf("%d", &N);
	P[N + 1].x = P[N + 1].y = -2000000000;
	for(int i = 1; i <= N; i++) {
		P[i].id = i;
		scanf("%lld%lld", &P[i].x, &P[i].y);
	}
	scanf("%s", S + 1);
	S[0] = 'L';
	pv = 0;
	for(int i = 0; i < N; i++) {
		//sort(P + 1, P + N + 1, cmp);
		int j = 1;
		for(; j <= N; j++) if(!P[j].chk) break;
		if(S[i] == 'L') {
			for(int k = 1; k <= N; k++) {
				if(P[k].chk) continue;
				if(k == j) continue;
				if(ccw(P[N + 1].x, P[N + 1].y, P[j].x, P[j].y, P[k].x, P[k].y) < 0) j = k;
			}
		}
		else {
			for(int k = 1; k <= N; k++) {
				if(P[k].chk) continue;
				if(k == j) continue;
				if(ccw(P[N + 1].x, P[N + 1].y, P[j].x, P[j].y, P[k].x, P[k].y) > 0) j = k;
			}
		}
		P[N + 1] = P[j];
		v.push_back(P[j].id);
		P[j].chk = true;
	}
	for(int i : v) printf("%d ", i); puts("");
	return 0;
}