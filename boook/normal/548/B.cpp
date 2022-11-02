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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , m , k;
int x[MAX][MAX] , ans[MAX];
multiset<int> cc;
int solve(int now){
    vector<int> tmp;
    tmp.pb(0);
    REP(i , 1 , m + 1)
        if(x[now][i] == 0) tmp.pb(i);
    tmp.pb(m + 1);
    int mm = 0;
    REP(i , 1 , tmp.size()){
        mm = max(mm , tmp[i] - tmp[i - 1] - 1);
    }
    return mm;
}
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 1 , n + 1) REP(j , 1 , m + 1)
        cin >> x[i][j];

    REP(i , 1 , n + 1) {
        ans[i] = solve(i);
        cc.insert(ans[i]);
    }
    REP(i , 1 , k + 1){
        int q , w;
        cin >> q >> w;
        x[q][w] ^= 1;
        cc.erase(cc.find(ans[q]));
        ans[q] = solve(q);
        cc.insert(ans[q]);
        auto tt = cc.end();tt--;
        cout << (*tt) << endl;
    }
    return 0;
}