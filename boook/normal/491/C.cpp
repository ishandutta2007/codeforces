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
#define MAX 60
#define INF 0x3f3f3f3f

int lx[MAX] , ly[MAX] , slk[MAX] , good[MAX];
int w[MAX][MAX] , s[MAX] , t[MAX];
int n;
int match(int now){
	s[now] = 1;
	REP(i , 0 , n){
		if(t[i] == 1) continue;
		if(lx[now] + ly[i] == w[now][i]){
			t[i] = 1;
			if(good[i] == -1 || match(good[i])){
				good[i] = now;
				return 1;
			}
		}
		else slk[i] = min(slk[i] , lx[now] + ly[i] - w[now][i]);
	}
	return 0;
}
void update(){
	int tmp = INF;
	REP(i , 0 , n)
		if(t[i] == 0) tmp = min(tmp , slk[i]);
	REP(i , 0 , n){
		if(s[i]) lx[i] -= tmp;
		if(t[i]) ly[i] += tmp;
	}
}
void solve_KM(){
	REP(i , 0 , n){
		good[i] = -1 , lx[i] = ly[i] = 0;
		REP(j , 0 , n) lx[i] = max(lx[i] , w[i][j]);
	}
	REP(i , 0 , n){
		REP(j , 0 , n) slk[j] = INF;
		while(true){
			REP(j , 0 , n) s[j] = t[j] = 0;
			if(match(i)) break;
			else update();
		}
	}
}
string a , b;

int32_t main(){
	cin >> n >> n;
	cin >> a >> b;
	REP(i , 0 , a.size()){
		int Q = (a[i] >= 'a' && a[i] <= 'z') ? a[i] - 'a' : a[i] - 'A' + 26;
		int W = (b[i] >= 'a' && b[i] <= 'z') ? b[i] - 'a' : b[i] - 'A' + 26;
		w[Q][W]++;
	}
	solve_KM();
	int ans = 0;
	vector<char> tmp(MAX);
	REP(i , 0 , n){
		ans += w[good[i]][i];
		tmp[good[i]] = (i < 26) ? i + 'a' : i - 26 + 'A';
	}
	cout << ans << endl;
	REP(i , 0 , n) cout << tmp[i] ; cout << endl;
    return 0;
}