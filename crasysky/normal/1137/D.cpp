#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e6 + 6;
int read(){
	int n; string s;
	cin >> n; for (int i = 1; i <= n; ++ i) cin >> s; cout.flush();
	return n;
}
int main(){
	cout << "next 1 2" << endl;
	int n = read();
	cout << "next 1" << endl;
	n = read();
	while (n == 3){
		cout << "next 1 2" << endl;
		n = read();
		cout << "next 1" << endl;
		n = read();
	}
	int t = 0;
	while (n == 2){
		cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
		n = read();
	}
	cout << "done" << endl;
}