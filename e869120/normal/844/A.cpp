#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<functional>
#include<queue>
using namespace std;
string S; int p, t;
int main() {
	cin >> S >> p; t = S.size();
	sort(S.begin(), S.end()); S.erase(unique(S.begin(), S.end()), S.end());
	if (t < p)cout << "impossible" << endl;
	else cout << max(0, p - (int)S.size()) << endl;
	return 0;
}