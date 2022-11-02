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
#define MAX 200900
#define INF 0x3f3f3f3f

int n , k;
int x[MAX];
vector<int> v;
int judge(int now){
	long double check = k , cc = 1;
	int fr = now , ba = 1;
	RREP(i , v.size() - 1 , 0){
		check -= cc * v[i];
		if(check <= 0) return 1;		
		if(cc > 1e18) return 1;
		cc *= fr; cc /= ba;
		fr ++ , ba ++;
	}
	return 0;
}
int32_t main(){
	cin >> n >> k;
	REP(i , 0 , n) cin >> x[i];
	REP(i , 0 , n){
		if(x[i] >= k){
			cout << 0 << endl;
			return 0;
		}
	}
	REP(i , 0 , n){
		if(x[i] == 0) continue;
		REP(j , i , n) v.pb(x[j]);
		break;
	}
	int l = 0 , r = 1000000000000000009;
	while(r - l > 1){
		int mid = (l + r) / 2;
		if(judge(mid)) r = mid;
		else l = mid;
	}
	cout << r << endl;
    return 0;
}