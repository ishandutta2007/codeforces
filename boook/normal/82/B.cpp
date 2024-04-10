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
#define MAX 40000
#define INF 0x3f3f3f3f

int n , po;
set<int> cc[MAX] , ans[MAX];
int32_t main(){
    cin >> n;
    if(n == 2){
        int a , b , tmp;
        vector<int> fk;
        cin >> tmp;
        while(tmp --) cin >> a , fk.pb(a);
        cout << "1 " << fk[0] << endl;
        cout << (int)(fk.size()) - 1 << " ";
        REP(i , 1 , fk.size()) cout << fk[i] << " ";
        cout << endl;
        return 0;
    }
    int all = n * (n - 1) / 2;
    int tt , q;
    REP(i , 0 , all){
        cin >> tt;
        while(tt--) cin >> q , cc[i].insert(q);
    }
    vector<int> tmp;
    REP(i , 0 , all){
        if(cc[i].find(q) != cc[i].end()) tmp.pb(i);
    }
    int a = tmp[0] , b = tmp[1];
    for(auto now : cc[a]){
        if(cc[b].find(now) != cc[b].end()) ans[0].insert(now);
    }
    REP(i , 0 , tmp.size()){
        for(auto now : cc[tmp[i]]){
            if(ans[0].find(now) == ans[0].end()) ans[i + 1].insert(now);
        }
    }
    REP(i , 0 , n){
        cout << ans[i].size() ;
        for(auto now : ans[i]) cout << " " << now ;
        cout << endl;
    }
    return 0;
}