#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long
 
const int mod = 32771;
struct HashMap {
	int last[mod + 1];
	int nx[mod + 1], key[mod + 1], val[mod + 1], hc;
	inline void reset() {
		hc = 0;
		memset(last, -1, sizeof(last));
	}
	inline void cr(int k) {
		int h = k % mod;
		for (int w = last[h]; w >= 0; w = nx[w]) {
			if (key[w] == k) return;
		}
		key[hc] = k; val[hc] = 0; nx[hc] = last[h]; last[h] = hc++;
	}
	inline void add(int v, int vv) {
		for (int w = last[v % mod]; w >= 0; w = nx[w]) {
			if (key[w] == v) {
				val[w] += vv;
				return;
			}
		}
	}
	inline int fnd(int v) {
		for (int w = last[v % mod]; w >= 0; w = nx[w]) {
			if (key[w] == v) return val[w];
		}
		return 0;
	}
};
int a,b,c,d,i,j,n,m,k;
int quer[10002];
char str[1000002], tmp[33];
int nx[26], ind[26];
 
struct cmp {
	bool operator ()(const int &a, const int &b) const {
		return nx[a] < nx[b];
	}
};
 
HashMap q;
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	q.reset();
	scanf("%s", str);
	n = (int)strlen(str);
	scanf("%d", &m);
	rept(i, m) {
		scanf("%s", tmp);
		b = (int)strlen(tmp);
		int cmask = 0;
		rept(j, b) cmask |= 1 << (tmp[j] - 'a');
		q.cr(cmask);
		quer[i] = cmask;
	}
 
	memset(nx, 63, sizeof(nx));
	FORD(i, n - 1, 0) {
		nx[str[i] - 'a'] = i;
		int mask = 0;
		rept(j, 26) ind[j] = j;
		sort(ind, ind + 26, cmp());
		int pp = -1;
		if (i) pp = str[i - 1] - 'a';
		rept(j, 26) {
			int v = ind[j];
			if (nx[v] >= INF) break;
			mask |= 1 << v;
			if (i && (mask & 1 << pp)) break;
			q.add(mask, 1);
		}
	}
 
	rept(i, m) {
		printf("%d\n", q.fnd(quer[i]));
	}
}