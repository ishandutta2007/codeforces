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
#define MAX 100
#define INF 0x3f3f3f3f

int no[MAX] , p[MAX] , po;
void pre(){
	REP(i , 2 , MAX){
		if(no[i] == 0) p[po ++] = i , cout << i << " , ";
		REP(j , 0 , po){
			int tmp = p[j] * i;
			if(tmp >= MAX) break;
			no[tmp] = 1;
			if(i % p[j] == 0) break;
		}
	}
}
int h[15] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47};
int ans[20];
string s;
int32_t main(){
	// pre();
	REP(i , 0 , 15){
		cout << h[i] << endl;
		cin >> s;
		if(s == "no") ans[i] = 0;
		else ans[i] = 1;
	}
	int cnt = 0 , val = 0;
	REP(i , 0 , 15){
		if(ans[i]) cnt ++ , val = h[i]; 
	}
	if(cnt >= 2) cout << "composite" << endl;
	else if(cnt == 0) cout << "prime" << endl;
	else if(cnt == 1){
		if(val >= 11) cout << "prime" << endl;
		else {
			int ok = 1;
			if(val == 2){
				cout << 4 << endl;
				cin >> s;
				if(s == "yes") ok = 0;
				cout << 8 << endl;
				cin >> s;
				if(s == "yes") ok = 0;
				cout << 16 << endl;
				cin >> s;
				if(s == "yes") ok = 0;
				cout << 32 << endl;
				cin >> s;
				if(s == "yes") ok = 0;
				cout << 64 << endl;
				cin >> s;
				if(s == "yes") ok = 0;
			}
			if(val == 3){
				cout << 9 << endl;
				cin >> s;
				if(s == "yes") ok = 0;
				cout << 27 << endl;
				cin >> s;
				if(s == "yes") ok = 0;
				cout << 81 << endl;
				cin >> s;
				if(s == "yes") ok = 0;
			}
			if(val == 5){
				cout << 25 << endl;
				cin >> s;
				if(s == "yes") ok = 0;
			}
			if(val == 7){
				cout << 49 << endl;
				cin >> s;
				if(s == "yes") ok = 0;
			}
			if(ok == 0) cout << "composite" << endl;
			else cout << "prime" << endl;
		}
	}
    return 0;
}