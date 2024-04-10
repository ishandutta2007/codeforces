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
#define MAX 50900
#define INF 0x3f3f3f3f

int n , s , val;
vector<PII> ans;
int R(){
    int res = 0;
    REP(i , 0 , 6) res = res * 10 + rand() % 10;
    return res;
}
int32_t main(){
    srand(time(NULL));
    cin >> n >> s >> val;
    int qust = s;
    REP(i , 0 , 1000){
        cout << "? " << qust << endl;
        qust = R() % n + 1;
        int q , w;
        cin >> q >> w;
        ans.pb(mp(q , w));
    }
    int gg = -1 , aaa = INF , ba = -100;
    REP(i , 0 , ans.size()){
        if(ans[i].A < val){
            if(ans[i].A > ba) gg = ans[i].B , ba = ans[i].A;
        }
        else aaa = min(aaa , ans[i].A);
    }
    REP(i , 0 , 997){
        if(gg == -1) break;
        cout << "? " << gg << endl;
        int q , w;
        cin >> q >> w;
        if(q >= val) aaa = min(aaa , q);
        gg = w;
    }
    if(aaa == INF) cout << "! -1" << endl;
    else cout << "! " << aaa << endl;
    return 0;
}