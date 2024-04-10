#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

string s, t;
int c[3][500];

int main(){
	cin >> s >> t;
	for (char ch:s)
		c[0][ch]++;
	for (char ch:t)
		c[1][ch]++;

	bool fl = 0, fl2 = 0;
	for (int i = 0; i < 400; i++){
		if (c[0][i] != c[1][i])	fl = 1;
		if (c[0][i] < c[1][i]){
			cout << "need tree\n";
			return	0;
		}
	}
	if (fl == 0){
		cout << "array\n";
		return	0;
	}

	int b = 0;
	for (int i = 0; b < t.size() && i < s.size(); i++)
		if (t[b] == s[i])	b++;
	if (b == t.size()){
		cout << "automaton\n";
		return	0;
	}
	cout << "both\n";
	return	0;
}