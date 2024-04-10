/*input
9 5
aAAaBBccD
1 4 a
5 6 c
2 3 B
4 4 D
2 3 A
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
#define MAX 200900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int big[MAX * 4] , sml[MAX * 4] , siz[MAX * 4] , num[MAX * 4];
int n , m;
string s;
void Pull(int now){
	siz[now] = siz[ls] + siz[rs];
	big[now] = big[ls] | big[rs];
	sml[now] = sml[ls] | sml[rs];
	num[now] = num[ls] | num[rs];
}
void Build(int now , int l , int r){
	if(l == r){
		siz[now] = 1;
		if(s[l] >= 'A' && s[l] <= 'Z') big[now] |= (1 << (s[l] - 'A'));
		if(s[l] >= 'a' && s[l] <= 'z') sml[now] |= (1 << (s[l] - 'a'));
		if(s[l] >= '0' && s[l] <= '9') num[now] |= (1 << (s[l] - '0'));
	}
	else {
		Build(ls , l , mid + 0);
		Build(rs , mid + 1 , r);
		Pull(now);
	}
}
void update(int now , int l , int r , int ql , int qr , char c , int ll , int rr){
	// DB4(l , r , ql , qr);
	int md = ((ll + rr) >> 1);
	if(ql <= l && r <= qr){
		if(c >= 'A' && c <= 'Z' && big[now] & (1 << (c - 'A'))){
			if(ll == rr) siz[now] = big[now] = 0;
			else {
				int mmm = l + siz[ls] - 1;
				update(ls , l , mmm + 0 , ql , qr , c , ll , md + 0);
				update(rs , mmm + 1 , r , ql , qr , c , md + 1 , rr);
				Pull(now);
			}
		}
		if(c >= 'a' && c <= 'z' && sml[now] & (1 << (c - 'a'))){
			if(ll == rr) siz[now] = sml[now] = 0;
			else {
				int mmm = l + siz[ls] - 1;
				update(ls , l , mmm + 0 , ql , qr , c , ll , md + 0);
				update(rs , mmm + 1 , r , ql , qr , c , md + 1 , rr);
				Pull(now);
			}
		}
		if(c >= '0' && c <= '9' && num[now] & (1 << (c - '0'))){
			if(ll == rr) siz[now] = num[now] = 0;
			else {
				int mmm = l + siz[ls] - 1;
				update(ls , l , mmm + 0 , ql , qr , c , ll , md + 0);
				update(rs , mmm + 1 , r , ql , qr , c , md + 1 , rr);
				Pull(now);
			}
		}
	}
	else {
		int mmm = l + siz[ls] - 1;
		if(ql <= mmm + 0) update(ls , l , mmm + 0 , ql , qr , c , ll , md + 0);
		if(mmm + 1 <= qr) update(rs , mmm + 1 , r , ql , qr , c , md + 1 , rr);
		Pull(now);
	}
}
void Print(int now , int l , int r){
		// DBGG(now , siz[now]);
	if(l == r){
		if(siz[now]) cout << s[l];
	}
	else {
		Print(ls , l , mid + 0);
		Print(rs , mid + 1 , r);
	}
}
int32_t main(){
	IOS , cin >> n >> m >> s;
	Build(1 , 0 , n - 1);
	REP(i , 1 , m + 1){
		int l , r; string in;
		cin >> l >> r >> in;
		if(siz[1]){
			// DBGG("siz[1] = " , siz[1]);
			update(1 , 1 , siz[1] , l , r , in[0] , 0 , n - 1);
		}
	}
	Print(1 , 0 , n - 1) , cout << endl;
    return 0;
}