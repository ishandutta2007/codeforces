/*input
10
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
#define MAX 
#define INF 0x3f3f3f3f

string s;
vector<int> v[3];
string update(string now){
    reverse(ALL(now));
    while(now.size() > 1 && now.back() == '0')
        now.pop_back();
    reverse(ALL(now));
    return now;
}
int32_t main(){
    cin >> s;
    int cnt = 0;
    REP(i , 0 , s.size()){
        cnt += s[i] - '0';
        v[(s[i] - '0') % 3].pb(i);
    }
    if(cnt % 3 == 0) cout << s << endl;
    else {
        string ans = "";
        if(cnt % 3 == 2) swap(v[1] , v[2]);
        if(v[1].size() >= 1){
            int a = v[1].back();
            string tmp = s;
            tmp.erase(a , 1);
            tmp = update(tmp);
            if(tmp.size() > ans.size()) ans = tmp;
        }
        if(v[2].size() >= 2){
            int a = v[2].back(); v[2].pop_back();
            int b = v[2].back();
            string tmp = s;
            tmp.erase(a , 1);
            tmp.erase(b , 1);
            tmp = update(tmp);
            if(tmp.size() > ans.size()) ans = tmp;
        }
        if(ans.size() == 0) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}