#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
const int INF = 1e9;
const int maxn = 2e6 + 6;
string s;
int read(){
	int c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f;
}
int main(){
	int t = read();
	while (t --){
		int n = read();
		cin >> s;
		int c = 0, f = 0;
		for (int i = 0; i < n; ++ i)
			if (s[i] != '8')
				++ c;
			else{
				f = 1;
				break;
			}
		if (f && n - c >= 11)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}