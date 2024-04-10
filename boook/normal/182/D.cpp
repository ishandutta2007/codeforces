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
#define MAX 100900
#define INF 0x3f3f3f3f

int cnt[MAX];
int z[MAX];
void solve(string s){
    int l = 0 , r = 0;
    REP(i , 1 , s.size()){
        z[i] = max(min(z[i - l] , r - i + 1) , 0);
        while(i + z[i] < s.size() && s[z[i]] == s[i + z[i]]){
            l = i , r = i + z[i];
            z[i] ++;
        }
    }
    int len = s.size();
    cnt[s.size()] ++;
    REP(i , 1 , s.size()){
        if(i + i > s.size()) break;
        if(len % i == 0 && z[i] == len - i){
            cnt[i] ++;
        }
    }
}
string a , b;
int32_t main(){
    cin >> a >> b;
    solve(a) , solve(b);
    int ans = 0;
    int sml = min(a.size() , b.size());
    REP(i , 1 , sml + 1){
        if(a[i - 1] != b[i - 1]) break;
        if(cnt[i] == 2) ans ++;
    }
    cout << ans << endl;
    return 0;
}