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
#define MAX 
#define INF 0x3f3f3f3f

int n;
string s;

int32_t main(){
    cin >> n >> n;
    cin >> s;
    RREP(i , s.size() - 1 , 0){
        int ok = 0;
        string ans;
        REP(j , 0 , i) ans += s[j];
        set<char> cc;
        if(ans.size() >= 1) cc.insert(ans[ans.size() - 1]);
        if(ans.size() >= 2) cc.insert(ans[ans.size() - 2]);
        char now = s[i] + 1;
        while(cc.find(now) != cc.end()) now ++;
        if(now - 'a' + 1 > n) continue;
        else ans += now;

        ok = 1;
        REP(j , i + 1 , s.size()){
            set<char> dd;
            if(ans.size() >= 1) dd.insert(ans[ans.size() - 1]);
            if(ans.size() >= 2) dd.insert(ans[ans.size() - 2]);
            char now = 'a';
            while(dd.find(now) != dd.end()) now ++;
            if(now - 'a' + 1 > n) {ok = 0 ; break;}
            else ans += now;
        }

        if(ok){
            cout << ans << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}