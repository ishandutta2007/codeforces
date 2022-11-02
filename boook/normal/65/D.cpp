/*input
2
H?
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
#define MAX 
#define INF 0x3f3f3f3f

pair<PII , PII> TRS(int a , int b , int c , int d){
	return mp(mp(a , b) , mp(c , d));
}
int n;
string s;
int32_t main(){
	IOS;
	cin >> n >> s;
	set<pair<PII , PII>> sol;
	sol.insert(TRS(0 , 0 , 0 , 0));
	REP(i , 0 , s.size()){
		set<pair<PII , PII>> nxt;
		
		for(auto to : sol){
			
			int a = to.A.A;
			int b = to.A.B;
			int c = to.B.A;
			int d = to.B.B;

			if(s[i] != '?'){
				if(s[i] == 'G') a ++;
				else if(s[i] == 'H') b ++;
				else if(s[i] == 'R') c ++;
				else if(s[i] == 'S') d ++;
				nxt.insert(TRS(a , b , c , d));
			}
			else if(s[i] == '?'){
				int sml = min(a , min(b , min(c , d)));
				if(a == sml) nxt.insert(TRS(a + 1 , b , c , d));
				if(b == sml) nxt.insert(TRS(a , b + 1 , c , d));
				if(c == sml) nxt.insert(TRS(a , b , c + 1 , d));
				if(d == sml) nxt.insert(TRS(a , b , c , d + 1));
			}

		}
		swap(sol , nxt);
	}
	set<string> cc;
	for(auto to : sol){
		int a = to.A.A;
		int b = to.A.B;
		int c = to.B.A;
		int d = to.B.B;
		int sml = min(a , min(b , min(c , d)));
		if(a == sml) cc.insert("Gryffindor");
		if(b == sml) cc.insert("Hufflepuff");
		if(c == sml) cc.insert("Ravenclaw");
		if(d == sml) cc.insert("Slytherin");
	}
	for(auto to : cc) cout << to << endl;
    return 0;
}