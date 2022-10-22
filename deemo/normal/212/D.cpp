#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef double ld;

const int MAXN = 1e6 + 5;

int n;
int h[MAXN];
pair<int, int>	sec[MAXN];
set<int>	st;
ll mark[MAXN], m2[MAXN], ans[MAXN], dl[MAXN], sdl[MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &h[i]);
		sec[i] = {h[i], i};
	}
	sort(sec, sec + n);
	for (int i = 0; i < n; i++){
		pair<ll, ll>	v = sec[i];
		ll l, r;

		auto it = st.upper_bound(v.second);
		if (it == st.end())	r = n;
		else	r = *it;

		if (it == st.begin())	l = 0;
		else	it--, l = *it + 1;

		ll ind = v.second;
		int sz = min(ind - l + 1, r - ind);
		mark[1] += v.first;
		mark[sz + 1] -= v.first;
		dl[sz + 1] -= sz * v.first;

		m2[r - l - sz] -= v.first;
		m2[r - l] += v.first;
		sdl[sz] -= sz * v.first;

		st.insert(ind);
	}
	ll sum = 0, cur = 0;
	for (int i = 1; i <= n; i++){
		sum += mark[i];
		cur += dl[i];
		cur += sum;
		ans[i] += cur;
	}
	sum = cur = 0;
	for (int i = n; i; i--){
		sum += m2[i];
		cur += sdl[i];
		cur += sum;
		ans[i] += cur;
	}
	
	int q;	scanf("%d", &q);
	//cout << fixed << setprecision(12);
	while (q--){
		int x;	scanf("%d", &x);
	//	cout << ld(ans[x])/ ld(n - x + 1) << "\n";
		printf("%.10lf\n", ld(ans[x])/ ld(n - x + 1));
	}
	return	0;
}