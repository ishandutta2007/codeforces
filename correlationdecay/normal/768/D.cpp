#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#define maxn 1300
using namespace std;
int k,q;
int ans[maxn];
struct node{
	int p, id;
	bool operator < (const node &rhs)const{
		return p < rhs.p;
	}
}a[maxn];
double dp[2][maxn];
bool f(double p, double cur){
	double eps  = 5e-8;
	if(cur > (p - eps) / 2000)
		return 1;
	else
		return 0;
}
int main(){
	cin >> k >> q;
	for(int i = 0 ;i < q; i++){
		cin >> a[i].p;
		a[i].id = i;
	}
	sort(a, a + q);
	int cur = 0, day = 0;
	dp[0][0] = 1;
	int p = 0;
	while(p < q){
		while(p < q && f(a[p].p, dp[cur][k])){
			ans[a[p].id] = day;
			p++;
		}
		if(p >= q)
			break;
		for(int i = 0 ; i <= k ; i++){
			dp[cur ^ 1][i] = 0;
		}	
		for(int i = 0; i <= k; i++){
			dp[cur ^ 1][i] += 1.0 * i / k * dp[cur][i];
			dp[cur ^ 1][i + 1] += 1.0 * (1.0 * k - i) / k * dp[cur][i];
		}
		cur ^= 1;
		day++;
	}
	for(int i = 0; i < q; i++)
		cout << ans[i] << endl;
	return 0;
}