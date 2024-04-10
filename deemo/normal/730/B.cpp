#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 50 + 2;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te;	cin >> te;
	while (te--){
		int n;	cin >> n;
		pair<int, int> x(1, 1);
		if (n % 2 == 0){
			cout << "? " << 1 << " " << n << endl;
			char ch;	cin >> ch;
			if (ch == '>')
				x.F = n;
			else
				x.S = n;
		}
		int i = 2;
		for (; i + 1 <= n; i += 2){
			cout << "? " << i << " " << i + 1<< endl;
			char ch;	cin >> ch;
			cout << "? " << x.F << " " << (ch == '<'?i:i+1) << endl;
			char a;	cin >> a;
			if (a == '>')
				x.F = (ch == '<'?i:i+1);
			cout << "? " << x.S << " " << (ch == '>'?i:i+1) << endl;
			char b;	cin >> b;
			if (b == '<')
				x.S = (ch == '>'?i:i+1);
			
		}
		cout << "! " << x.F << " " << x.S << endl;
	}
	return 0;
}