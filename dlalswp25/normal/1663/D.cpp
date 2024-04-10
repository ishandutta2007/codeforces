#include <bits/stdc++.h>

using namespace std;

string s;
int X;

int main() {
	cin >> s;
	scanf("%d", &X);
	if(s == "ABC") {
		puts(X <= 2000 ? "YES" : "NO");
	}
	else if(s == "ARC") {
		puts(X <= 2800 ? "YES" : "NO");
	}
	else {
		puts(X >= 1200 ? "YES" : "NO");
	}
	return 0;
}