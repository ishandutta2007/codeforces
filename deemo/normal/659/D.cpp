#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<cassert>

using namespace std;

const int MAXN = 1e4 + 30;

int n, x[MAXN], y[MAXN];
string s;

int check(string t){
	if (t == "UL")	return 1;
	if (t == "UR")	return 0;
	if (t == "DL")	return 0;
	if (t == "DR")	return 1;
	if (t == "LU")	return 0;
	if (t == "LD")	return 1;
	if (t == "RU")	return 1;
	if (t == "RD")	return 0;
	assert(0);
}

int main(){	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i <= n; i++)	cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++){
		if (x[i] < x[i + 1])	s += 'R';
		if (x[i] > x[i + 1])	s += 'L';
		if (y[i] < y[i + 1])	s += 'U';
		if (y[i] > y[i + 1])	s += 'D';
	}
	int cn = 0;
	for (int i = 0; i < n; i++){
		string temp;
		temp += s[i];
		temp += s[(i + 1) % n];
		cn += check(temp);
	}
	cout << cn << "\n";
	return	0;
}