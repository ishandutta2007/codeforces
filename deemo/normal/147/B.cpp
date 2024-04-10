#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

const int max_n = 300 + 5;
const int INF = 1e9;

int n, m;

struct Mat{
	int val[max_n][max_n];
	Mat(){
		for (int i = 0; i < max_n; i++)
			for (int j = 0; j < max_n; j++)
				if (i != j)
					val[i][j] = -INF;
				else
					val[i][j] = 0;
	}
};

Mat operator *(Mat a, Mat b){
	Mat ret;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int z = 0; z < n; z++)
				ret.val[i][j] = max(ret.val[i][j], a.val[i][z] + b.val[z][j]);
	return	ret;
}

const int LOG = 10 + 2;

Mat t[LOG + 1];

void init(){
	for (int i = 1; i < LOG; i++)
		t[i] = t[i - 1] * t[i - 1];
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		int a, b;	scanf("%d%d", &a, &b);	a--, b--;
		scanf("%d%d", &t[0].val[a][b], &t[0].val[b][a]);
	}
	init();
	
	int ret = 0;
	Mat z;
	for (int i = LOG - 1; i >= 0; i--){
		Mat temp = z * t[i];
		bool fl = 0;

		for (int j = 0; j < n; j++)
			if (temp.val[j][j] > 0){
				fl = 1;
				break;
			}
		if (!fl){
			ret ^= (1 << i);
			z = temp;
		}
	}
	if (ret > n)	printf("%d\n", 0);
	else	printf("%d\n", ret + 1);
	return 0;
}