#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

bool isvowel(char c){
	return (c=='a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	string ss; int n;
	cin >> n >> ss;
	char x[1000];
	x[0] = ss.at(0);
	int ii = 1;
	for(int i=1;i<n;++i) {
		if(!(isvowel(ss.at(i-1)) && isvowel(ss.at(i))))
			x[ii++] = ss.at(i);
	}
	x[ii] = 0;
	cout << x << endl;

	return 0;
}