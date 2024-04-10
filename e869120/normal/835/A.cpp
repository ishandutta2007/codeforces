#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
int a, b, c, d, e;
int main() {
	cin >> a >> b >> c >> d >> e;
	int f = a*b + d * 2;
	int g = a*c + e * 2;
	if (f < g)cout << "First" << endl;
	else if (f > g)cout << "Second" << endl;
	else cout << "Friendship" << endl;
	return 0;
}