#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; ++i)
#define REPNM(i,j,k)   for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define endl "\n"
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

string s;
int check(int now){
	if(now + 1 <= s.size()){
		REPNM(i , now + 1 , s.size())
			if(s[i] != '0') return i - now;
		return int(s.size()) - now;
	}
	return 1;
}
int32_t main(){
	IOS;
	cin >> s;
	int ans = 1 , fr = s[0] - '0' , len = check(0);
	int i = len;
	while(i < s.size()){
		int tmplen = check(i) , tmpfr = s[i] - '0';
		if(len > tmplen || (len == tmplen && fr >= tmpfr)) ans ++ , len += tmplen;
		else ans = 1 , len += tmplen;
		i += tmplen;
	}
	cout << ans << endl;
    return 0;
}