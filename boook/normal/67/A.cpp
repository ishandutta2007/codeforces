#include <bits/stdc++.h> 
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define pb push_back
#define ALL(i) i.begin() , i.end()
///---------------------
#define int long long
#define MAX 100000
#define INF 0x3f3f3f3f
#define mod 1000000007LL
using namespace std;

string s;
int ans[MAX];
signed main(){
	cin >> s >> s;
	ans[0] = 0;
	REP(i , 0 , s.size() + 1) ans[i] = 1;
	REP(times , 0 , s.size() + 10){
		REP(i , 0 , s.size()){
			if(s[i] == '='){
				if(ans[i] < ans[i + 1]) ans[i] = ans[i + 1];
				if(ans[i + 1] < ans[i]) ans[i + 1] = ans[i];
			}
			if(s[i] == 'L'){
				if(ans[i] < ans[i + 1] + 1) ans[i] = ans[i + 1] + 1;
			}
			if(s[i] == 'R'){
				if(ans[i + 1] < ans[i] + 1) ans[i + 1] = ans[i] + 1;
			}
		}
	}
	
	REP(i , 0 , s.size() + 1) cout << ans[i] << " "; cout << endl;
	return 0;
}