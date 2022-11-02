/*input
10111110001111101
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
#define MAX 1000900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int AC , mod , siz[MAX]; 
PII sum[MAX * 4]; 
string s; 
PII Pull(PII a , PII b){
	int val = (a.A * siz[b.B] + b.A) % mod;
	return mp(val , a.B + b.B);
}
void Build(int now , int l , int r){
	if(l == r) sum[now].A = s[l] - '0' , sum[now].B = 1;
	else {
		Build(ls , l , mid + 0);
		Build(rs , mid + 1 , r);
		sum[now] = Pull(sum[ls] , sum[rs]);
	}
}
PII query(int now , int l , int r , int ql , int qr){
	if(ql <= l && r <= qr) return sum[now]; 
	if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
	if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
	return Pull(query(ls , l , mid + 0 , ql , qr) , query(rs , mid + 1 , r , ql , qr)); 
}
void P(int a , int b){
	REP(i , 0 , s.size()){
		if(i == a) cout << "+";
		if(i == a + b) cout << "=";
		cout << s[i];
	}
	cout << endl;
	exit(0);
}
vector<PII> ans;
void check(int a , int b){
	if(b >= 2 && s[a] == '0') return ; 
	int c = (int)s.size() - a - b; 
	if(c >= 2 && s[a + b] == '0') return ; 
	int tma = query(1 , 0 , (int)s.size() - 1 , 0 , a - 1).A; 
	int tmb = query(1 , 0 , (int)s.size() - 1 , a , a + b - 1).A; 
	int tmc = query(1 , 0 , (int)s.size() - 1 , a + b , (int)s.size() - 1).A; 
	if((tma + tmb) % mod == tmc) P(a , b);
}
int32_t main(){
	// srand(time(NULL));
	AC = 10; mod = 10430579;
	cin >> s;
	siz[0] = 1;
	REP(i , 1 , MAX) siz[i] = siz[i - 1] * AC % mod;
	Build(1 , 0 , (int)s.size() - 1);
	int n = s.size() , b;
	REP(a , 1 , n){
		b = n - a - a;
		if(b > 0) check(a , b);
		b = n - a;
		if(b > 0 && b % 2 == 0) check(a , b / 2);
		b = n - a - a - 1; 
		if(b > 0) check(a , b); 
		b = n - a - 1; 
		if(b > 0 && b % 2 == 0) check(a , b / 2); 
	} 
	return 0; 
}