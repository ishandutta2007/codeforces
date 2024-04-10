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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

string ans;
bool chk[10050];

int isValid(int i) {
	int j, k;
	vector <int> Vu;
	int t = i;
	while (t) {
		Vu.push_back(t % 10);
		t /= 10;
	}
	reverse(all(Vu));

	int X = Vu.size();
	for (j = 0; j < (1 << (X - 1)); j++) {
		for (k = 0; k < X - 1; k++) {
			if (j & (1 << k)) chk[k] = true;
			else chk[k] = false;
		}

		int s = 0, v = Vu[0];
		for (k = 1; k < X; k++) {
			if (chk[k - 1]) {
				s += v;
				v = 0;
			}
			v = v * 10 + Vu[k];
		}
		s += v;

		int os = s;
		int s2 = 0;
		while (s) {
			s2 += s % 10;
			s /= 10;
		}
		if (s2 < 10) {
			ans = string("");
			ans += (char)('0' + Vu[0]);
			for (i = 1; i < X; i++) {
				if (chk[i - 1]) ans += '+';
				ans += (char)('0' + Vu[i]);
			}
			return os;
		}
	}
	return 0;
}

int printnxt(int x) {
	vector <int> Vu;
	while (x) {
		Vu.push_back(x % 10);
		x /= 10;
	}
	reverse(all(Vu));

	int s = 0;
	for (int i = 0; i < Vu.size(); i++) {
		printf("%d", Vu[i]);
		s += Vu[i];
		if (i + 1 != Vu.size()) printf("+");
	}
	printf("\n");
	return s;
}

char in[200050];
vector <int> Vl;
int main() {
	int i, j, k, L;
	srand(time(0));
	
	scanf("%d %s", &L, in);

	while (1) {
		int sc = 0, s = 0;
		while (sc != L) {
			if (sc + 1 == L) Vl.push_back(1);
			else if (rand() % 20 == 19) Vl.push_back(2);
			else Vl.push_back(1);

			if (Vl.back() == 1) {
				s += in[sc] - '0';
				sc++;
			}
			else {
				s += (in[sc] - '0') * 10 + (in[sc + 1] - '0');
				sc += 2;
			}
		}

		int t = isValid(s);
		if (t) {
			int x = 0;
			for (auto it : Vl) {
				for (i = x; i < x + it; i++) printf("%c", in[i]);
				x += it;
				if (x != L) printf("+");
			}
			printf("\n");
			printf("%s\n", ans.c_str());
			t = printnxt(t);
			return 0;
		}
		Vl.clear();
	}
	return 0;
	
}