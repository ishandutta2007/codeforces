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
#define MAX 300900
#define INF 0x3f3f3f3f

typedef pair<PII , int> PIII;
int n , m;
PII a[MAX];
PII x[MAX];
PIII rl[MAX];
set<PII> cc;
int ans[MAX];
int32_t main(){

    cin >> n >> m;
    REP(i , 0 , n) cin >> x[i].A >> x[i].B;
    REP(i , 0 , n - 1){
        rl[i].A = mp(x[i + 1].B - x[i].A , x[i + 1].A - x[i].B);
        rl[i].B = i;
    }
    REP(i , 0 , m) cin >> a[i].A , a[i].B = i + 1;
    sort(a , a + m);
    sort(rl , rl + n - 1);
    int po = 0;

    REP(i , 0 , n - 1){
        while(po < m && a[po].A <= rl[i].A.A){
            cc.insert(a[po]) , po ++;
        }
        auto tmp = cc.lower_bound(mp(rl[i].A.B , 0));
        if(tmp == cc.end()){
            cout << "No" << endl;
            return 0;
        }
        else {
            ans[rl[i].B]= (*tmp).B;
            cc.erase(tmp);
        }
    }
    cout << "Yes" << endl;
    REP(i , 0 , n - 1)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}