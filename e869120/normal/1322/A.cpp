#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

string S;
int n, dep, cnt, pres;
bool flag = false;

int main() {
	cin >> n >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '(') dep++;
		if (S[i] == ')') dep--;
		if (dep == 0) {
			if (flag == true) cnt += ((i + 1) - pres);
			pres = i + 1;
			flag = false;
		}
		if (dep < 0) flag = true;
	}
	if (dep != 0) cout << "-1" << endl;
	else cout << cnt << endl;
	return 0;
}