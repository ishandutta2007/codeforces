#include<iostream>
#include<cmath>
#include<algorithm>
#include<utility>

using namespace std;

int main(){
	int x = 0, y = 0;
	int ans = 0;
	int a, b;	cin >> a >> b;

	int dir = 0,	tm = 1, cur = 0, last = 0;
	while (a != x || y != b){
		cur++;
		if (dir == 0)	x++;
		if (dir == 1)	y++;
		if (dir == 2)	x--;
		if (dir == 3)	y--;

		if (a == x && y == b)	break;
		if (last + tm == cur){
			ans++;
			if (dir == 1 || dir == 3)	tm++;
			dir = (dir + 1) % 4;
			last = cur;
		}
	}

	cout << ans << endl;
	return 0;
}