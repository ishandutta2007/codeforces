#include<bits/stdc++.h>

using namespace std;

#define FAIL {cout << "NO\n"; return 0;}

const int MAXN = 1e5 + 10;

int n, k, x, y;
string ans;

int main(){
	cin >> n >> k >> x >> y;
	int z = 0;
	for (int i = 0; i < n; i++){
		if (x == y){
			if (i == 0 || ans.back() == 'G')
				ans += 'B', z = 1, y--;
			else
				ans += 'G', z = 1, x--;
		}
		else if (x > y){
			if (i == 0 || ans.back() != 'G' || ans.back()=='G' && z<k){
				x--;
				if (i && ans.back() == 'G')	z++;
				else	z = 1;
				ans += 'G';
			}
			else{
				if (y == 0)	FAIL
				y--;
				z = 1;
				ans += 'B';
			}
		}
		else if (x < y){
			if (i == 0 || ans.back() != 'B' || ans.back()=='B' && z<k){
				y--;
				if (i && ans.back() == 'B')	z++;
				else	z = 1;
				ans += 'B';
			}
			else{
				if (x == 0)	FAIL
				x--;
				z = 1;
				ans += 'G';
			}
		}
	}
	cout << ans << "\n";
	return 0;
}