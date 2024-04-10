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

string s1, s2, s3;
int dist[8192];
PII pre[8192];
bool vis[8192];
vector<pair<int, PII> > G[8192];

void getstr(string& S, int ep)
{
	char ch;
	while((ch = getchar()) != ep) S.push_back(ch);
}

void putstr(string S)
{
	rep(i, S.length()) putchar(S[i]);
}

void rem_lz(string& S)
{
	int pos = 0;
	while(pos < S.length() && S[pos] == '0') pos ++;
	S = S.substr(pos);
}

int state(int l1, int l2, int l3, int car, int lz)
{
	return (l1 << 4) + (l2 << 7) + (l3 << 10) + (car << 3) + lz;
}

void add_path(int l1, int l2, int l3, int car, int lz) 
{
	int cs = state(l1, l2, l3, car, lz);
	for(int n1 = 0; n1 < 10; n1 ++) for(int n2 = 0; n2 < 10; n2 ++)
	for(int nc = 0; nc <= 1; nc ++) {
		int n3 = n1 + n2 - car * 10 + nc;
		if(n3 < 0 || n3 >= 10) continue;
		int nl1 = l1 + (l1 < s1.length() && s1[l1] - '0' == n1),
			nl2 = l2 + (l2 < s2.length() && s2[l2] - '0' == n2),
			nl3 = l3 + (l3 < s3.length() && s3[l3] - '0' == n3);
		int nlz = lz & ~((n1 != 0) | (n2 != 0) << 1 | (n3 != 0) << 2);
		G[state(l1, l2, l3, car, lz)].push_back(MP(state(nl1, nl2, nl3, nc, nlz), 
		MP(3 - (nlz >> 2) - (nlz >> 1 & 1) - (nlz & 1), n1 + n2 * 10 + n3 * 100)));
	}
}

void dijkstra(int s)
{
	rep(i, 8192) dist[i] = INF;
	priority_queue<PII, vector<PII>, greater<PII> > Q;
	dist[s] = 0;
	Q.push(MP(0, s));
	while(!Q.empty()) {
		int v = Q.top().second;
		Q.pop();
		if(vis[v]) continue;
		vis[v] = true;
		rep(i, G[v].size()) {
			int u = G[v][i].first;
			if(dist[u] > dist[v] + G[v][i].second.first) {
				dist[u] = dist[v] + G[v][i].second.first;
				pre[u] = MP(v, G[v][i].second.second);
				Q.push(MP(dist[u], u));
			}
		}
	}
}

int main()
{
	getstr(s1, '+');
	getstr(s2, '=');
	getstr(s3, '\n');
	for(int i = 0; i <= s1.length(); i ++)
	for(int j = 0; j <= s2.length(); j ++)
	for(int k = 0; k <= s3.length(); k ++)
	for(int c = 0; c <= 1; c ++) for(int l = 0; l < 8; l ++)
	add_path(i, j, k, c, l);
	int s = state(0, 0, 0, 0, 7), t = state(s1.length(), s2.length(), s3.length(), 0, 0);
	dijkstra(s);
	s1.clear();
	s2.clear();
	s3.clear();
	while(t != s) {
		s1.push_back(pre[t].second % 10 + '0');
		s2.push_back(pre[t].second / 10 % 10 + '0');
		s3.push_back(pre[t].second / 100 + '0');
		t = pre[t].first;
	}
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	reverse(s3.begin(), s3.end());
	rem_lz(s1);
	rem_lz(s2);
	rem_lz(s3);
	putstr(s1); putchar('+');
	putstr(s2); putchar('=');
	putstr(s3); putchar('\n');
	return 0;
}