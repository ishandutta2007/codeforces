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
// #define DBGG(i,j)     cout << i << " " << j << endl
// #define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f

int n , ans[MAX];
string s , pre;

int32_t main(){
	IOS;
	cin >> n;
	cin >> s;
	int tmp = 0;
	REP(i , 0 , s.size()){
		if(i == 0 && s[i] == '?') s[i] = '1';
		else if(s[i] == '?') s[i] = '0';
		tmp = tmp * 10 + (int)(s[i] - '0');
	} ans[0] = tmp;
	pre = s;
	REP(times , 1 , n){
		cin >> s;
		if(s.size() < pre.size()){
			cout << "NO" << endl;
			return 0;
		}
		else if(s.size() > pre.size()){
			tmp = 0;
			REP(i , 0 , s.size()){
				if(i == 0 && s[i] == '?') s[i] = '1';
				else if(s[i] == '?') s[i] = '0';
				tmp = tmp * 10 + (int)(s[i] - '0');
			} ans[times] = tmp;
		}
		else {
			int cnt = s.size() - 1;
			int good = -1;
			REP(i , 0 , s.size()){
				if(s[i] != '?' && pre[i] > s[i]){
					cnt = i; break;
				}
			}
			REP(i , 0 , s.size()){
				if(s[i] != '?' && pre[i] < s[i]){
					good = i; break;
				}
			}
			// DBGG("pre = " , pre);
			// DB4("good = " , good , "cnt = " , cnt);
			if(good <= cnt && good != -1){
				REP(i , 0 , good) s[i] = pre[i];
				REP(i , good + 1 , s.size()){
					if(i == 0 && s[i] == '?') s[i] = '1';
					else if(s[i] == '?') s[i] = '0';
				}
			}
			else {
				int now = 0;
				REP(i , 0 , cnt + 1){
					if(s[i] == '?') now = now * 10 + (pre[i] - '0');
				}
				now ++;
				// DBGG("now = " , now);
				RREP(i , cnt , 0){
					if(s[i] == '?'){
						s[i] = ('0' + int32_t(now % 10));
						now /= 10;
					}
				}
				// DBGG("now = " , now);
				if(now != 0){
					cout << "NO" << endl;
					return 0;
				}
				REP(i , cnt + 1 , s.size()){
					if(i == 0 && s[i] == '?') s[i] = '1';
					else if(s[i] == '?') s[i] = '0';
				}
			}

			tmp = 0;
			REP(i , 0 , s.size()) tmp = tmp * 10 + (int)(s[i] - '0');

			ans[times] = tmp;
			if(tmp <= ans[times - 1]){
				// DB4("99 = " , ans[times - 1] , tmp , s);
				cout << "NO" << endl;
				return 0;
			}
		}
		pre = s;
	}
	cout << "YES" << endl;
	REP(i , 0 , n) cout << ans[i] << endl;
    return 0;
}