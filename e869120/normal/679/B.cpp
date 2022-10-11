#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n, s = 1, t = 0, u = 0; vector<long long>E;
bool isvalid(vector<long long>D, long long Y) {
	for (int i = D.size() - 1; i >= 0; i--) {
		if ((D[i] + 1)*(D[i] + 1)*(D[i] + 1) <= Y)return false;
		Y -= D[i] * D[i] * D[i];
	}
	return true;
}
int main() {
	cin >> n;
	while (true) {
		while (s <= 200000 && (s + 1)*(s + 1)*(s + 1) <= s*s*s + t) s++;
		if (s*s*s + t > n)break;
		E.push_back(s); t += s*s*s;
	}
	u = t;
	for (int i = E.size() - 1; i >= 0; i--) {
		while (true) {
			long long Z = (E[i] + 1)*(E[i] + 1)*(E[i] + 1) - E[i] * E[i] * E[i];
			vector<long long>F = E; F[i]++;
			if (Z + t <= n && isvalid(F, t + Z) == true) {
				u += Z; t += Z; E[i]++;
			}
			else break;
		}
	}
	cout << E.size() << ' ' << t << endl;
	return 0;
}