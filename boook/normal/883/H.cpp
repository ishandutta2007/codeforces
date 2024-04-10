/*input
2
aA
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
// #define endl "\n"
///------------------------------------------------------------
#define MAX 100000
#define INF 0x3f3f3f3f

const int N = 26 + 26 + 10;
int toint(char now){
	if('a' <= now && now <= 'z') return now - 'a' + 0;
	if('A' <= now && now <= 'Z') return now - 'A' + 26;
	return now - '0' + 52;
}
char tochar(int now){
	if( 0 <= now && now < 26) return now + 'a' - 0;
	if(26 <= now && now < 52) return now + 'A' - 26;
	return now + '0' - 52;
}
int cnt[MAX];
string s;
vector<int> p;
vector<vector<int>> ans;
int32_t main(){
	IOS;
	cin >> s >> s;
	REP(i , 0 , s.size()) cnt[toint(s[i])] ++;
	REP(k , 1 , s.size() + 1){
		if(s.size() % k == 0){
			int len = s.size() / k , odd = 0;
			REP(i , 0 , N) odd += cnt[i] % 2;
			if(len % 2 == 0 && odd != 0) continue;
			if(len % 2 == 1 && (k >= odd && k % 2 == odd % 2) == 0) continue;
			
			if(len % 2 == 0){
				int pos = 0;
				REP(i , 0 , k){
					vector<int> sol;
					REP(j , 0 , len / 2){
						while(cnt[pos] == 0) pos ++;
						sol.pb(pos) , cnt[pos] -= 2;
					}
					ans.pb(sol);
				}
			}
			else {
				REP(i , 0 , N) if(cnt[i] % 2 == 1) p.pb(i) , cnt[i] --;
				REP(i , 0 , N) while(cnt[i] && p.size() < k) p.pb(i) , p.pb(i) , cnt[i] -= 2;
				int pos = 0;
				REP(i , 0 , k){
					vector<int> sol;
					REP(j , 0 , len / 2){
						while(cnt[pos] == 0) pos ++;
						sol.pb(pos) , cnt[pos] -= 2;
					}
					ans.pb(sol);
				}
			}
			cout << k << endl;
			REP(j , 0 , k){
				vector<int> sol = ans[j];
				REP(i , 0 , len / 2)      cout << tochar(sol[i]);
				if(p.size()) cout << tochar(p[j]) ;
				RREP(i , len / 2 - 1 , 0) cout << tochar(sol[i]);
				cout << " ";
			}
			cout << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
    return 0;
}