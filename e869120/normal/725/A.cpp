#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
string S; int p, cnt, n;
int main() {
	cin >> n >> S;
	while (p < S.size() && S[p] == '<') { p++; cnt++; }p = S.size() - 1;
	while (p >= 0 && S[p] == '>') { p--; cnt++; }
	cout << cnt << endl;
	return 0;
}