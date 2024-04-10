#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e3 + 20;

ld d[MAXN][MAXN];

int main(){
	int w, b;	cin >> w >> b;
	cout << fixed << setprecision(12);

	for (int i = 0; i <= w; i++)
		for (int j = 0; j <= b; j++)
			if (i || j){
				d[i][j] = ld(i)/ ld(i + j);
				ld t = ld(j)/ ld(i + j);
				t *= ld(j - 1)/ ld(i + j - 1);
				
				if (j >= 2 && i + j >= 3){
					if (i)
						d[i][j] += t * ld(i)/ ld(i + j - 2) * d[i-1][j - 2];
					if (j >= 3)
						d[i][j] += t * ld(j - 2)/ ld(i + j - 2) * d[i][j - 3];
				}
			}
		
	cout << d[w][b] << endl;
	return 0;
}