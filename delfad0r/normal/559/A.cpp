#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int A[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for(int n = 1; n <= 6; ++n) cin >> A[n];
	auto sqr = [](int x) { return x * x; };
	cout << sqr(A[1] + A[2] + A[3]) - sqr(A[1]) - sqr(A[3]) - sqr(A[5]);
}