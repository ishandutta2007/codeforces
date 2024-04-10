#include <bits/stdc++.h>
using namespace std;

int main() {	
	int c = 0,n,a=0,d;
	cin >> n >> d;
	for(int i = 0; i < d; ++i) {
		string s;
		cin >> s;
		bool a1 = true;
		for(char x : s)
			a1 &= x == '1';
		if(a1) c = 0;
		else ++c;
		a = max(a,c);
	}
	cout << a << "\n";
}