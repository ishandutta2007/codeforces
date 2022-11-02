/*input
51 785
255 192 147 264 213 111 175 75 213 44 106 112 61 209 181 105 217 21 45 160 15 134 232 49 174 96 157 195 205 52 71 71 74 146 26 151 168 198 244 71 222 230 269 15 103 185 255 151 252 129 62
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
#define MAX 50090
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , k , x[MAX];
int sum[MAX * 37] , ls[MAX * 37] , rs[MAX * 37] , po = 2;
unsigned short cnt[MAX * 37][37];
void update(int now , int floor , int val , int ty){
	if(floor == -1){
		sum[now] ++;
		if(ty){
			REP(i , 0 , 35){
				if(val & (1LL << i)) cnt[now][i] ++;
			}
		}
	}
	else {
		if(val & (1LL << floor)){
			if(rs[now] == 0) sum[po] = ls[po] = rs[po] = 0 , rs[now] = po ++;
			update(rs[now] , floor - 1 , val , ty);
		}
		else {
			if(ls[now] == 0) sum[po] = ls[po] = rs[po] = 0 , ls[now] = po ++;
			update(ls[now] , floor - 1 , val , ty);
		}
		sum[now] = sum[ls[now]] + sum[rs[now]];
		if(ty){
			REP(i , 0 , 35) {
				cnt[now][i] = cnt[ls[now]][i] + cnt[rs[now]][i];
			}
		}
	}
}
int query(int now , int floor , int val , int lim){
	if(floor == -1) return sum[now];
	else{
		if(lim & (1LL << floor)){
			if(val & (1LL << floor)){
				// cout << "L1" << endl;
				return query(ls[now] , floor - 1 , val , lim);
			}
			else {
				// cout << "R1" << endl;
				return query(rs[now] , floor - 1 , val , lim);
			}
		}
		else {
			if(val & (1LL << floor)){
				// cout << "R2" << endl;
				return query(rs[now] , floor - 1 , val , lim) + sum[ls[now]];
			}
			else {
				// cout << "L2" << endl;
				return query(ls[now] , floor - 1 , val , lim) + sum[rs[now]];
			}
		}
	}
}
int DFS(int now , int floor , int val , int lim){
	if(floor == -1) return 1LL * lim * sum[now] % mod;
	else {
		if(lim & (1LL << floor)){
			if(val & (1LL << floor)){
				// cout << "L" << endl;
				return DFS(ls[now] , floor - 1 , val , lim);
			}
			else {
				// cout << "R" << endl;
				return DFS(rs[now] , floor - 1 , val , lim);
			}
		}
		else {
			// cout << "here = " << floor << endl;
			if(val & (1LL << floor)){
				int tmp = 0 , id = ls[now];
				REP(i , 0 , 35){
					int one = cnt[id][i] , zero = sum[id] - one;
					if(val & (1LL << i))
						tmp = (1LL * tmp + 1LL * zero * (1LL << i)) % mod;
					else 
						tmp = (1LL * tmp + 1LL * one * (1LL << i)) % mod;
				}
				return (DFS(rs[now] , floor - 1 , val , lim) + tmp) % mod;
			}
			else {
				int tmp = 0 , id = rs[now];
				REP(i , 0 , 35){
					int one = cnt[id][i] , zero = sum[id] - one;
					if(val & (1LL << i))
						tmp = (1LL * tmp + 1LL * zero * (1LL << i)) % mod;
					else 
						tmp = (1LL * tmp + 1LL * one * (1LL << i)) % mod;
				}
				return (1LL * DFS(ls[now] , floor - 1 , val , lim) + 1LL * tmp) % mod;
			}
		}
	}
}
int solve(int now){
	po = 2 , sum[1] = ls[1] = rs[1] = 0;
	int cnt = 0;
	REP(i , 1 , n + 1){
		cnt = (1LL * cnt + 1LL * DFS(1 , 35 , x[i] , now)) % mod;
		update(1 , 35 , x[i] , 1);
	}
	// DBGG("final cnt = " , cnt);
	return cnt;
}
int judge(int now){
	po = 2 , sum[1] = ls[1] = rs[1] = 0;
	int cnt = 0;
	REP(i , 1 , n + 1){
		cnt += query(1 , 35 , x[i] , now);
		update(1 , 35 , x[i] , 0);
	}
	return cnt;
}
int32_t main(){
	IOS , cin >> n >> k;
	REP(i , 1 , n + 1) cin >> x[i];
	int now = 0 , num = 0;
	RREP(i , 30 , 0){
		int to = now + (1LL << i);
		// DB4("to = " , to , "count = " , judge(to));
		if(judge(to) >= k) now = to;
	}
	num = judge(now);
	// DB4("now = " , now , "num = " , num);
	int jj = 0 , cc = 0;
	REP(i , 1 , n + 1){
		REP(j , i + 1 , n + 1){
			if((x[i] ^ x[j]) >= now) jj += x[i] ^ x[j] , cc ++;
		}
	}
	int ans = solve(now) - (num - k) * now;
	ans = (ans % mod + mod) % mod;
	// DB4("jj = " , jj , "cc = " , cc);
	// DBGG("ans = " , ans);
	cout << ans << endl;
    return 0;
}