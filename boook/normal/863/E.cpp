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
#define MAX 200900 * 6
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int n , x[MAX][2];
vector<int> uni;
int N , b[MAX * 4] , siz[MAX * 4];
void update(int now , int l , int r , int ql , int qr , int val){
    if(ql <= l && r <= qr) b[now] += val;
    else {
        if(ql <= mid) update(ls , l , mid , ql , qr , val);
        if(mid + 1 <= qr) update(rs , mid + 1 , r , ql , qr , val);
        int tma = 0 , tmb = 0;
        tma = (b[ls]) ? (mid - l + 1) : siz[ls];
        tmb = (b[rs]) ? (r - (mid + 1) + 1) : siz[rs];
        siz[now] = tma + tmb;
    }
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1){
        cin >> x[i][0] >> x[i][1];
        uni.pb(x[i][0]); uni.pb(x[i][1]);
        uni.pb(x[i][0] - 1); uni.pb(x[i][1] - 1);
        uni.pb(x[i][0] + 1); uni.pb(x[i][1] + 1);
    }
    sort(ALL(uni));
    uni.resize(unique(ALL(uni)) - uni.begin());
    REP(i , 1 , n + 1) REP(j , 0 , 2){
        x[i][j] = lower_bound(ALL(uni) , x[i][j]) - uni.begin() + 1;
    }

    N = uni.size() + 10;

    REP(i , 1 , n + 1){
        update(1 , 0 , N , x[i][0] , x[i][1] , 1);
    }

    int all = siz[1];
    REP(i , 1 , n + 1){
        update(1 , 0 , N , x[i][0] , x[i][1] , -1);
        if(siz[1] == all) return cout << i << endl , 0;
        update(1 , 0 , N , x[i][0] , x[i][1] , 1);
    }
    cout << -1 << endl;
    return 0;
}