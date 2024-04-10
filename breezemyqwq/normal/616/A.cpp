#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
string a, b;
int lena, lenb, asize, bsize;

int main() {
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++) {
		if(a[i] != '0') break;
		lena++;
	}
	for (int i = 0; i < b.size(); i++) {
		if(b[i] != '0') break;
		lenb++;
	}
	//cout << lena << ' ' << lenb << endl;
	if(lena) a.erase(0, lena);
	if(lenb) b.erase(0, lenb);
	//cout << a << ' ' << b << endl;
	//cout << lena << ' ' << lenb << endl;
	if (a.size() > b.size()) printf(">\n");
	else if (a.size() < b.size()) printf("<\n");
	else {
		if (a > b) printf(">\n");
		else if (a < b) printf("<\n");
		else printf("=\n");
	}
	return 0;
}