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

vector<string> solve(int n) {
	vector<string> V = { 
		"a1","a2","a3","a4","a5","a6","a7","a8",
		"b8","b7","b6","b5","b4","b3","b2","b1",
		"c1","c2","c3","c4","c5","c6","c7","c8",
		"d8","d7","d6","d5","d4","d3","d2","d1",
		"e1","e2","e3","e4","e5","e6","e7","e8",
		"f8","f7","f6","f5","f4","f3","f2","f1"};
	vector<string> A1 = {
		"g1","h1","h2","g2","g3","h3","h4","g4",
		"g5","h5","h6","g6","g7","h7","h8","g8",
	};
	vector<string> A2 = {
		"h1","g1","g2","h2","h3","g3","g4","h4",
		"h5","g5","g6","h6","h7","g7","g8","h8",
	};
	vector<string> ans;
	for (int i = 0; i < MIN(n - 2, 48); i++) {
		printf("%s ", V[i].c_str());
		ans.push_back(V[i]);
	}
	if (n == 51) 
		n = 51;
	if (n - 2 <= SZ(V)) {
		string last = V[n - 2 - 1];
		if (last.at(1) == '8') {
			last = "g8";
		}
		else {
			last[0] = 'h';
		}
		printf("%s ", last.c_str());
		ans.push_back(last);
		printf("h8\n");
		ans.push_back("h8");
		return ans;
	}
	n -= 48;
	vector<string> A;
	if (n % 2) A = A1;
	else A = A2;
	string last;
	for (int i = 0; i < n - 2; i++) {
		printf("%s ", A[i].c_str());
		last = A[i];
		ans.push_back(A[i]);
	}
	if (last.at(0) == 'g') last = "g8";
	else last = "h7";
	printf("%s ", last.c_str());
	ans.push_back(last);
	printf("h8\n");
	ans.push_back("h8");
	return ans;
}

void check(int n, vector<string> S) {
	auto Assert = [&](bool b) -> void {
		if (!b) printf(">>>%d\n", n);
		assert(b);
	};
	VP V;
	for (string s : S) {
		V.push_back({ s.at(0) - 'a', s.at(1) - '1' });
	}
	Assert(V.size() == n);
	for (int i = 1; i < n; i++) {
		Assert(V[i - 1].first == V[i].first
			|| V[i - 1].second == V[i].second);
	}
	Assert(V[0] == PII(0, 0));
	Assert(V[n - 1] == PII(7, 7));
	set<PII> SS;
	for (auto p : V) SS.insert(p);
	Assert(S.size() == n);
}

int main()
{
	double start_time = clock();
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif

	//for (int n = 3; n <= 64; n++) 
	{
		int n;
		scanf("%d", &n);
		n++;
		check(n, solve(n));
	}

	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);

	return 0;
}