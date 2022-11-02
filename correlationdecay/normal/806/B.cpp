#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#define maxn 1009
using namespace std;
const int INF = 1e9 + 8;
int n;
int a[maxn][6];
int tp[6];
int pass[6];
int pt[]={500, 1000, 1500, 2000, 2500, 3000};
int solve(int x){
	int y = x;
	for(int i = 0; i < 5; i++){
		tp[i] = y % 6;
		y /= 6;
		//cout << tp[i] << endl;
	}
	int my = 0;
	int he = 0;
	for(int i = 0; i < 5; i++){
		if(a[1][i] != -1){
			my += pt[tp[i]] - pt[tp[i]] * a[1][i] / 250;
		}
		if(a[2][i] != -1){
		  	he += pt[tp[i]] - pt[tp[i]] * a[2][i] / 250;
		}
	}
	if(my <= he)
		return INF;
	int ans = 0;
	int up = INF;
	for(int i = 0; i < 5; i++){
		if(tp[i] <= 4){
			int L = 1 << (tp[i] + 1);
			int R = 1 << tp[i];
			if(pass[i] * L > n && pass[i] * R <= n){
				if(a[1][i] == -1)
					up = min(up, pass[i] * L - n - 1);		
			}
			else if(pass[i] * L <= n){
				if(a[1][i] == -1)
					return INF;
				int t = (n - L * pass[i] +1 + L - 1 + 1) / (L - 1);
				ans = max(ans, t);
			}
			else{
				if(a[1][i] == -1)
					up = min(up, pass[i] * L - n - 1);
				ans = max(ans, pass[i] * R - n);
			}
		}
		else{
			if(32 * pass[i] > n){
				ans = max(ans, 32 * pass[i] - n);
			}
		}
	}
	if(ans <= up){
		
		//if(ans == 1)
			//cout << x << endl;
		return ans;
	}
	else
		return INF;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 5; j++){
			scanf("%d", &a[i][j]);
			if(a[i][j] != -1){
				pass[j]++;
			}
		}
	
	int tot = 1;
	for(int i = 0; i < 5; i++)
		tot *= 6;
	int ans = INF;
	
	for(int i = 0; i < tot; i++){
		ans = min(ans, solve(i));
	}
	
	//cout << solve(6708) << endl;
	if(ans >= INF)
	{
		puts("-1");
		return 0;
	}
	cout << ans << endl;
	return 0;
}