/*input
2 -3 1
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int a , b , c;
int32_t main(){
	cin >> a >> b >> c;
	int val = b * b - 4 * a * c;
	if(a == 0 && b == 0){
		if(c == 0) cout << -1 << endl;
		else cout << 0 << endl;
	}
	else if(a == 0){
		double v1 = -(double)c / (double)b;
		printf("1\n%.11f\n", v1);
	}
	else if(val < 0){
		cout << 0 << endl;
	}
	else if(val == 0){
		double v1 = -b / (double)(2.0 * a);
		printf("1\n%.11f\n", v1);
	}
	else {
		double tmp = sqrt(val);
		double v1 = (-b - tmp) / (double)(2.0 * a);
		double v2 = (-b + tmp) / (double)(2.0 * a);
		if(v1 > v2) swap(v1 , v2);
		printf("2\n%.11f\n%.11f\n", v1 , v2);
	}
    return 0;
}