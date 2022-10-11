#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<functional>
using namespace std;
long long n, k, p, q, s; vector<long long>l;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) { cin >> p >> q; l.push_back(min(p * 2, q) - min(p, q)); s += min(p, q); }
	sort(l.begin(), l.end(), greater<long long>());
	for (int i = 0; i < k; i++)s += l[i];
	cout << s << endl;
	return 0;
}