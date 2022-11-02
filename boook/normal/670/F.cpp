/*input
11007000
1000
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
#define MAX 1000900
#define INF 0x3f3f3f3f

string b , ans;
int dig[MAX] , have[20] , need[20] , pos = 0;
int check(int put){
	if(have[put] == 0) return 0;
	have[put] --;
	return 1;
}
void update(string now){
	if(now[0] == '0' && now.size() > 1) return ;
	if(now.size() < ans.size()) ans = now;
	else ans = min(ans , now);
}
void solve(string a){
	REP(i , 0 , 10) have[i] = need[i] = 0;
	REP(i , 0 , a.size()) have[a[i] - '0'] ++;
	REP(i , 0 , b.size()) need[b[i] - '0'] ++;
	REP(i , 0 , 10) have[i] -= need[i] , need[i] = have[i];

	string now , sec = b;
	int can = a.size() > 1;
	REP(i , 0 , a.size()){
		REP(j , can , 10) if(check(j)){
			now += '0' + j;
			break;
		}
		can = 0;
	}
	REP(i , 0 , 10) have[i] = need[i];
	REP(i , 0 , a.size()){
		REP(j , 0 , 10) if(check(j)){
			sec += '0' + j;
			break;
		}
	}
	update(sec);
	int lpo = 1 , rpo = 1;
	while(lpo < now.size() && now[lpo] < b[0]) lpo ++;
	while(rpo < now.size() && now[rpo] <= b[0]) rpo ++;

	string s1 = now , s2 = now , s3 = now;
	s1.insert(0 , b) , update(s1) , s1 = now;
	if(now.size() > 0) s1.insert(1 , b) , update(s1);
	if(now.size() > 1){
		s2.insert(lpo , b) , update(s2);
		s3.insert(rpo , b) , update(s3);
	}
}
string a;
void solveinit(){
	REP(i , 0 , 10) dig[i] = 1;
	REP(i , 10 , MAX) dig[i] = dig[i / 10] + 1;
	int n = a.size();
	RREP(i , 10 , 0){
		if(i == dig[n - i]){
			multiset<int> cc;
			i = n - i;
			while(i) cc.insert(i % 10) , i /= 10;
			string na;
			REP(j , 0 , a.size()){
				auto tmp = cc.find(a[j] - '0');
				if(tmp == cc.end()) na += a[j];
				else cc.erase(tmp);
			}
			if(cc.size() == 0) solve(na);
		}
	}
}
int32_t main(){
	IOS;
	cin >> a >> b;
	ans.resize(a.size() , '9');
	solveinit();
	cout << ans << endl;
    return 0;
}