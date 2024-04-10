#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int n, r, g, b;
string s;
bool ans[500];

int main(){
	cin >> n >> s;
	for (char ch:s)
		if (ch == 'R')	r++;
		else if (ch == 'G')	g++;
		else if (ch == 'B')	b++;

	if (r && g == 0 && b == 0)
		ans['r'] = 1;
	if (g && b)	
		ans['r'] = 1;
	if (r && max(g, b) > 1)
		ans['r'] = 1;

	if (g && r == 0 && b == 0)
		ans['g'] = 1;
	if (r && b)
		ans['g'] = 1;
	if (g && max(r, b) > 1)
		ans['g'] = 1;

	if (b && r == 0 && g == 0)
		ans['b'] = 1;
	if (r && g)
		ans['b'] = 1;
	if (b && max(r, g) > 1)
		ans['b'] = 1;

	if (ans['b'])
		cout << "B";
	if (ans['g'])
		cout << "G";
	if (ans['r'])
		cout << "R";
	cout << "\n";
	return	0;
}