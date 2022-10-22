#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
	
using namespace std;
	
const int nax = 3e5 + 111;

int n;
int gdzie[nax];
int p[nax];
vector <pair<int, int>> v;

void add(int a, int b) {
	gdzie[p[a]] = b;
	gdzie[p[b]] = a;
	swap(p[a], p[b]);
	v.pb(mp(a, b));
}

int half(int a) {
	if(a <= n / 2)
		return 1;
	return 2;
}
	
void rob(int ele) {
	if(p[ele] == ele)
		return;
	if(half(ele) == half(gdzie[ele])) {
		if(half(ele) == 1) {
			add(gdzie[ele], n);
			add(n, ele);
		}
		else {
			add(gdzie[ele], 1);
			add(1, ele);
		}
		return;
	}
	if(half(ele) == 1) {
		add(1, gdzie[ele]);
		add(1, n);
		add(ele, n);
	}
	else {
		add(n, gdzie[ele]);
		add(n, 1);
		add(ele, 1);
	}
}
		
	
	

int main() {
	scanf("%d", &n);
	FOR(i, n) {
		scanf("%d", p + i);
		gdzie[p[i]] = i;
	}
	int mid = n / 2;
	int j = 0;
	for(int i = mid; 2 <= i; --i) {
		rob(i);
		rob(i + j + 1);
		j += 2;
	}
	if(p[1] != 1)
		add(1, n);
	FOR(i, n)
		assert(p[i] == i);
	printf("%d\n", ss(v));
	for(auto it : v)
		printf("%d %d\n", it.fi, it.se);
	
	
	return 0;
}