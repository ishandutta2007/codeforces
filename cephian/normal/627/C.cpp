#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;


#define pos first
#define price second

const int N = 200005;
ll d,v;
int n;
pll xp[N];
int next_cheap[N];

vector<int> st;

int main() {
	ios::sync_with_stdio(0); cin.tie();
	cin >> d >> v >> n;
	for(int i = 0; i < n; ++i)
		cin >> xp[i].pos >> xp[i].price;
	xp[n].pos = 0;
	xp[n].price = 0;
	xp[n+1].pos = d;
	xp[n+1].price = -1;
	sort(xp,xp+n+2);
	st.push_back(n+1);
	for(int i = n; i >= 0; --i) {
		while(xp[st.back()].price >= xp[i].price)
			st.pop_back();
		next_cheap[i] = st.back();
		st.push_back(i);
	}
	ll tank = 0, cost=0;
	for(int i = 0;; ++i) {
		if(tank < 0) {
			cout << "-1\n";
			return 0;
		}
		if(i == n+1) break;
		ll get = max(0LL,min(v-tank,xp[next_cheap[i]].pos-xp[i].pos - tank));
		cost += get*xp[i].price;
		tank += get;
		tank -= xp[i+1].pos-xp[i].pos;
	}
	cout << cost << "\n";

	return 0;
}