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
#define int long long
#define MAX 1000900
#define INF 0x3f3f3f3f

string s;
int a , b , pre[MAX];
set<int> cc;

int32_t main(){
	IOS;
	cin >> s >> a >> b; 
	pre[0] = 1;
	REP(i , 1 , MAX){
		pre[i] = pre[i - 1] * 10 % b;
	}
	int now = 0;
	REP(i , 0 , s.size()){
		now = (now * 10 + (s[i] - '0')) % a;
		if(now == 0) cc.insert(i + 1);
	}
	int cnt = 0 , po = 0;
	RREP(i , s.size() - 1 , 0){
		cnt = (cnt + pre[po] * (s[i] - '0')) % b;
		if(cnt == 0 && s[i] != '0'){
			int tmp = ((int)(s.size())) - (po + 1);
			// DBGG("tmp = " , tmp);
			if(cc.find(tmp) != cc.end()){
				cout << "YES" << endl;
				REP(i , 0 , tmp) cout << s[i] ; cout << endl;
				REP(i , tmp , s.size()) cout << s[i] ;
				cout << endl;
				return 0;
			}
		}
		po ++;
	}
	cout << "NO" << endl;
    return 0;
}