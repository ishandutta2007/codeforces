#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

vector <string> in;

char tus[300050];
vector <string> ans;

vector <string> u;

int mnp[300050];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%s", tus);
		in.emplace_back(tus);
	}

	ans = in;
	u = in;
	int mn = INF;
	char ch[5] = "ACGT";
	do {
		int tot = 0;
		for (int i = 0; i < N; i++) {
			char c[2] = { ch[0], ch[1] };
			if (i % 2 == 1) c[0] = ch[2], c[1] = ch[3];

			int v = INF;
			for (int j = 0; j < 2; j++) {
				int s = 0;
				for (int k = 0; k < M; k++) {
					if (c[j ^ (k & 1)] != in[i][k]) s++;
				}
				if (v > s) {
					v = s;
					mnp[i] = j;
				}
			}
			tot += v;
		}
		if (mn > tot) {
			for (int i = 0; i < N; i++) {
				char c[2] = { ch[0], ch[1] };
				if (i % 2 == 1) c[0] = ch[2], c[1] = ch[3];

				if (mnp[i]) swap(c[0], c[1]);

				for (int j = 0; j < M; j++) ans[i][j] = c[j & 1];
			}
			mn = tot;
		}
	} while (next_permutation(ch, ch + 4));

	do {
		int tot = 0;
		for (int i = 0; i < M; i++) {
			char c[2] = { ch[0], ch[1] };
			if (i % 2 == 1) c[0] = ch[2], c[1] = ch[3];

			int v = INF;
			for (int j = 0; j < 2; j++) {
				int s = 0;
				for (int k = 0; k < N; k++) {
					if (c[j ^ (k & 1)] != in[k][i]) s++;
				}
				if (v > s) {
					v = s;
					mnp[i] = j;
				}
			}
			tot += v;
		}
		if (mn > tot) {
			for (int i = 0; i < M; i++) {
				char c[2] = { ch[0], ch[1] };
				if (i % 2 == 1) c[0] = ch[2], c[1] = ch[3];

				if (mnp[i]) swap(c[0], c[1]);

				for (int j = 0; j < N; j++) ans[j][i] = c[j & 1];
			}
			mn = tot;
		}
	} while (next_permutation(ch, ch + 4));

	for (int i = 0; i < N; i++) printf("%s\n", ans[i].c_str());
	return 0;
}