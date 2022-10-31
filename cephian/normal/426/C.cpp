#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <vector>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int n,k;
int a[200];

vector<int> in, out;

int solve(int s, int e) {
	in.clear();
	out.clear();
	int sum = 0;
	for(int i = 0; i < n; ++i) {
		if(i < s || i > e) {
			out.push_back(a[i]);
		}
		else {
			in.push_back(a[i]);
			sum += a[i];
		}
	}
	sort(in.begin(), in.end());
	sort(out.rbegin(),out.rend());
	int b=0;
	for(int i = 0; i < in.size() && i < k; ++i) {
		while(b < out.size() && out[b] <= in[i]) ++b;
		if(b == out.size()) break;
		sum += out[b++]-in[i];
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = a[0];
	for(int i = 0; i < n; ++i) {
		for(int j = i; j < n; ++j) {
			ans = max(ans, solve(i,j));
		}
	}
	cout << ans << "\n";
	return 0;
}