/*input
4
*/
#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define pb push_back
#define mp make_pair
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define PII pair<vector<int> , vector<int>>
#define DBGG(i , j) cout << i << " " << j << endl
#define A first
#define B second
///----------------------------
#define MAX 300000


queue<PII> qu;
void ADD(vector<int> a , vector<int> b , vector<int> &c){
	if(a.size() > 160) return;
	REP(i , 0 , b.size()){
		a[i] += b[i];
		if(abs(a[i]) > 1) return ;
	}
	qu.push(mp(c , a));
}

int main(){
	int n; cin >> n;
	vector<int> aa[2] = {{-1} , {1}};
	vector<int> bb[6] = {{0 , 1} , {0 , -1} , {1 , 1} , {1 , -1} , {-1 , -1} , {-1 , 1}};
	REP(i , 0 , 2) REP(j , 0 , 6) qu.push(mp(aa[i] , bb[j]));
	int cnt = 0;
	while(qu.size()){
		cnt ++;
		vector<int> a = qu.front().A;
		vector<int> b = qu.front().B , c = b;
		if(a.size() == n && b.size() == n + 1){
			if(a[a.size() - 1] == 1 && b[b.size() - 1] == 1){
				cout << n << endl;
				for(auto to : b) cout << to << " "; cout << endl;
				cout << n - 1 << endl;
				for(auto to : a) cout << to << " "; cout << endl;
				return 0;
			}
		}
		// if(cnt > 100000){
		// 	return 0;
		// }
		qu.pop();
		b.insert(b.begin() , 0);
		ADD(b , a , c);
		REP(i , 0 , b.size()) b[i] *= -1;
		ADD(b , a , c);
	}
	cout << -1 << endl;
	// DBGG("cnt = " , cnt);
	return 0;
}