#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 111111;
const int C = 4;
const long long INF = (1LL << 60);

struct SAM {
	SAM *next[C], *fail;
	int len;	
	inline void clear() {
		for(int i = 0; i < C; i++) {
			next[i] = NULL;
		}
		fail = NULL;
	}
};
SAM *head, *tail, pool[N * 2];
int used, dist[N * 2], visit[N * 2];

SAM *newNode() {
	pool[used].clear();
	return &pool[used++];
}

long long n;
char buf[N];

struct Matrix {
	long long dat[4][4];
	Matrix() {
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++) {
				dat[i][j] = INF;
			}
	}
	
	void clear() {
		for(int i = 0; i < C; i++)
			for(int j = 0; j < C; j++) {
				dat[i][j] = 0;
			}
	}
	
	friend Matrix operator * (const Matrix &a, const Matrix &b) {
		Matrix c;
		for(int i = 0; i < C; i++)
			for(int j = 0; j < C; j++) {
				for(int k = 0; k < C; k++) {
					c.dat[i][j] = min(c.dat[i][j], a.dat[i][k] + b.dat[k][j]);
				}
			}
		return c;
	}
};

void add(int x) {
	SAM *np = newNode(), *p = tail;
	tail = np;
	np->len = p->len + 1;
	for(; p && !p->next[x]; p = p->fail)
		p->next[x] = np;
	if (!p)
		np->fail = head;
	else if (p->len + 1 == p->next[x]->len)
		np->fail = p->next[x];
	else {
		SAM *q = p->next[x], *nq = newNode();
		*nq = *q; 
		nq->len = p->len + 1;
		q->fail = np->fail = nq;
		for(; p && p->next[x] == q; p = p->fail)
			p->next[x] = nq;
	}
}

long long solve(long long times, Matrix cost) {
	Matrix base;
	base.clear();
	while(times) {
		if (times & 1) {
			base = base * cost;
		}
		times >>= 1;
		cost = cost * cost;
	}
	long long minValue = INF;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++) {
			minValue = min(minValue, base.dat[i][j]);
		}
	return minValue;
}

int main() {
	cin >> n;
	scanf("%s", buf);
	used = 0;
	head = tail = newNode();
	for(int i = 0; buf[i]; ++i) {
		add(buf[i] - 'A');
	}
	
	Matrix cost;
	
	vector<SAM*> queue;
	for(int start = 0; start < 4; start++) {
		memset(dist, 0, sizeof(dist));
		queue.clear();
		queue.push_back(head->next[start]);
		dist[head->next[start] - pool] = 1;
		for(int i = 0; i < (int)queue.size(); i++) {
			SAM* temp = queue[i];
			int x = temp - pool;
			for(int j = 0; j < 4; j++) {
				if (temp->next[j] == NULL) {
					cost.dat[start][j] = min(cost.dat[start][j], (long long)dist[x]);
				} else {
					int y = temp->next[j] - pool;
					if (dist[y] == 0) {
						dist[y] = dist[x] + 1;
						queue.push_back(temp->next[j]);
					}
				}
			}
		}
	}
	/*
	for(int i = 0; i < 4; i++, puts(""))
		for(int j = 0; j < 4; j++) {
			printf("%d ", cost.dat[i][j]);
		}
	*/
	long long l = 0, r = n;
	while(l < r) {
		long long mid = (1 + l + r) / 2;
		if (solve(mid, cost) + 1 <= n) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l + 1 << endl;
	return 0;
}