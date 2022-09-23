#include <bits/stdc++.h>

using namespace std;

struct tup {
	int x, y, z;
	tup() {
		x = y = z = 0;
	}
	tup(int _x, int _y, int _z) {
		x = _x; y = _y; z = _z;
	}
};

vector<tup> ans;
int A[100005];
int l, r;
queue<int> q;
int D[1010101];
tup P[1010101];
int B[1010101];

int cvt(vector<int>& v) {
	int ret = 0;
	for(int i = 0; i < v.size(); i++) {
		if(v[i]) ret += (1 << i);
	}
	return ret;
}

void norm() {
	while(A[l] == 0 && l <= r) l++;
	while(A[r] == 0 && l <= r) r--;
}

void f(int t) {
	A[t] = 1 - A[t];
}

void g(int p, int q, int r) {
	f(p); f(q); f(r);
	ans.push_back(tup(p, q, r));
}

void yes() {
	puts("YES");
	printf("%d\n", ans.size());
	for(auto i : ans) {
		printf("%d %d %d\n", i.x, i.y, i.z);
	}
}
void no() {
	puts("NO");
}

int main() {
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

	l = 1, r = N;
	const int X = 12;
	if(r - l + 1 > X) norm();

	while(1) {
		if(r - l + 1 <= X) break;

		if(A[l + 1] == 1 && A[l + 2] == 1) {
			g(l, l + 1, l + 2);
			if(r - l + 1 > X) norm();
		}
		else if(A[l + 1] == 0 && A[l + 2] == 0) {
			g(l, l + 3, l + 6);
			if(r - l + 1 > X) norm();
		}
		else if(A[r - 1] == 0 && A[r - 2] == 0) {
			g(r - 6, r - 3, r);
			if(r - l + 1 > X) norm();
		}
		else if(A[r - 1] == 1 && A[r - 2] == 1) {
			g(r - 2, r - 1, r);
			if(r - l + 1 > X) norm();
		}
		else if(A[l + 1] == 0 && A[l + 2] == 1) {
			/*
			if((r - l) % 2 == 0) {
				g(l, (l + r) / 2, r);
				norm();
			}
			else {
				if(A[r - 1] == 1) {
					g(l, (l + r - 1) / 2, r - 1);
					norm();
				}
				else {
					g(l, (l + r - 1) / 2, r - 1);
					g(r - 2, r - 1, r);
					norm();
				}
			}*/
			g(l, l + 2, l + 4);
			if(r - l + 1 > X) norm();
		}
		else {
			/*
			if((r - l) % 2 == 0) {
				g(l, (l + r) / 2, r);
				norm();
			}
			else {
				if(A[r - 1] == 1) {
					g(l, (l + r - 1) / 2, r - 1);
					g(l + 1, (l + r + 1) / 2, r);
					norm();
				}
				else {
					g(l, l + 1, l + 2);
					norm();
				}
			}*/
			if(A[r - 2] == 1 && A[r - 1] == 0) {
				g(r - 4, r - 2, r); if(r - l + 1 > X) norm();
			}
			else if((r - l) % 2 == 0) {
				g(l, (l + r) / 2, r); if(r - l + 1 > X) norm();
				g(l, (l + r) / 2, r); if(r - l + 1 > X) norm();
			}
			else {
				g(l, (l + r - 1) / 2, r - 1);
				g(l + 1, (l + r + 1) / 2, r);
				if(r - l + 1 > X) norm();
			}
		}
	}

	while(l > 1 && r - l + 1 < X) l--;
	while(r < N && r - l + 1 < X) r++;
	int Q = r - l + 1;

	for(int i = 0; i < (1 << Q); i++) D[i] = 987654321;
	D[0] = 0;
	q.push(0);
	while(!q.empty()) {
		int now = q.front(); q.pop();
		int tmp = now;
		vector<int> V; for(int i = 0; i < Q; i++) {
			V.push_back(tmp & 1); tmp >>= 1;
		}
		for(int x = 0; x < Q; x++) {
			for(int y = x + 1; y < Q; y++) {
				if(y + y - x >= Q) continue;
				int z = y + y - x;
				//printf("%d %d %d\n", x, y, z);
				V[x] = 1 - V[x]; V[y] = 1 - V[y]; V[z] = 1 - V[z];
				int nxt = cvt(V);
				V[x] = 1 - V[x]; V[y] = 1 - V[y]; V[z] = 1 - V[z];

				//printf("%d %d %d\n", x, y, z);
				//printf("(%d -> %d)\n", now, nxt);
				if(D[nxt] != 987654321) continue;
				D[nxt] = D[now] + 1; q.push(nxt);
				P[nxt] = tup(x, y, z);
				B[nxt] = now;
			}
		}
	}

	int state = 0;
	for(int i = 0; i < Q; i++) {
		if(A[l + i]) state |= (1 << i);
	}

	if(D[state] == 987654321) no();
	else {
		while(state) {
			//printf("%d\n", state);
			ans.push_back(tup(P[state].x + l, P[state].y + l, P[state].z + l));
			state = B[state];
		}
		yes();
	}
	/*
	while(r - l + 1 > 3) {
		g(l, l + 1, l + 2);
		norm();
	}
	norm();*/

	return 0;
}