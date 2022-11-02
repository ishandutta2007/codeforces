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
#define MAX 2100000
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)

int n , m , x[MAX] , res = 0 , b[MAX] , ans;
void query(int now , int floor){
    if(floor == -1) return;
    int need = (1 << floor);
    if((1 << floor) & res){
        if(b[rs] == need) ans = ans * 2 + 1 , query(ls , floor - 1);
        else ans = ans * 2 , query(rs , floor - 1);
    }
    else {
        if(b[ls] == need) ans = ans * 2 + 1 , query(rs , floor - 1);
        else ans = ans * 2 , query(ls , floor - 1);
    }
}
void update(int now , int floor , int val){
    if(floor == -1) b[now] = 1;
    else {
        if((1 << floor) & val) update(rs , floor - 1 , val);
        else update(ls , floor - 1 , val);
        b[now] = b[ls] + b[rs];
    }
}
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i] , update(1 , 19 , x[i]);

    REP(i , 1 , m + 1){
        int q;
        cin >> q;
        ans = 0;
        res ^= q;
        query(1 , 19);
        cout << ans << endl;
    }
    return 0;
}