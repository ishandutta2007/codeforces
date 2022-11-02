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
#define MAX 4000000
#define INF 0x3f3f3f3f

int o[MAX] , p[MAX] , po;
void pre(){
	o[0] = o[1] = 1;
	REP(i , 2 , MAX){
		if(o[i] == 0) p[po ++] = i;
		REP(j , 0 , po){
			int tmp = p[j] * i;
			if(tmp >= MAX) break;
			o[tmp] = 1;
			if(i % p[j] == 0) break;
		}
	}
}
int ok[MAX] , B[MAX];
void TR(int now){
	int val = now;
	while(val) now = now * 10 + val % 10 , val /= 10;
	if(now < MAX) ok[now] = 1;
}
void TR2(int now){
	REP(i , 0 , 10){
		int to = now * 10 + i;
		int val = now;
		while(val) to = to * 10 + val % 10 , val /= 10;
		if(to < MAX) ok[to] = 1;
	}
}
void PRE(){
	REP(i , 0 , 10000){
		TR(i) , TR2(i);
	}
	// REP(i , 0 , 10000) if(ok[i]) cout << i << endl;
}
int A[MAX];
int n , m;
int32_t main(){

	pre() , PRE();
	REP(i , 1 , MAX) A[i] = A[i - 1] + (1 - o[i]);
	REP(i , 1 , MAX) B[i] = B[i - 1] + ok[i];

	cin >> n >> m;

	int ans = -1;
	REP(i , 0 , MAX){
		if(A[i] * m <= B[i] * n) ans = max(ans , i);
	}
	if(ans == -1) cout << "Palindromic tree is better than splay tree" << endl;
	else cout << ans << endl;
    return 0;
}