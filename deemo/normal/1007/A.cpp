#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n;
int a[MAXN];
set<pii> st, st2;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], st.insert({a[i], i}), st2.insert({a[i], i});
	int ans = 0;
	while (st.size()){
		auto x = *st.rbegin();
		st.erase(x);
		auto it = st2.lower_bound({x.F, -1});
		if (it != st2.begin()){
			it--;
			st2.erase(it);
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}