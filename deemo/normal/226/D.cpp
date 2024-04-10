#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 100 + 10;

int n, m;
int c[MAXN][MAXN];
int s[MAXN], t[MAXN], cs[MAXN], ct[MAXN];

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> c[i][j];
			s[i] += c[i][j];
			t[j] += c[i][j];
		}

	bool fl = 1;
	int c1 = 0, c2 = 0;
	while (fl){
		fl = 0;
		for (int i = 0; i < n; i++)
			if (s[i] < 0){
				fl = 1;
				cs[i]++;
				if (cs[i] % 2 == 1)	c1++;
				else	c1--;
				for (int j = 0; j < m; j++){
					c[i][j] = -c[i][j];
					t[j] -= -c[i][j], t[j] += c[i][j];
				}
				s[i] *= -1;
			}

		for (int j = 0; j < m; j++)
			if (t[j] < 0){
				fl = 1;
				ct[j]++;
				if (ct[j] % 2 == 1)	c2++;
				else	c2--;
				for (int i = 0; i < n; i++){
					c[i][j] *= -1;
					s[i] -= -c[i][j], s[i] += c[i][j];
				}
				t[j] *= -1;
			}				
	}
	cout << c1 << " ";
	for (int i = 0; i < n; i++)
		if (cs[i] % 2 == 1)
			cout << i + 1 << " ";
	cout << endl;

	cout << c2 << " ";
	for (int j = 0; j < m; j++)
		if (ct[j] % 2 == 1)
			cout << j + 1 << " ";
	cout << endl;
	return 0;
}