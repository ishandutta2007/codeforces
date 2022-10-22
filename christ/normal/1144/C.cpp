#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 5e4+2, MOD = 1e9+7, LOG = 15;
#define all(x) (x).begin(),(x).end()
int main() {
	int n;
	scanf ("%d",&n);
	vector<int> a(n); vector<bool> in(n);
	for (auto &au : a) scanf ("%d",&au);
	sort(all(a));
	vector<int> one,two; int lst = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] > lst) one.push_back(a[i]), lst = a[i], in[i] = 1;
	}
	 lst = INT_MAX;
	for (int i = n-1; i >= 0; i--) {
		if (!in[i]) {
			if (a[i] >= lst) return !printf ("nO\n");
			two.push_back(a[i]);
			lst = a[i];
		}
	}
	printf ("YeS\n");
	printf ("%d\n",one.size());
	for (int i : one) printf ("%d ",i);
	printf ("\n%d\n",two.size());
	for (int i : two) printf ("%d ",i);
	printf ("\n");
    return 0;
}