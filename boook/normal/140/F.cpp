/*input
1 0 1 1
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
#define PII pair<double , double>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 200900
#define INF 0x3f3f3f3f

PII operator + (PII x , PII y){ return mp(x.A + y.A , x.B + y.B); }
int equal(PII x , PII y){
    return abs(x.A - y.A) < 1e-9 && abs(x.B - y.B) < 1e-9;
}
int n , k;
PII x[MAX];
vector<PII> ans;
void check(PII now){
    // DB4("now check = " , now.A , now.B , "");
    int l = 0 , r = n - 1;
    int cnt = 0;
    while(l <= r){
        if(equal(x[l] + x[r] , now)) l ++ , r --;
        else if(l == r) cnt ++ , l ++;
        else if(x[l] + x[r] > now){
            r -- , cnt ++;
        }
        else if(x[l] + x[r] < now){
            l ++ , cnt ++;
        }
    }
    if(cnt <= k) ans.pb(now.A / 2 , now.B / 2);
}
int32_t main(){
    scanf("%d%d" , &n , &k);
    REP(i , 0 , n) scanf("%lf%lf" , &x[i].A , &x[i].B);
    sort(x , x + n);
    if(k >= n) return cout << -1 << endl , 0;
    for(int i = 0 ; i < n && i <= k ; i ++){
        for(int j = n - 1 ; j >= 0 && j + k + 1 >= n && i <= j ; j --){
            check(x[i] + x[j]);
        }
    }
    sort(ALL(ans));
    int cnt = ans.size() > 0;
    REP(i , 1 , ans.size()) cnt += equal(ans[i - 1] , ans[i]) == 0;
    cout << cnt << endl;
    REP(i , 0 , ans.size()){
        if(i == 0 || equal(ans[i - 1] , ans[i]) == 0)
            printf("%.11f %.11f\n", ans[i].A , ans[i].B);
    }
    return 0;
}