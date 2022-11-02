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
#define MAX 10090000LL
#define INF 0x3f3f3f3f

int n , m;
vector<PII> ans;
int C3(int now){
    int a = now - 1 , b = now , c = now + 1;
    if(a % 3 == 0) a /= 3;
    if(b % 3 == 0) b /= 3;
    if(c % 3 == 0) c /= 3;
    if(a % 2 == 0) a /= 2;
    else b /= 2;
    return a * b * c;
}
int32_t main(){
    cin >> n;
    REP(i , 1 , min(MAX , n + 1LL)){
        int tmp = C3(i) + n;
        int xx = i * (i + 1) / 2;
        if(tmp % xx == 0){
            int res = tmp / xx;
            if(res >= i) ans.pb(mp(i , res));
            if(res <= i) break;
        }
    }
    int sum = (int)(ans.size()) * 2;
    int ss = ans.size() - 1;
    if(ans[ss].A == ans[ss].B) ss-- , sum --;
    cout << sum << endl;
    REP(i , 0 , ans.size()) cout << ans[i].A << " " << ans[i].B << endl;
    RREP(i , ss , 0) cout << ans[i].B << " " << ans[i].A << endl;
    return 0;
}