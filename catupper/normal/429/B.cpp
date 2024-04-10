#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int lt[1080][1080], lb[1080][1080], rt[1080][1080], rb[1080][1080];
int a[1080][1080];
int main(){
	int n ,m;
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			scanf("%d", &a[i][j]);
	
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			lt[i][j] = max(lt[i - 1][j], lt[i][j - 1]) + a[i][j];
			
	for(int i = 1;i <= n;i++)
		for(int j = m;j >= 1;j--)
			rt[i][j] = max(rt[i - 1][j], rt[i][j + 1]) + a[i][j];
	
	for(int i = n;i >= 1;i--)
		for(int j = 1;j <= m;j++)
			lb[i][j] = max(lb[i + 1][j], lb[i][j - 1]) + a[i][j];
			
	for(int i = n;i >= 1;i--)
		for(int j = m;j >= 1;j--)
			rb[i][j] = max(rb[i + 1][j], rb[i][j + 1]) + a[i][j];

	int res = 0;
	
	for(int i = 2;i <= n - 1;i++){
		for(int j = 2;j <= m - 1;j++){
//			res = max(res, lt[i - 1][j] + lb[i + 1][j] + rb[i + 1][j] + rt[i - 1][j]);
//			res = max(res, lt[i - 1][j] + lb[i][j - 1] + rb[i + 1][j] + rt[i - 1][j]);
//			res = max(res, lt[i][j - 1] + lb[i + 1][j] + rb[i + 1][j] + rt[i - 1][j]);
//			res = max(res, lt[i][j - 1] + lb[i][j - 1] + rb[i + 1][j] + rt[i - 1][j]);
//			res = max(res, lt[i - 1][j] + lb[i + 1][j] + rb[i + 1][j] + rt[i][j + 1]);
			res = max(res, lt[i - 1][j] + lb[i][j - 1] + rb[i + 1][j] + rt[i][j + 1]);
//			res = max(res, lt[i][j - 1] + lb[i + 1][j] + rb[i + 1][j] + rt[i][j + 1]);
//			res = max(res, lt[i][j - 1] + lb[i][j - 1] + rb[i + 1][j] + rt[i][j + 1]);
//			res = max(res, lt[i - 1][j] + lb[i + 1][j] + rb[i][j + 1] + rt[i - 1][j]);
//			res = max(res, lt[i - 1][j] + lb[i][j - 1] + rb[i][j + 1] + rt[i - 1][j]);
			res = max(res, lt[i][j - 1] + lb[i + 1][j] + rb[i][j + 1] + rt[i - 1][j]);
//			res = max(res, lt[i][j - 1] + lb[i][j - 1] + rb[i][j + 1] + rt[i - 1][j]);
//			res = max(res, lt[i - 1][j] + lb[i + 1][j] + rb[i][j + 1] + rt[i][j + 1]);
//			res = max(res, lt[i - 1][j] + lb[i][j - 1] + rb[i][j + 1] + rt[i][j + 1]);
//			res = max(res, lt[i][j - 1] + lb[i + 1][j] + rb[i][j + 1] + rt[i][j + 1]);
//			res = max(res, lt[i][j - 1] + lb[i][j - 1] + rb[i][j + 1] + rt[i][j + 1]);
		}
	}
	cout << res << endl;
	return 0;	
}