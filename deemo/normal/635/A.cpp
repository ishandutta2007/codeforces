#include<iostream>
#include<algorithm>

using namespace std;

int n, m, aa, bb;
bool mark[20][20];

int main(){
	cin >> n >> m >> aa >> bb;
	for (int i = 0; i < aa; i++){
		int x, y;	cin >> x >> y;	x--, y--;
		mark[x][y] = 1;
	}
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int a = 1; a <= n - i; a++)
				for (int b = 1; b <= m - j; b++){
					int cnt = 0;
					for (int w = i; w < i + a; w++)
						for (int q = j; q < j + b; q++)
							if (mark[w][q])	cnt++;
					if (cnt >= bb)
						ret++;
				}
	cout << ret << "\n";
	return	0;
}