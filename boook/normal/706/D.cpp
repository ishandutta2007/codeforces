#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 200000
#define INF 0x3f3f3f3f

int n , ans;
bitset<37> sol;
int b[MAX * 35] , ls[MAX * 35] , rs[MAX * 35] , po = 2;
void update(int now , int floor , int val){
	if(floor < 0) b[now] += val;
	else if(sol[floor] == 0){
		// DBGG("L" , "");
		if(ls[now] == 0) ls[now] = po ++;
		update(ls[now] , floor - 1 , val);
		b[now] = b[ls[now]] + b[rs[now]];
	}
	else if(sol[floor] == 1){
		// DBGG("R" , "");
		if(rs[now] == 0) rs[now] = po ++;
		update(rs[now] , floor - 1 , val);
		b[now] = b[ls[now]] + b[rs[now]];
	}
}
void query(int now , int floor){
	if(floor < 0) return;
	else if(ls[now] == 0) ans = ans * 2 + (sol[floor] == 0) , query(rs[now] , floor - 1);
	else if(rs[now] == 0) ans = ans * 2 + (sol[floor] == 1) , query(ls[now] , floor - 1);
	else if(sol[floor] == 0){
		if(b[rs[now]] > 0) ans = ans * 2 + (sol[floor] == 0) , query(rs[now] , floor - 1);
		else ans = ans * 2 + (sol[floor] == 1) , query(ls[now] , floor - 1);
	}
	else if(sol[floor] == 1){
		if(b[ls[now]] > 0) ans = ans * 2 + (sol[floor] == 1) , query(ls[now] , floor - 1);
		else ans = ans * 2 + (sol[floor] == 0) , query(rs[now] , floor - 1);
	}
}
int32_t main(){
	IOS;
	cin >> n;
	sol = 0;
	update(1 , 34 , 1);
	REP(times , 0 , n){
		string s; int q;
		cin >> s >> q;
		if(s == "+") sol = q , update(1 , 34 , 1);
		else if(s == "-") sol = q , update(1 , 34 , -1);
		else if(s == "?"){
			sol = q , ans = 0;
			query(1 , 34);
			cout << ans << endl;
		}
	}
    return 0;
}