/*input
3
3 4
1 5
2 6
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
#define MAX 500000
#define INF 0x3f3f3f3f

int bit[MAX];
void update(int from , int val){
    for(int i = from + 10 ; i < MAX ; i += i & -i)
        bit[i] += val;
}
int query(int from){
    int cnt = 0;
    for(int i = from + 10 ; i > 0 ; i -= i & -i)
        cnt += bit[i];
    return cnt;
}
int query(int l , int r){
    return query(r) - query(l - 1);
}
int n , a[MAX][2] , sol[MAX] , ans[MAX];
vector<int> uni;
int cmp(int q , int w){
    return a[q][1] < a[w][1];
}
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) REP(j , 0 , 2) cin >> a[i][j];
    REP(i , 1 , n + 1) REP(j , 0 , 2) uni.pb(a[i][j]);

    sort(ALL(uni));
    uni.resize(unique(ALL(uni)) - uni.begin());
    REP(i , 1 , n + 1) REP(j , 0 , 2) 
        a[i][j] = lower_bound(ALL(uni) , a[i][j]) - uni.begin();

    REP(i , 1 , n + 1) sol[i] = i;
    sort(sol + 1 , sol + 1 + n , cmp);
    REP(i , 1 , n + 1){
        int id = sol[i];
        ans[id] = query(a[id][0] , a[id][1]);
        update(a[id][0] , 1);
    }
    REP(i , 1 , n + 1) cout << ans[i] << endl;
    return 0;
}