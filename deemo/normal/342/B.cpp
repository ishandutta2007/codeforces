#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<string>

using namespace std;

int n, m, s, f;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s >> f;
	int cur = 1;
	for (int i = 0; i < m; i++){
		int j, t, l, r;	cin >> t >> l >> r;
		for (j = cur; j < t; j++){
			if (s > f)
				s--, cout << "L";
			else
				s++, cout << "R";
			if (s == f){
				cout << endl;
				return 0;
			}
		}
		if (s < l || s > r){
			if (s > f && (s - 1 > r || (s - 1 < l)))
				s--, cout << "L";
			else if (s < f && ((s + 1 < l || s + 1 > r)))
				s++, cout << "R";
			else
				cout << "X";
			if (s == f){
				cout << endl;
				return 0;
			}
		}
		else	cout << "X";
		cur = t + 1;
	}
	while (f != s){
		if (s > f)
			s--, cout << "L";
		else
			s++, cout << "R";
	}
	return 0;
}