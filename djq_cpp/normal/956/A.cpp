/*
Author: Dynamic JQ

Problem:

Time & Date(start):

Verdict:

Tags:
Implementation
Brute force
Graphs
	Dfs and similar
		DFS order
		Topological sort
		Strongly/Biconnected connected components
			2 - SAT
	BFS
	Shortest Path
	Trees
		LCA
		Centroid Deposition
		Differentation on trees
	Flows
		Max_flow
		Min_cost_flow
Data structures
	DSU
		Union by rank
	Doubling algorithms 
	Segment tree/Fenwick tree
		Lazy tags
		2 - dimensional segment tree/Fenwick tree
	Balanced BST
	Persistent data structures
	Divide and conquer
	Offline algorithms
		Mo's algorithm
	Heavy - light deposition
Tricks based on monotonicity
	Binary search
	Ternary search
	Two pointers
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

set<string> S;
int cnt[55];

int main()
{
	int n, m;
	string inp;
	cin >> n >> m;
	rep(i, n) {
		cin >> inp;
		S.insert(inp);
	}
	for(set<string>::iterator it = S.begin(); it != S.end(); it ++) {
		inp = *it;
		rep(i, m) if(inp[i] == '#') cnt[i] ++;
	}
	rep(i, m) if(cnt[i] > 1) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	return 0;
}