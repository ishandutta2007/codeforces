#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 100;

int n, m;
char ch[MAXN][MAXN];

bool ok(int a, int b, int c, int d){
	if (a == c && b == d)	return	true;
	int ta = a, tb = b;

	bool ret = 1;
	while (a < c){
		a++;
		if (ch[a][b] == 'W')	ret = 0;
	}
	while (b < d){
		b++;
		if (ch[a][b] == 'W')	ret = 0;
	}
	if (ret)	return	true;

	a = ta, b = tb;
	ret = 1;
	while (b < d){
		b++;
		if (ch[a][b] == 'W')	ret = 0;
	}
	while (a < c){
		a++;
		if (ch[a][b] == 'W')	ret = 0;
	}
	return	ret;
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ch[i][j];

	bool ret = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = i; k < n; k++)
				for (int w = j; w < m; w++)
					if (ch[i][j] == 'B' && ch[k][w] == 'B')
						if (!ok(i, j, k, w))	ret = 0;

	for (int i = 0; i < n; i++)
		reverse(ch[i], ch[i] + m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = i; k < n; k++)
				for (int w = j; w < m; w++)
					if (ch[i][j] == 'B' && ch[k][w] == 'B')
						if (!ok(i, j, k, w))	ret = 0;
				
	if (ret)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}