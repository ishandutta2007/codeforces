#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
int n, k, a[N];
ll pre;
ll sum;
int lst;
vi S;
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	L(i, 1, n) {
		cin >> a[i];
		sum += a[i];
	}
	if(sum % k) return cout << "No\n", 0;
	sum /= k;
	ll now = sum;
	L(i, 1, n) {
		now -= a[i];
		if(now < 0) return cout << "No\n", 0;
		if(now == 0) {
			S.push_back(i - lst);
			lst = i;
			now += sum;
		}
	}
	cout << "Yes\n";
	for (const int &u : S) 
		cout << u << ' ';
	cout << '\n';
	return 0;
}