#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>

using namespace std;

const int max_n = 1e3;

struct Thing{
	int first, second;
	Thing(int a, int b){
		first = a;
		second = b;
	}
};

bool operator <(Thing a, Thing b){
	return a.first > b.first;
}

int n;
int ans[max_n];
int mat[max_n][max_n];
set<Thing>	st[max_n];
int mark[max_n];
bool picked[max_n];

int main(){
	scanf("%d", &n);
	for (int i = 1; i < 2 * n; i++)
		for (int j = 0; j < i; j++)
			scanf("%d", &mat[i][j]);
	
	for (int i = 0; i < 2 * n; i++)
		for (int j = 0; j < 2 * n; j++){
			if (i == j)	continue;
			int t = max(mat[i][j], mat[j][i]);
			st[i].insert(Thing(t, j));
		}	

	for (int i = 0; i < n; i++){
		fill(mark, mark + 2 * n, 0);
		for (int j = 0; j < 2 * n; j++){
			if (picked[j])	continue;
			while (picked[(*st[j].begin()).second])	st[j].erase(st[j].begin());
			int t = (*st[j].begin()).second;
			mark[j] = t;
			if (t > j)	continue;
			if (mark[t] == j){
				ans[j] = t;
				ans[t] = j;
				picked[t] = picked[j] = 1;
				break;
			}
		}
	}
	for (int i = 0; i < 2 * n; i++)
		printf("%d ", ans[i] + 1);
	printf("\n");
	return 0;
}