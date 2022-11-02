/*input
6
1 3
2
1 4
2
1 8
2
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int n , ty , now;
int pos = -1 , sum = 0;
vector<int> v;
double ans = 0;
int check(int id){
	double tmp = sum + v[id] + v.back();
	double res = (double)v.back() - tmp / (id + 2);
	// DBGG(id + 2 , tmp);
	if(res > ans) return ans = res , 1;
	return 0;
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1){
		cin >> ty;
		if(ty == 1){
			cin >> now;
			v.pb(now);
			double pp = sum + v.back();
			double res = (double)v.back() - pp / (pos + 2);
			if(res > ans) ans = res;
			while(pos + 1 < (int)(v.size()) - 1 && check(pos + 1)){
				pos ++;
				sum += v[pos];
			}
		}
		if(ty == 2){
			// DBGG("pos = " , pos);
			printf("%.11f\n", ans);
		}
	}
    return 0;
}