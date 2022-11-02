/*input

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
///-----------------------------------------------------------
#define int int_fast64_t
#define MAX 200900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int n , m , sml[MAX * 4] , tag[MAX * 4];
void push(int now , int l , int r){
	if(tag[now] && l != r){
		tag[ls] += tag[now];
		tag[rs] += tag[now];
		sml[ls] += tag[now];
		sml[rs] += tag[now];
		tag[now] = 0;
	}
}
void update(int now , int l , int r , int ql , int qr , int val){
	push(now , l , r);
	if(ql <= l && r <= qr){
		sml[now] += val;
		tag[now] += val;
	}
	else {
		if(ql <= mid + 0) update(ls , l , mid + 0 , ql , qr , val);
		if(mid + 1 <= qr) update(rs , mid + 1 , r , ql , qr , val);
		sml[now] = min(sml[ls] , sml[rs]);
	}
}
int query(int now , int l , int r , int ql , int qr){
	push(now , l , r);
	if(ql <= l && r <= qr) return sml[now];
	if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
	if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
	return min(query(ls , l , mid + 0 , ql , qr) , query(rs , mid + 1 , r , ql , qr));
}
int x[MAX] , tmp[10] , pos = 0;
string s;
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) update(1 , 1 , n , i , i , x[i]);
	cin >> m;
	getline(cin , s);
	REP(i , 1 , m + 1){
		getline(cin , s);
		stringstream ss(s);
		pos = 0;
		while(ss >> tmp[pos]) pos ++;
		tmp[0] ++ , tmp[1] ++;
		if(pos == 2){
			if(tmp[0] <= tmp[1]) cout << query(1 , 1 , n , tmp[0] , tmp[1]) << endl;
			else cout << min(query(1 , 1 , n , tmp[0] , n) , query(1 , 1 , n , 1 , tmp[1])) << endl;
		}
		if(pos == 3){
			if(tmp[0] <= tmp[1])
				update(1 , 1 , n , tmp[0] , tmp[1] , tmp[2]);
			else {
				update(1 , 1 , n , tmp[0] , n , tmp[2]);
				update(1 , 1 , n , 1 , tmp[1] , tmp[2]);
			}
		}
	}
    return 0;
}