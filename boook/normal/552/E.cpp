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
#define INF 0x3f3f3f3f

string s;
vector<int> query(int l , int r){
	vector<int> cc;
	cc.pb(s[l] - '0');
	for(int i = l + 2 ; i <= r ; i += 2){
		if(s[i] >= '0' && s[i] <= '9'){
			if(s[i - 1] == '+') cc.pb(s[i] - '0');
			else cc.back() *= (s[i] - '0');
		}
	}
	return cc;
}
int solve(int l , int r){
	if(l == 0 && r + 1 == s.size()) {
		vector<int> a = query(0 , s.size() - 1);
		int ans = 0;
		REP(i , 0 , a.size()) ans += a[i];
		return ans;
	}
	else if(l == 0){
		int ans = 0 , cnt = 0;
		vector<int> a = query(0 , r);
		vector<int> b = query(r + 2 , s.size() - 1);
		REP(i , 0 , a.size()) cnt += a[i];
		b[0] *= cnt;
		REP(i , 0 , b.size()) ans += b[i];
		return ans;
	}
	else if(r + 1 == s.size()){
		int ans = 0 , cnt = 0;
		vector<int> a = query(0 , l - 2);
		vector<int> b = query(l , s.size() - 1);
		REP(i , 0 , b.size()) cnt += b[i];
		a.back() *= cnt;
		REP(i , 0 , a.size()) ans += a[i];
		return ans;
	}
	else {
		int ans = 0 , cnt = 0;
		vector<int> a = query(0 , l - 2) ;
		vector<int> b = query(l , r) ;
		vector<int> c = query(r + 2 , s.size() - 1);
		REP(i , 0 , b.size()) cnt += b[i];
		c[0] *= cnt * a.back();
		REP(i , 0 , a.size() - 1) ans += a[i];
		REP(i , 0 , c.size()) ans += c[i];
		return ans;
	}
}
vector<int> l , r;
int32_t main(){
	cin >> s;
	l.pb(0);
	r.pb(s.size() - 1);
	for(int i = 1 ; i < s.size() ; i += 2)
		if(s[i] == '*') l.pb(i + 1) , r.pb(i - 1);
	int ans = 0;
	for(auto i : l) for(auto j : r){
		if(i <= j){
			ans = max(ans , solve(i , j));
		}
	} 
	cout << ans << endl;
    return 0;
}