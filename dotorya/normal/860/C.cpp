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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

char str[100050];
pair<string, int> u[100050];
string in[100050];
string name[100050];

set <string> Sn;
set <int> Sx1[2];
set <int> Sx2[2];
set <string> Sn1[2];
set <string> Sn2[2];
vector <pair<string, string>> Va;
void END() {
	printf("%d\n", (int)Va.size());
	for (auto it : Va) printf("move %s %s\n", it.first.c_str(), it.second.c_str());
	exit(0);
}
void changename(int x, int c, string u) {
	int t = (int) (x > c);

	if (Sn1[!t].count(in[x])) Sn2[!t].insert(in[x]);
	if (Sx2[t].count(x)) Sx2[t].erase(x);
	
	Va.emplace_back(in[x], u);
	in[x] = u;
	if (Sn1[t].count(u)) {
		Sn1[t].erase(u);
		Sx1[t].erase(x);

		if (Sn2[0].count(u)) Sn2[0].erase(u);
		if (Sn2[1].count(u)) Sn2[1].erase(u);
	}
}
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%s %d", str, &u[i].second);
		u[i].first = string(str);
		Sn.insert(u[i].first);
	}
	sort(u + 1, u + N + 1, [](auto a, auto b) {
		return a.second > b.second;
	});
	int c = 0;
	for (i = 1; i <= N; i++) c += u[i].second;
	for (i = 1; i <= N; i++) in[i] = u[i].first;

	for (i = 1; i <= N; i++) {
		int t = 0;
		if (i > c) t = 1;

		sprintf(str, "%d", i);
		name[i] = string(str);
		Sn1[t].insert(name[i]);
		Sn2[t].insert(name[i]);
	}
	for (i = 1; i <= N; i++) {
		int t = 0;
		if (i > c) t = 1;
		
		if (Sn1[t].count(in[i])) {
			Sn1[t].erase(in[i]);
			Sn2[t].erase(in[i]);
		}
		else {
			Sx1[t].insert(i);
			if (Sn1[!t].count(in[i])) {
				Sx2[t].insert(i);
				Sn2[!t].erase(in[i]);
			}
		}
	}

	while (!Sx1[0].empty() || !Sx1[1].empty()) {
		if (Sn2[0].empty() && Sn2[1].empty()) {
			srand(time(0));
			string u = string("aaaaaa");
			while (Sn.count(u)) {
				u = string("");
				for (i = 0; i < 6; i++) u += rand() % 26 + 'a';
			}

			int x;
			if (Sx2[0].empty()) x = *(Sx2[1].begin());
			else x = *(Sx2[0].begin());

			changename(x, c, u);
			continue;
		}

		int t = 0;
		if (Sn2[0].empty()) t = 1;
		string u = *(Sn2[t].begin());
		
		int x;
		if (!Sx2[t].empty()) x = *(Sx2[t].begin());
		else if (!Sx1[t].empty()) x = *(Sx1[t].begin());
		else {
			printf("FUUU\n");
			while (1);
		}

		changename(x, c, u);
	}
	END();
}