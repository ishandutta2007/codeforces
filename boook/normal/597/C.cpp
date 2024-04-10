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
#define MAX 200000
#define INF 0x3f3f3f3f

int n , m , x[MAX] , bit[13][MAX];
void update(int ty , int from , int val){
    from += 10;
    for(int i = from ; i < MAX ; i += i & -i)
        bit[ty][i] += val;
}
int query(int ty , int from){
    from += 10;
    int cnt = 0;
    for(int i = from ; i > 0 ; i -= i & -i)
        cnt += bit[ty][i];
    return cnt;
}
int32_t main(){
    cin >> n >> m;
    m += 1;
    REP(i , 1 , n + 1) cin >> x[i];
    update(0 , 0 , 1);
    REP(i , 1 , n + 1){
        RREP(j , m , 1){
            int tmp = query(j - 1 , x[i]);
            update(j , x[i] , tmp);
        }
    }
    int ans = query(m , MAX - 10);
    cout << ans << endl;
    return 0;
}