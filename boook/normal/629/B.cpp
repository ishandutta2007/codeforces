#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; ++ i)
#define int long long
#define MAX 200
#define PII pair<int , int>
#define A first
#define B second
#define pb push_back
#define mp make_pair

int n;
vector<PII> a , b;
string s;
int32_t main(){
	cin >> n;
	REP(i , 1 , n + 1){
		int q , w;
		cin >> s >> q >> w;
		if(s == "M") a.pb(mp(q , w));
		else b.pb(mp(q , w));
	}
	int ans = 0;
	REP(i , 1 , 400){
		int tma = 0 , tmb = 0;
		for(auto to : a){
			if(to.A <= i && i <= to.B) tma ++;
		}
		for(auto to : b){
			if(to.A <= i && i <= to.B) tmb ++;
		}
		ans = max(ans , min(tma , tmb) * 2);
	}
	cout << ans << endl;
	return 0;
}