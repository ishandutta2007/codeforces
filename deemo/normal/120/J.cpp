#include<cstdio>
#include<algorithm>
#include<utility>
#include<iostream>

using namespace std;

typedef long long ll;

#define F first
#define S second
#define Vec pair<pair<int, int>, int>

const int MAXN = 1e5 + 10;

int n;
pair<int, int>	vec[MAXN];
pair<pair<int, int>, int>	sec[MAXN], gec[MAXN];
ll mx = 1e18;
pair<int, int> gg;

ll dis(pair<ll, ll> a, pair<ll, ll> b){
	return (a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S);
}

void check(Vec a, Vec b){
	ll temp = dis(a.F, b.F);
	if (temp >= mx)	return;
	mx = temp;
	gg = {a.S, b.S};
}

bool cmp(Vec a, Vec b){return a.F.S < b.F.S;}

void solve(int l, int r){
	if (r - l < 2)	return;

	int mid = l + r >> 1;
	solve(l, mid);
	solve(mid, r);
	merge(sec + l, sec + mid, sec + mid, sec + r, gec, cmp);
	copy(gec, gec + (r - l), sec + l);
	
	for (int i = l; i < r; i++)
		for (int j = max(l, i - 9); j < min(r, i + 10); j++)
			if (i^j)
				check(sec[i], sec[j]);
}

int get(int a, bool fl){
	if (fl){
		if (vec[a].F > 0 && vec[a].S > 0)	return 4;
		if (vec[a].F > 0)	return 2;
		if (vec[a].S > 0)	return 3;
		return 1;
	}
	else{
		if (vec[a].F < 0 && vec[a].S < 0)	return 4;
		if (vec[a].F < 0)	return 2;
		if (vec[a].S < 0)	return 3;
		return 1;
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d %d", &vec[i].F, &vec[i].S);
		sec[i].F.F = abs(vec[i].F), sec[i].F.S = abs(vec[i].S), sec[i].S = i;
	}
	sort(sec, sec + n);
	solve(0, n);
	printf("%d %d %d %d\n", gg.F + 1, get(gg.F, 0), gg.S + 1, get(gg.S, 1));
	return 0;
}