/*input
8 5
1 1 1 1 1 2 8 2
1 1
0 1 3
1 1
0 3 4
1 2
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
#define MAX 100900
#define INF 0x3f3f3f3f
#define N 320

int n , m , x[MAX] , len[MAX] , go[MAX];
void update(int now){
    now = now / N;
    int r = (now + 1) * N - 1;
    RREP(i , r , now * N){
        if(x[i] > n){
            len[i] = 1 , go[i] = i;
        }
        else if(x[i] > r){
            len[i] = 1 , go[i] = x[i];
        }
        else {
            len[i] = len[x[i]] + 1 , go[i] = go[x[i]];
        }
    }
}
PII query(int now){
    PII ans = mp(0 , now);
    while(1){
        // DBGG("now = " , now);
        ans.A += len[now];
        if(go[now] / N != now / N);
        else if(go[go[now]] == go[now]){
            ans.B = go[now];
            break;
        }
        now = go[now];
    }
    return ans;
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i] , x[i] += i;
    REP(i , 0 , n + 1) if(i % N == 0) update(i);
    x[0] = 1;
    // REP(i , 1 , n + 1) cout << len[i] << " " ;cout << endl;
    REP(i , 1 , m + 1){
        int ty , k , v;
        cin >> ty;
        if(ty == 0){
            cin >> k >> v;
            x[k] = v + k;
            update(k);
        }
        else if(ty == 1){
        // REP(j , 1 , n + 1) cout << j << " " ; cout << endl;
        // REP(j , 1 , n + 1) cout << x[j] << " " ; cout << endl;
        // REP(j , 1 , n + 1) cout << len[j] << " " ; cout << endl;
            cin >> k;
            PII tmp = query(k);
            // cout << "the ans = " ;
            cout << tmp.B << " " << tmp.A << endl;
        }
    }
    return 0;
}