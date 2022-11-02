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
#define MAX 200000
#define INF 0x3f3f3f3f

int n;
int x[MAX];
vector<int> tmp;

int32_t main(){
    cin >> n;
    REP(i , 0 , n) cin >> x[i] , tmp.pb(x[i]);
    sort(ALL(tmp));
    int po = 0 , ans = 0;
    multiset<int> cc;
    REP(i , 0 , n){
        cc.insert(x[i]);
        while(po <= i && cc.find(tmp[po]) != cc.end()){
            cc.erase(cc.find(tmp[po]));
            po++;
            if(cc.size() == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}