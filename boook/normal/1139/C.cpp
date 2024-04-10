/*input
3 5
1 2 1
2 3 0
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++i)
#define RREP(i, j, k) for(int i = j; i >= k; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 100009
#define INF 0x3f3f3f3f
#define mod 1000000007LL

struct djs{
	int x[MAX];
	void init(){ REP(i , 0 , MAX) x[i] = i; }
	int Find(int now){ return x[now] == now ? now : x[now] = Find(x[now]); }
	void Union(int a , int b){ x[Find(a)] = Find(b); }
	int operator[](int now){ return Find(x[now]); }
} ds;
int ppow(int a , int k){
	if(k == 0) return 1;
	else if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
	else if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod;
}

int n , k , siz[MAX];
int32_t main(){
	IOS;
	cin >> n >> k , ds.init();
	REP(i , 2 , n + 1){
		int a , b , c;
		cin >> a >> b >> c;
		if(c == 0) ds.Union(a , b);
	}
	REP(i , 1 , n + 1) siz[ds[i]] ++;
	int all = ppow(n , k);
	REP(i , 1 , n + 1) if(siz[i]) all = (all + mod - ppow(siz[i] , k)) % mod;
	cout << all << endl;
    return 0;
}