#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 300 + 5;

bool d[MAX][MAX][MAX], b[MAX][MAX][MAX];
bool c[3][MAX][MAX][MAX];
bool g[MAX][MAX], ff[MAX][MAX];
bool gg[2][MAX][MAX];

void init(){
	d[0][0][0] = 0;
	int i[3];
	for (i[0] = 0; i[0] < MAX; i[0]++)
		for (i[1] = 0; i[1] < MAX; i[1]++)
			for (i[2] = 0; i[2] < MAX; i[2]++){
				if (i[0] == i[1] && i[1] == i[2] && i[2] == 0)	continue;
				bool win = 0;
				if (i[0])
					win |= !(c[0][i[0] - 1][i[1]][i[2]]);
				if (i[1])
					win |= !(c[1][i[0]][i[1] - 1][i[2]]);
				if (i[2])
					win |= !(c[2][i[0]][i[1]][i[2] - 1]);
				
				if (i[0] && i[1] && i[2])	
					win |= !(b[i[0] - 1][i[1] - 1][i[2] - 1]);
				
				d[i[0]][i[1]][i[2]] = win;
				for (int w = 0; w < 3; w++)
					c[w][i[0]][i[1]][i[2]] = win;
				if (i[0])
					c[0][i[0]][i[1]][i[2]] &= c[0][i[0] - 1][i[1]][i[2]];
				if (i[1])
					c[1][i[0]][i[1]][i[2]] &= c[1][i[0]][i[1] - 1][i[2]];
				if (i[2])
					c[2][i[0]][i[1]][i[2]] &= c[2][i[0]][i[1]][i[2] - 1];

				b[i[0]][i[1]][i[2]] = win;
				if (i[0] && i[1] && i[2])
					b[i[0]][i[1]][i[2]] &= b[i[0] - 1][i[1] - 1][i[2] - 1];
			}

	g[0][0] = 0;
	for (i[0] = 0; i[0] < MAX; i[0]++)
		for (i[1] = 0; i[1] < MAX; i[1]++){
			if (i[0] == i[1] && i[1] == 0)	continue;
			bool win = 0;
			if (i[0])
				win |= !(gg[0][i[0] - 1][i[1]]);
			if (i[1])
				win |= !(gg[1][i[0]][i[1] - 1]);
			if (i[0] && i[1])
				win |= !(ff[i[0] - 1][i[1] - 1]);

			g[i[0]][i[1]] = win;
			for (int w = 0; w < 2; w++)
				gg[w][i[0]][i[1]] = g[i[0]][i[1]];
			if (i[0])
				gg[0][i[0]][i[1]] &= gg[0][i[0] - 1][i[1]];
			if (i[1])
				gg[1][i[0]][i[1]] &= gg[1][i[0]][i[1] - 1];

			ff[i[0]][i[1]] = win;
			if (i[0] && i[1])
				ff[i[0]][i[1]] &= ff[i[0] - 1][i[1] - 1];
		}
}

int main(){
	init();
	int n;	cin >> n;
	vector<int>	vec(3);
	for (int i = 0; i < n; i++)	cin >> vec[i];
	bool ans = d[vec[0]][vec[1]][vec[2]];
	if (n == 2)
		ans = g[vec[0]][vec[1]];
	if (ans)
		cout << "BitLGM\n";
	else
		cout << "BitAryo\n";
	return 0;
}