#include<fstream>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 50 + 5;

int n, m;
int c[MAXN][MAXN];
int p[MAXN][MAXN];

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> c[i][j];
			p[i + 1][j + 1] = p[i + 1][j] + p[i][j + 1] - p[i][j] + c[i][j];
		}				

	int ts[3];
	for (int i = 0; i < 3; i++)	cin >> ts[i];
	sort(ts, ts + 3);
	int cnt = 0;
	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m - 1; j++){
			int t[3] = {p[n][i + 1], p[n][j + 1] - p[n][i + 1], p[n][m] - p[n][j + 1]};
			sort(t, t + 3);
			bool fl = 1;
			for (int w = 0; w < 3; w++)
				if (ts[w] != t[w])	fl = 0;
			if (fl)	cnt++;
		}

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n - 1; j++){
			int t[3] = {p[i + 1][m], p[j + 1][m] - p[i + 1][m], p[n][m] - p[j + 1][m]};
			sort(t, t + 3);
			bool fl = 1;
			for (int w = 0; w < 3; w++)
				if (ts[w] != t[w])	fl = 0;
			if (fl)	cnt++;
		}
	cout << cnt << endl;
	return 0;
}