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
vector<int>V;
int main() {
	int n; cin >> n;
	for (int i = 2; i <= n; i += 2)V.push_back(i);
	for (int i = 1; i <= n; i += 2)V.push_back(i);
	for (int i = 2; i <= n; i += 2)V.push_back(i);
	cout << V.size() << endl;
	for (int i = 0; i < V.size(); i++) {
		if (i)cout << " "; cout << V[i];
	}
	cout << endl;
	return 0;
}