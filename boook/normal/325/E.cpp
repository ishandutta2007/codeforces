/*input
32
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
#define MAX 200000
#define INF 0x3f3f3f3f

struct {
	int x[MAX];
	void init(){ REP(i , 0 , MAX) x[i] = i; }
	int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
	void Union(int a , int b){ x[Find(a)] = Find(b); }
	int operator[](int now){ return Find(x[now]); }
} ds;
int n , in[MAX] , nxt[MAX];
int32_t main(){
	ds.init();
	cin >> n;
	if(n % 2 == 1) return cout << -1 << endl , 0;
	REP(i , 0 , n){
		int a = (i + i + 0) % n;
		int b = (i + i + 1) % n;
		     if(in[a] == 0) in[a] = 1 , nxt[i] = a , ds.Union(i , a);
		else if(in[b] == 0) in[b] = 1 , nxt[i] = b , ds.Union(i , b);
		else return cout << "wrong answer = " << i << endl , 0;
	}
	REP(i , 0 , n){
		int now = i , to = (i + n / 2) % n;
		if(ds[now] != ds[to]){
			swap(nxt[now] , nxt[to]);
			ds.Union(now , to);
		}
	}
	int tmp = nxt[0];
	cout << 0 << " ";
	while(1){
		cout << tmp << " ";
		if(tmp == 0) break;
		else tmp = nxt[tmp];
	}
	cout << endl;
    return 0;
}