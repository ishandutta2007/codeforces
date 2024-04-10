#include<iostream>
#include<string>

using namespace std;

int t11, t10, t01, t00;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	string s;	cin >> s;
	string t;	cin >> t;
	for (int i = 0; i < 2 * n; i++)
		if (s[i] == '1' && t[i] == '1')	t11++;
		else if (s[i] == '1' && t[i] == '0')	t10++;
		else if (s[i] == '0' && t[i] == '1')	t01++;
		else	t00++;
	
	int c1 = 0, c2 = 0;
	c1 += t11/2 + bool(t11 % 2 == 1);
	c2 += t11/2;
	
	if (t11 % 2 == 0){
		int z = min(t01, t10);
		t01 -= z, t10 -= z;
		
		if (t10)	c1 += t10 / 2 + bool(t10 % 2 == 1);
		else if (t01 > 1)	c2 += (t01 - 1) / 2 + bool(t01 % 2 == 0);
	}
	else{
		int z = min(t01, t10);
		t01 -= z,	t10 -= z;
		
		if (t01)	c2 += t01/2 + bool(t01 % 2 == 1);
		else if (t10 > 1)	c1 += (t10 - 1) / 2 + bool(t10 % 2 == 0);
	}

	if (c1 == c2)
		cout << "Draw\n";
	else if (c1 > c2)
		cout << "First\n";
	else
		cout << "Second\n";

	return 0;	
}