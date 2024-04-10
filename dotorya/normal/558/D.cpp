//*
#include <algorithm>
#include <ctype.h>
#include <functional>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 131072;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;

vector <pll> yes;
vector <pll> no;
map <ll, int> M;
ll delta[300050];
ll deltasum[300050];
ll val[300050];
ll pow2[55];

vector <ll> tmp;
int main() {
	int H, Q, i, t1, t4;
	ll t2, t3;
	pow2[0] = 1;
	for (i = 1; i <= 52; i++) pow2[i] = pow2[i - 1] * 2;
	scanf("%d %d", &H, &Q);
	for (i = 1; i <= Q; i++) {
		scanf("%d %I64d %I64d %d", &t1, &t2, &t3, &t4);
		while (t1 != H) {
			t2 *= 2;
			t3 = 2 * t3 + 1;
			t1++;
		}
		if (t4 == 1) yes.push_back(pll(t2, t3+1));
		else no.push_back(pll(t2, t3+1));
		tmp.push_back(t2);
		tmp.push_back(t3+1);
	}

	tmp.push_back(pow2[H - 1]);
	tmp.push_back(pow2[H]);
	sort(tmp.begin(), tmp.end());

	for (i = 0; i < tmp.size(); i++) {
		if (i != 0 && tmp[i] == tmp[i - 1]) continue;
		t1 = M.size();
		val[t1] = tmp[i];
		M[tmp[i]] = t1;
	}

	for (i = 0; i < yes.size(); i++) {
		yes[i].first = M[yes[i].first];
		yes[i].second = M[yes[i].second];
		delta[yes[i].first]++;
		delta[yes[i].second]--;
	}

	for (i = 0; i < no.size(); i++) {
		no[i].first = M[no[i].first];
		no[i].second = M[no[i].second];
		delta[no[i].first] -= INF;
		delta[no[i].second] += INF;
	}

	deltasum[0] = delta[0];
	for (i = 1; i < M.size(); i++) deltasum[i] = deltasum[i - 1] + delta[i];

	ll len = 0, ans;
	for (i = 0; i < M.size()-1; i++) {
		if (deltasum[i] == yes.size()) {
			len += val[i + 1] - val[i];
			ans = val[i];
		}
	}
	if (len == 0) printf("Game cheated!");
	else if (len >= 2) printf("Data not sufficient!");
	else printf("%I64d", ans);
	return 0;
}