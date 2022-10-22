#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e3 + 10;

int n, a[MAXN], b[MAXN], c[MAXN], d[MAXN], ans;
bool vec[MAXN][MAXN];

void get(int ind){
	for (int i = 0; i < n; i++)
		if (vec[i][ind] && vec[ind][i])	a[ind]++;
		else if (!vec[i][ind] && !vec[ind][i])	d[ind]++;
		else if (vec[i][ind] && !vec[ind][i])	b[ind]++;
		else if (!vec[i][ind] && vec[ind][i])	c[ind]++;
	ans += a[ind];
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)	scanf("%d", &vec[i][j]);
	for (int i = 0; i < n; i++)
		get(i);

	int q;	scanf("%d", &q);
	while (q--){
		int type;	scanf("%d", &type);
		if (type == 3)
			printf("%d", ans & 1);
		else if (type == 2){
			int col;	scanf("%d", &col), col--;
			ans -= 2*a[col];
			if (vec[col][col])	ans++;

			swap(a[col], b[col]);
			swap(c[col], d[col]);
			vec[col][col] = !vec[col][col];

			ans += 2 * a[col];
			if (vec[col][col])
				ans--;
		}
		else{
			int ro;	scanf("%d", &ro), ro--;
			ans -= 2 * a[ro];
			if (vec[ro][ro])	ans++;

			swap(a[ro], c[ro]);
			swap(b[ro], d[ro]);
			vec[ro][ro] = !vec[ro][ro];

			ans += 2 * a[ro];
			if (vec[ro][ro])
				ans--;
		}
	}
	printf("\n");
	return 0;
}