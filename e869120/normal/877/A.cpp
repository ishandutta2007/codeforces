#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<ctime>
using namespace std;
#pragma warning(disable: 4996)

string S; int cnt = 0;
int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (i <= (int)S.size() - 5 && S.substr(i, 5) == "Danil") { cnt++; }
		if (i <= (int)S.size() - 4 && S.substr(i, 4) == "Olya") { cnt++; }
		if (i <= (int)S.size() - 5 && S.substr(i, 5) == "Slava") { cnt++; }
		if (i <= (int)S.size() - 3 && S.substr(i, 3) == "Ann") { cnt++; }
		if (i <= (int)S.size() - 6 && S.substr(i, 6) == "Nikita") { cnt++; }
	}
	if (cnt == 1)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}