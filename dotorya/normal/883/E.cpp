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
//#include <unordered_map>  
//#include <unordered_set>  
#include <vector>

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple<int, int, int> t3;
#define rep(i, n) for(int i=0;i<n;i++)

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-12;

char in1[55];
bool chk[55];
char in2[1050][55];

int cnt[55];
int N;
int aa(vector<int> Vl, ll v) {


	int i, j;
	for (i = 0; i < 26; i++) cnt[i] = 0;
	for (auto it : Vl) {
		for (i = 0; i < 26; i++) chk[i] = false;
		for (i = 0; i < N; i++) {
			if (v & (1ll << (ll)i));
			else continue;

			chk[in2[it][i] - 'a'] = true;
		}
		for (i = 0; i < 26; i++) if (chk[i]) cnt[i]++;
	}

	int ans = 0;
	for (i = 0; i < 26; i++) chk[i] = false;
	for (i = 0; i < 26; i++) {
		if (cnt[i] != Vl.size()) continue;
		chk[i] = true;
		ans++;
	}

	return ans;
}
int main() {
	int M, i, j;
	scanf("%d", &N);
	scanf("%s", in1);
	scanf("%d", &M);
	for (i = 1; i <= M; i++) scanf("%s", in2[i]);

	ll v = 0;
	for (i = 0; i < N; i++) {
		if (in1[i] == '*') v |= 1ll << (ll)i;
		else chk[in1[i] - 'a'] = true;
	}

	vector <int> Vl;
	int c = 0;
	for (i = 1; i <= M; i++) {
		for (j = 0; j < N; j++) {
			if (in1[j] != '*') {
				if (in1[j] != in2[i][j]) break;
			}
			else if (chk[in2[i][j] - 'a']) break;
		}
		if (j >= N) Vl.push_back(i);
	}
	return !printf("%d\n", aa(Vl, v));
}