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

int n , m;
PII x[MAX];

int32_t main(){
    cin >> n >> m;
    REP(i , 0 , n) cin >> x[i].A >> x[i].B;
    sort(x , x + n);
    int po = 0 , sum = 0 , ans = 0;
    multiset<int> cc;
    REP(i , 0 , n){
        cc.insert(x[i].A) , sum += x[i].B;
        auto tmp = cc.begin();
        while(x[i].A - *tmp >= m){
            cc.erase(cc.find(x[po].A)) , sum -= x[po++].B;
            tmp = cc.begin();
        }
        tmp = cc.end() , tmp --;
        while(*tmp - x[i].A >= m){
            cc.erase(cc.find(x[po].A)) , sum -= x[po++].B;
            tmp = cc.end() , tmp --;
        }
        ans = max(ans , sum);
    }
    cout << ans << endl;
    return 0;
}