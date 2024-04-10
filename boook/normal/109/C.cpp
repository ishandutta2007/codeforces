#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define DBGG(i , j) cout << i << " " << j << endl
#define MAX 100900
#define int long long
struct djs{
	int x[MAX];
	void init(){
		REP(i , 0 , MAX) x[i] = i;  
	}
	int Find(int now){
		return now == x[now] ? now : x[now] = Find(x[now]);
	}
	void Union(int a , int b){
		x[Find(a)] = Find(b);
	}
	int operator[](int now){
		return Find(now);
	}
} ds;
int check(int now){
	while(now){
		if(now % 10 != 4 && now % 10 != 7) return 0;	
		now /= 10;
	}
	return 1;
}
int n , siz[MAX];
signed main(){
	cin >> n;
	ds.init();
	REP(i , 2 , n + 1){
		int a , b , c;
		cin >> a >> b >> c;
		if(check(c) == 0) ds.Union(a , b);
	}
	REP(i , 1 , n + 1) siz[ds[i]] ++;
	int ans = 0;
	REP(i , 1 , n + 1){
		int las = n - siz[ds[i]];
//		DBGG(i , las);
		ans += las * (las - 1);
	}
	cout << ans << endl;
	return 0;
}