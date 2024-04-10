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
#define int long long
#define MAX 1000900
#define INF 0x3f3f3f3f

int bit[MAX];
int update(int from , int val){
    for(int i = from ; i < MAX ; i += i & -i)
        bit[i] += val;
}
int query(int from){
    int cnt = 0;
    for(int i = from ; i > 0 ; i -= i & -i)
        cnt += bit[i];
    return cnt;
}
int query(int l , int r){
    return query(r) - query(l - 1);
}
int n , l[MAX] , r[MAX];
int x[MAX];
vector<int> uni;
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i] , uni.pb(x[i]);

    sort(ALL(uni));
    uni.resize(unique(ALL(uni)) - uni.begin());
    REP(i , 1 , n + 1) x[i] = lower_bound(ALL(uni) , x[i]) - uni.begin() + 1;

    REP(i , 1 , n + 1){
        l[i] = query(x[i] + 1 , n + 10);
        update(x[i] , 1);
    }
    MEM(bit , 0);
    RREP(i , n , 1){
        r[i] = query(x[i] - 1);
        update(x[i] , 1);
    }
    int ans = 0;
    REP(i , 1 , n + 1) ans += l[i] * r[i];
    cout << ans << endl;
    return 0;
}