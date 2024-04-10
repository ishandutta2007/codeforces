//*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <unordered_map>
#include <functional>
#define MOD 1000000007
#define MAX 0x3f3f3f3f
#define MAX2 0x3f3f3f3f3f3f3f3fll
#define ERR 1e-10
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#pragma warning(disable:4996)
using namespace std;

typedef double db;
typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const int INF = 1034567891;
class edge {
public:
	int s, e, f, c;
	edge() {
		*this = edge(0, 0, 0, 0);
	}
	edge(int s, int e, int f, int c) : s(s), e(e), f(f), c(c) {}
};
vector <edge> E;
vector <int> fconn[100050];

void epush(int s, int e, int f, int c) {
	edge e1 = edge(s, e, f, c);
	edge e2 = edge(e, s, 0, -c);
	fconn[s].push_back(E.size());
	fconn[e].push_back(E.size() + 1);
	E.push_back(e1);
	E.push_back(e2);
}

int fdis[100050];
int frev[100050];
bool fchk[100050];
vector <int> Vf;
ll totc = 0;
int BellmanFord(int snk) {
	fill(fdis, fdis + snk + 1, INF);
	fill(frev, frev + snk + 1, -1);
	fill(fchk, fchk + snk + 1, false);
	fchk[0] = true;
	fdis[0] = 0;
	Vf.push_back(0);
	for (int i = 0; i < Vf.size(); i++) {
		fchk[Vf[i]] = false;
		for (auto it : fconn[Vf[i]]) {
			if (E[it].f == 0 || fdis[E[it].e] <= fdis[Vf[i]] + E[it].c) continue;
			fdis[E[it].e] = fdis[Vf[i]] + E[it].c;
			frev[E[it].e] = it;
			if (!fchk[E[it].e]) {
				Vf.push_back(E[it].e);
				fchk[E[it].e] = true;
			}
		}
	}
	Vf.clear();

	if (fdis[snk] >= 0) return 0;

	int f = INF, t = snk;
	while (t) {
		f = min(f, E[frev[t]].f);
		t = E[frev[t]].s;
	}
	t = snk;
	totc += (ll)f * fdis[snk];
	while (t) {
		E[frev[t]].f -= f;
		E[frev[t] ^ 1].f += f;
		t = E[frev[t]].s;
	}
	return f;
}
int getFlow(int snk) {
	totc = 0;
	int f = 0, t;
	while (t = BellmanFord(snk)) f += t;
	return f;
}
void init(int snk) {
	for (int i = 0; i <= snk; i++) fconn[i].clear();
	E.clear();
}

char in1[505];
char in2[105][505];
int P[505];
int main() {
    int N, M, X, i, j, k;
    scanf("%d", &N);
    scanf("%s", in1+1);
    scanf("%d", &M);
    for(i = 1; i <= M; i++) scanf("%s %d", in2[i] + 1, &P[i]);
    scanf("%d", &X);

    int src = 0, snk = N+1;
    epush(src, 1, X, 0);
    for(i = 1; i <= N; i++) epush(i, i+1, X, 0);
    for(i = 1; i <= M; i++) {
        int l = strlen(in2[i]+1);
        for(j = 1; j + l - 1 <= N; j++) {
            for(k = 1; k <= l; k++) if(in2[i][k] != in1[j+k-1]) break;
            if(k > l) epush(j, j+l, 1, -P[i]);
        }
    }

    getFlow(snk);
    printf("%lld\n", -totc);
    return 0;
}