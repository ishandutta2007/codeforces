#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 1e4 + 10;
const int MX = 100 + 3;

int n, x, y;
int c[MX][MX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> x >> y;
	if (n > x * y){
		cout << "-1\n";
		return 0;
	}

	if (y & 1){
		int cur = 1;
		for (int i = 0; cur <= n && i < x; i++)
			for (int j = 0; cur <= n && j < y; j++)
				c[i][j] = cur++;
	}
	else if (x & 1){
		int cur = 1;
		for (int j = 0; cur <= n && j < y; j++)
			for (int i = 0; cur <= n && i < x; i++)
				c[i][j] = cur++;
	}
	else{
		y--;
		int cur = 1;
		for (int i = 0; cur <= n && i < x; i++)
			for (int j = 0; cur <= n && j < y; j++)
				c[i][j] = cur++;
	
		int z = n;
		y++;
		if (n == x * y)
			for (int i = 0; cur <= z && i < x; i++)
				c[i][y - 1] = z--;
		else
			for (int i = 1; cur <= n && i < x; i++)
				c[i][y - 1] = cur++;
	}

	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++)
			cout << c[i][j] << " ";
		cout << "\n";
	}
	return	0;
}