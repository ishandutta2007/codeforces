#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int> x(4), y(4);
void feed(int i) {
	cout << i << ' ';
	for(int j = 0; j < y[i]; ++j) {
		cout << i+1 << ' ' << i << ' ';
	}
}

void sub(int i) {
	int d = min(x[i], x[i+1])-1;
	d = max(d, 0);
	y[i] = d;
	x[i] -= d;
	x[i+1] -= d;
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	for(int i = 0; i < 4; ++i)
		cin >> x[i];
	sub(0), sub(2), sub(1);
	if(x == vector<int>({1,1,1,1})) {
		cout << "YES\n";
		feed(0), feed(1), feed(2), feed(3);
	} else if(x == vector<int>({1,1,2,1})) {
		cout << "YES\n";
		feed(2), feed(3), cout << "2 ", feed(1), feed(0);
	} else if(x == vector<int>({1,2,1,1})) {
		cout << "YES\n";
		feed(1), feed(0), cout << "1 ", feed(2), feed(3);
	} else if(x == vector<int>({0,1,1,1})){
		cout << "YES\n";
		feed(1), feed(2), feed(3);
	} else if(x == vector<int>({1,1,1,0})){
		cout << "YES\n";
		feed(0), feed(1), feed(2);
	} else if(x == vector<int>({1,1,0,0})){
		cout << "YES\n";
		feed(0), feed(1);
	} else if(x == vector<int>({0,1,1,0})){
		cout << "YES\n";
		feed(1), feed(2);
	} else if(x == vector<int>({0,0,1,1})){
		cout << "YES\n";
		feed(2), feed(3);
	} else if(x == vector<int>({1,2,0,0})){
		cout << "YES\n";
		cout << "1\n", feed(0), feed(1);
	} else if(x == vector<int>({0,1,2,0})){
		cout << "YES\n";
		cout << "2\n", feed(1), feed(2);
	} else if(x == vector<int>({0,0,1,2})){
		cout << "YES\n";
		cout << "3\n", feed(2), feed(3);
	} else if(x == vector<int>({2,1,0,0})){
		cout << "YES\n";
		feed(0), feed(1), cout << "0";
	} else if(x == vector<int>({0,2,1,0})){
		cout << "YES\n";
		feed(1), feed(2), cout << "1";
	} else if(x == vector<int>({0,0,2,1})){
		cout << "YES\n";
		feed(2), feed(3), cout << "2";
	} else if(x == vector<int>({1,0,0,0})){
		cout << "YES\n";
		feed(0);
	} else if(x == vector<int>({0,1,0,0})){
		cout << "YES\n";
		feed(1);
	} else if(x == vector<int>({0,0,1,0})){
		cout << "YES\n";
		feed(2);
	} else if(x == vector<int>({0,0,0,1})){
		cout << "YES\n";
		feed(3);
	} else if(x == vector<int>({1,2,1,0})){
		cout << "YES\n";
		feed(1), feed(0), cout << "1 ", feed(2);
	} else if(x == vector<int>({0,1,2,1})){
		cout << "YES\n";
		feed(2), feed(1), cout << "2 ", feed(3);
	} else if(x == vector<int>({1,3,1,0})){
		cout << "YES\n";
		feed(1), feed(0), cout << "1 ", feed(2), cout << "1";
	} else if(x == vector<int>({0,1,3,1})){
		cout << "YES\n";
		feed(2), feed(1), cout << "2 ", feed(3), cout << "2";
	} else {
		cout << "NO\n";
	}
}