//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include <ctime>
#include<list>
#include <numeric>
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
#include<unordered_map>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int128 LL;
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<long double, long double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;
typedef long double ld;

vector<int> Prime;
int d[33000], prevs[33000], done[33000];

void solve() {
	int n;
	scanf("%d", &n);
	//n = rand() * rand() % 1000000000 + 2;
	//if (n < 2) return;
	//if (n > 1000000000) return;
	vector<int> primes;
	{
		int temp = n;
		for (LL i : Prime) {
			if (i * i > temp) break;
			if (temp % i) continue;
			primes.push_back(i);
			while (temp % i == 0) temp /= i;
		}
		if (temp > 1) primes.push_back(temp);
	}

	sort(ALL(primes));
	if (primes.size() == 1) {
		printf("NO\n");
		return;
	}

	int sp = primes[0];
	for (int i = 0; i < sp; i++) {
		prevs[i] = -1;
		d[i] = -1;
		done[i] = 0;
	}
	set<int> SS;
	VI primes2;
	for (int i : primes) {
		if (SS.find(i % sp) == SS.end()) {
			primes2.push_back(i);
			SS.insert(i % sp);
		}
	}
	primes = primes2;
	d[0] = 0;
	for (int i = 0; i < sp; i++) {
		LL candidate = -1, mncost = 1000000000;
		for (int j = 0; j < sp; j++) {
			if (done[j]) continue;
			if (d[j] == -1) continue;
			if (d[j] < mncost) {
				mncost = d[j];
				candidate = j;
			}
		}
		if (candidate == -1) break;
		done[candidate] = 1;
		for (int p : primes) {
			int to = (p + candidate) % sp;
			if (mncost + p > n) continue;
			if (d[to] != -1 && d[to] <= mncost + p) continue;
			d[to] = mncost + p;
			prevs[to] = p;
		}
	}

	if (d[(n - 1) % sp] == -1 || d[(n - 1) % sp] > n - 1) {
		printf("NO\n");
		return;
	}

	printf("YES\n");
	VI ans;
	int now = (n - 1) % sp;
	while (now) {
		int p = prevs[now];
		ans.push_back(p);
		now = (now + sp - (p%sp)) % sp;
	}
	map<int, int> M;
	for (int i : ans) M[i]++;
	if (n - 1 - d[(n - 1) % sp]) {
		M[sp] += (n - 1 - d[(n - 1) % sp]) / sp;
	}
	printf("%d\n", SZ(M));
	LL lob = 0;
	//printf(">>>>>%d\n", n);
	for (auto& ps : M) {
		printf("%d %d\n", ps.second, n / ps.first);
		assert(n % ps.first == 0);
		assert(n / ps.first != n);
		assert(n / ps.first != 1);
		assert(ps.second > 0);
		assert(ps.second < n/ps.first);
		lob += ((LL) ps.second) * ps.first;
	}
	assert(lob == n - 1);
}

int mark[33000];

void sieve(int n)
{
	int i, j, limit = sqrt(n*1.) + 2;

	mark[1] = 1;
	for (i = 4; i <= n; i += 2) mark[i] = 1;

	Prime.push_back(2);
	for (i = 3; i <= n; i += 2)
		if (!mark[i])
		{
			Prime.push_back(i);

			if (i <= limit)
			{
				for (j = i * i; j <= n; j += i * 2)
				{
					mark[j] = 1;
				}
			}
		}
}

int main()
{
	double start_time = clock();
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif

	sieve(32000);
	//while (true) 
		solve();

	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);

	return 0;
}