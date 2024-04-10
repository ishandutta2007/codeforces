#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

int a, b, c, d;

int get(int x, int y){
	return	abs(c - x) + abs(d - y);
}

int main(){
	int t;	cin >> t;	
	cin >> a >> b >> c >> d;
	string s;	cin >> s;
	int i;
	for (i = 0; i < t; i++){
		if (a == c && b == d)	break;
		int addx = 0, addy= 0 ;
		int ta = a, tb = b;
		if (s[i] == 'N')	tb++;
		if (s[i] == 'S')	tb--;
		if (s[i] == 'E')	ta++;
		if (s[i] == 'W')	ta--;
		
		if (get(a, b) > get(ta, tb)){
			b = tb;
			a = ta;
		}
	}

	if (a == c && b == d){
		cout << i << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}