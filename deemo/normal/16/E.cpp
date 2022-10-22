#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef double ld;

const int MAXN = 18;
const int MAX = 1 << MAXN;

int n;
ld p[MAXN][MAXN], ss[MAX][MAXN], def[MAX][MAXN];

int main(){
	cout << fixed << setprecision(9);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> p[i][j];

	int z = (1 << n);
	for (int i = 1; i < z; i++){
		int t = __builtin_popcount(i);
		if (t > 1){
			ld prob = ld(1) / ld(t * (t - 1)/ 2);
			for (int j = 0; j < n; j++)
				if ((i >> j) & 1){
					ld ret = 0;
					for (int w = 0; w < n; w++)
						if (w != j && (i >> w) & 1)
							ret += prob * p[w][j];
					def[i][j] = ret;
				}
		}
	}

	for (int i = 1; i < z; i++){
		int t = __builtin_popcount(i);
		for (int j = 0; j < n; j++)
			if ((i >> j) & 1){
				if (t == 1)
					ss[i][j] = 1;
				else{
					ld ret = 0;
					for (int w = 0; w < n; w++)
						if (w != j && (i >> w) & 1)
							ret += def[i][w] * ss[i ^ (1 << w)][j];
					ss[i][j] = ret;
				}
			}
	}

	for (int i = 0; i < n; i++)
		cout << ss[z - 1][i] << " ";
	cout << "\n";
	return 0;
}