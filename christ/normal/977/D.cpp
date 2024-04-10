#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 5e3+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
vector<ll> withlog[40];
int main() {
	int n;
	scanf ("%d",&n);
	vector<ll> a(n);
	for (auto &au : a) {
		scanf ("%lld",&au);
		int lg = 0;
		ll cur = au;
		while (cur%3==0) lg++, cur/=3;
		withlog[lg].push_back(au);
	}
	for (int i = 40; i >= 0; i--) if (!withlog[i].empty()){
		sort(all(withlog[i]));
		for (ll cur : withlog[i]) printf ("%lld ",cur);
	}
	printf ("\n");
    return 0;
}