#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
//------------------------------------------
#define int long long
#define INF 0x3f3f3f3f
#define MAX 100900

string s;
set<char> cc;
map<char , int> sum;
int32_t main(){
	cin.tie(0) , cout.sync_with_stdio(0);
	cin >> s >> s;
	REP(i , 0 , s.size()){
		cc.insert(s[i]);
	}
	int po = 0 , ans = INF;
	REP(i , 0 , s.size()){
		sum[s[i]] ++;
		while(sum.size() == cc.size()){
			ans = min(ans , i - po + 1);
			if(sum[s[po]] == 1) sum.erase(s[po]);
			else sum[s[po]] --;
			po ++;
		}
	}
	cout << ans << endl;
	return 0;
}