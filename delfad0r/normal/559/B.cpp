#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

void transform(string & S, int b, int e) {
	if((e - b) & 1) return;
	int m = (b + e) >> 1;
	transform(S, b, m);
	transform(S, m, e);
	if(!lexicographical_compare(S.begin() + b, S.begin() + m, S.begin() + m, S.begin() + e))
		rotate(S.begin() + b, S.begin() + m, S.begin() + e);
}

string A, B;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> A >> B;
	
	transform(A, 0, A.length());
	transform(B, 0, B.length());
	
	cout << ((A == B) ? ("YES") : ("NO"));
}