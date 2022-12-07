#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << max(max(a, b), c) - min(min(a, b), c) << endl;
}