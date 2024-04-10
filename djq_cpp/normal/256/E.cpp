/*
Author: Dynamic JQ

Problem: Codeforces 256E - Lucky Arrays

Time & Date(start): Mar/12/2018 22:30

Verdict: Coding

Tags: dp + trie
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

struct node
{
	node* left;
	node* right;
	LL data;
	int siz; 
	node(LL dat = 1LL)
	{
		left = right = NULL; 
		data = dat;
		siz = 1;
	}
};

LL _getdata(node* v)
{
	return v == NULL ? 1LL : v -> data;
}

int _getsiz(node* v)
{
	return v == NULL ? 0 : v -> siz;
}

void Nmodify(node*& v, int id, LL cur, int cl = 0, int cr = 131071)
{
	if(v == NULL) v = new node();
	if(cl != cr) {
		int mid = (cl + cr) >> 1;
		if(id <= mid) Nmodify(v -> left, id, cur, cl, mid);
		else Nmodify(v -> right, id, cur, mid + 1, cr);
		v -> data = _getdata(v -> left) * _getdata(v -> right) % 777777777;
		v -> siz = _getsiz(v -> left) + _getsiz(v -> right);
	} else v -> data = cur;
}

LL Nquery(node*& v, int l, int r, int cl = 0, int cr = 131071)
{
	if(v == NULL) return 1LL;
	if(l == cl && r == cr) return v -> data;
	LL ans = 1LL;
	int mid = (cl + cr) >> 1;
	if(l <= mid) ans = ans * Nquery(v -> left, l, min(r, mid), cl, mid) % 777777777;
	if(r > mid) ans = ans * Nquery(v -> right, max(l, mid + 1), r, mid + 1, cr) % 777777777;
	return ans;
}

void Nerase(node*& v, int id, int cl = 0, int cr = 131071)
{
	if(v == NULL) return;
	if(cl != cr) {
		int mid = (cl + cr) >> 1;
		if(id <= mid) Nerase(v -> left, id, cl, mid);
		else Nerase(v -> right, id, mid + 1, cr);
		v -> data = _getdata(v -> left) * _getdata(v -> right) % 777777777;
		v -> siz = _getsiz(v -> left) + _getsiz(v -> right);
		if(v -> siz == 0) {
			delete v;
			v = NULL;
		}
	} else {
		delete v;
		v = NULL;
	}
}

int Ngetkth(node*& v, int k, int cl = 0, int cr = 131071)
{
	if(v == NULL) return -1;
	if(cl == cr) return k == 0 ? cl : -1;
	int mid = (cl + cr) >> 1;
	if(k < _getsiz(v -> left)) return Ngetkth(v -> left, k, cl, mid);
	else return Ngetkth(v -> right, k - _getsiz(v -> left), mid + 1, cr);
}

int Ngetidr(node*& v, int id, int cl = 0, int cr = 131071)
{
	if(v == NULL) return -1;
	if(cl == cr) return 0;
	int mid = (cl + cr) >> 1;
	if(id <= mid) return Ngetidr(v -> left, id, cl, mid);
	else return Ngetidr(v -> right, id, mid + 1, cr) + _getsiz(v -> left);
}

typedef node* segt;
segt st;

int N, trans[4][4]; 
int dp[4][4][78987];

void init_dp()
{
	memset(dp, 0, sizeof(dp));
	rep1(i, 3) dp[i][i][0] = 1LL;
	rep1(b, 3) rep1(k, N - 1) rep1(i, 3) rep1(j, 3)
	if(trans[j][i]) dp[b][i][k] = (dp[b][i][k] + dp[b][j][k - 1]) % 777777777;
	rep(k, N) {
		rep1(i, 3) rep1(j, 3) dp[i][0][k] = (dp[i][0][k] + dp[i][j][k]) % 777777777;
		rep(i, 4) rep1(j, 3) dp[0][i][k] = (dp[0][i][k] + dp[j][i][k]) % 777777777;
	}
}

int dat[78987];

void init_ds()
{
	Nmodify(st, 1, dp[0][0][N - 1]);
	Nmodify(st, N, 1LL);
}

LL modify(int id, int v)
{
	if(dat[id] == 0 && id != 1 && id != N) Nmodify(st, id, 1LL);
	int idr = Ngetidr(st, id);
	int prv = Ngetkth(st, idr - 1), nxt = Ngetkth(st, idr + 1);
	if(prv == -1) prv = 1;
	if(nxt == -1) nxt = N;
	dat[id] = v;
	if(v == 0) {
		if(id != 1 && id != N) Nerase(st, id);
		Nmodify(st, prv, dp[dat[prv]][dat[nxt]][nxt - prv]);
	} else {
		Nmodify(st, id, dp[dat[id]][dat[nxt]][nxt - id]);
		if(id != prv) Nmodify(st, prv, dp[dat[prv]][dat[id]][id - prv]);
	}
	return Nquery(st, 1, N);
}

int main()
{
	int q, id, v;
	scanf("%d%d", &N, &q);
	rep1(i, 3) rep1(j, 3) scanf("%d", &trans[i][j]);
	init_dp();
	init_ds();
	while(q --) {
		scanf("%d%d", &id, &v);
		printf("%I64d\n", modify(id, v));
	}
	return 0;
}