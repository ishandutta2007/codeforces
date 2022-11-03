#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define DBGG(i , j) cout << i << " " << j << endl
//------------------------------------------
#define int long long
#define INF 0x3f3f3f3f
#define MAX 100900

int n , k;
double len , v1 , v2;
int judge(double goal){
	double b = (goal * v1 * v2 - len * v2) / (v1 - v2);
	if(b > len) return 0;
	// DBGG("b = " , b);
	int tmp = (n % k == 0) ? n / k : n / k + 1;
	double res = 0 , now = 0;
	REP(i , 0 , tmp){
		now = (now - v1 * res) / (v1 + v2) * v1 + v1 * res;
		res += (now - v1 * res) / v1;
		now = now + b;
		res += b / v2;
		// DB4("now = " , now , "res = " , res);
	}
	if(res <= goal) return 1;
	else return 0;
}
int32_t main(){
	// cin.tie(0) , cout.sync_with_stdio(0);
	cin >> n >> len >> v1 >> v2 >> k;
	double l = 0 , r = len / v1;
	// cout << "result = " << judge(4.72) << endl;
	while(r - l > 1e-6){
		double mid = (l + r) / 2.0;
		// DB4("l = " , l , "r = " , r);
		if(judge(mid)) r = mid;
		else l = mid;
	}
	printf("%.11f\n", l);
	return 0;
}