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
#define INF 100000000000000LL

int n , m , k;
int x[MAX][4] , fr[MAX] , ba[MAX] , val[MAX];
vector<int> a , b;
int cmp1(int q , int w){
    return x[q][0] < x[w][0];
}
int cmp2(int q , int w){
    return x[q][0] > x[w][0];
}
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 0 , m) REP(j , 0 , 4) cin >> x[i][j];
    REP(i , 0 , m){
        if(x[i][2] == 0) a.pb(i);
        else if(x[i][1] == 0) b.pb(i);
        else assert(0);
    }
    sort(ALL(a) , cmp1);
    sort(ALL(b) , cmp2);

    REP(i , 1 , n + 1) val[i] = INF;

    int po = 0 , cnt = 0 , sum = 0;
    fr[0] = INF;
    REP(i , 1 , MAX){
        while(po < a.size() && x[a[po]][0] <= i){
            int id = a[po];
            if(val[x[id][1]] == INF) cnt ++;
            else sum -= val[x[id][1]];
            val[x[id][1]] = min(val[x[id][1]] , x[id][3]);
            sum += val[x[id][1]];
            po ++;
        }
        fr[i] = fr[i - 1];
        if(cnt == n) fr[i] = min(fr[i] , sum);
    }

    REP(i , 1 , n + 1) val[i] = INF;
    int N = 1000000;
    po = 0 , cnt = 0 , sum = 0;
    ba[N + 1] = INF;
    RREP(i , N , 1){
        while(po < b.size() && x[b[po]][0] >= i){
            int id = b[po];
            if(val[x[id][2]] == INF) cnt ++;
            else sum -= val[x[id][2]];
            val[x[id][2]] = min(val[x[id][2]] , x[id][3]);
            sum += val[x[id][2]];
            po ++;
        }
        ba[i] = ba[i + 1];
        if(cnt == n) ba[i] = min(ba[i] , sum);
    }

    int ans = INF;
    REP(i , 1 , N + 1){
        if(i + k + 1 <= N) ans = min(ans , fr[i] + ba[i + k + 1]);
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}