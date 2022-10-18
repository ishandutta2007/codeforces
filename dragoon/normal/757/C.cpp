#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

vector<set<int> > V;
int id[1000006];
LL fact[1000006];
LL MOD = 1000000007;

int num[1000006];
int cnt[1000006];

void process(set<int>& S) {
	map<int, set<int> > M;
	for (int s : S) {
		M[id[s]].insert(s);
	}

	for (auto& ent : M) {
		int nid = V.size();
		V.push_back(set<int>());
		for (int j : ent.second) {
			V[ent.first].erase(j);
			V[nid].insert(j);
			id[j] = nid;
		}
	}
}

void process() {
	int g;
	scanf("%d", &g);
	for (int i = 0; i < g; i++) {
		scanf("%d", &num[i]);
		cnt[num[i]] = 0;
	}

	for (int i = 0; i < g; i++) {
		cnt[num[i]]++;
	}

	map<int, set<int> > M;
	for (int i = 0; i < g; i++) {
		M[cnt[num[i]]].insert(num[i]);
	}

	for (auto& ent : M) {
		// ent.first = int
		// ent.second = set<int>
		process(ent.second);
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	{
		fact[0] = 1;
		for (int i = 1; i <= 1000000; i++) {
			fact[i] = (i * fact[i - 1]) % MOD;
		}

		set<int> S;
		for (int i = 1; i <= m; i++) {
			S.insert(i);
			id[i] = 0;
		}
		V.push_back(S);
	}

	for (int i = 1; i <= n; i++) {
		process();
	}

	LL ans = 1;
	for (int i = 0; i < V.size(); i++) {
		ans = (ans * fact[V[i].size()]) % MOD;
	}

	printf("%I64d\n", ans);

	return 0;
}