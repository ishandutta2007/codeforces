/*input
3
55 80 10 -1 -1
15 -1 79 60 -1
42 -1 13 -1 -1
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
#define MAX 
#define INF 0x3f3f3f3f

int n , a[6] , b[6] , cnt[6];
int V(int ac , int peo){
	if(ac * 32 <= peo) return 3000;
	if(ac * 16 <= peo) return 2500;
	if(ac *  8 <= peo) return 2000;
	if(ac *  4 <= peo) return 1500;
	if(ac *  2 <= peo) return 1000;
	if(ac *  1 <= peo) return  500;
}
int judge(int now){
	int v1 = 0 , v2 = 0 , val;
	REP(i , 1 , 5 + 1){
		if(a[i] == -1 && b[i] == -1) continue;
		else if(a[i] == -1){
			val = V(cnt[i] , now + n);
		}
		else if(b[i] == -1){
			val = V(cnt[i] , now + n);
		}
		else {
			if(a[i] >= b[i]){
				val = V(cnt[i] + now , now + n);
			}
			if(a[i] < b[i]){
				val = V(cnt[i] , now + n);
			}
		}
		if(a[i] != -1) v1 += val - val / 250 * a[i];
		if(b[i] != -1) v2 += val - val / 250 * b[i];
		// cout << "val = " << val << " " ; DB4("v1 = " , (int)v1 , "v2 = " , (int)v2);
	}
	return v1 > v2;
}
int32_t main(){
	IOS , cin >> n;
	REP(i , 1 , 5 + 1){
		cin >> a[i];
		if(a[i] != -1) cnt[i] ++;
	}
	REP(i , 1 , 5 + 1){
		cin >> b[i];
		if(b[i] != -1) cnt[i] ++;
	}
	REP(i , 3 , n + 1){
		int in;
		REP(j , 1 , 5 + 1){
			cin >> in;
			if(in != -1) cnt[j] ++;
		}
	}
	int now = INF;
	REP(i , 0 , 1000000) if(judge(i)) now = min(now , i);
	if(now == INF) cout << -1 << endl;
	else cout << now << endl;
    return 0;
}