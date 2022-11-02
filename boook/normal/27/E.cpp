#include <bits/stdc++.h>
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define RREP(i , j , k) for(int i = j ; i >= k ; i --)
#define PII pair<int , int>
#define mp make_pair
#define pb push_back
#define DBGG(i , j) cout << i << " " << j << endl
#define ALL(i) i.begin() , i.end()
#define A first
#define B second
///--------------------------------------
#define int long long
#define MAX
#define INF 0x3f3f3f3f
using namespace std;

int p[] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 27 , 29 , 31 , 37 , 41 , 43 , 47 , 53 , 59 , 61 , 67};
int ans = 1000000000000000000LL;
int ppow(int a , int k){
	int val = 1;
	REP(i , 0 , k){
		if(ans / val / a == 0) return -1;
		else val *= a;
	}
	return val;
}
void DFS(vector<int> v){
	REP(i , 2 , INF){
		if(i * i > v.back()) break;
		if(v.back() % i == 0){
			int tmp = v.back();
			v.back() = i;
			v.pb(tmp / i);
			DFS(v);
			v.pop_back();
			v.back() = tmp;
		}
	}
	
	sort(ALL(v) , greater<int>());
	int val = 1;
	REP(i , 0 , v.size()){
		int tmp = ppow(p[i] , v[i] - 1);
		if(ans / tmp / val == 0 || tmp == -1) return ;
		else val *= tmp;
	}
//	if(val < ans){
//	for(auto to : v) cout << to << " "; cout << endl;
//	}
	ans = min(ans , val);
}
signed main(){
	int n;
	cin >> n;
	vector<int> v(1 , n);
	DFS(v);
	cout << ans << endl;
	return 0;
}