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

int n , m;
PII ans[MAX];
vector<PII> v , b;

int32_t main(){
    cin >> n >> m;
    REP(i , 0 , m){
        int q , w;
        cin >> q >> w;
        if(w == 1) v.pb(mp(q , i));
        if(w == 0) b.pb(mp(q , i));
    }
    sort(ALL(v)) , sort(ALL(b));
    REP(i , 0 , v.size()){
        ans[v[i].B] = mp(i + 1 , i + 2);
    }
    int now = 2 , fr = 0;
    REP(i , 0 , b.size()){
        int val = b[i].A , id = b[i].B;
        while(1){
            if(now == n || v[now - 1].A > val){
                cout << -1 << endl;
                return 0;
            }
            else {

                ans[id] = mp(fr + 1 , now + 1);
                fr ++;
                if(now - fr < 2) now ++ , fr = 0;
                break;
            }
        }
    }
    REP(id , 0 , m) cout << ans[id].A << " " << ans[id].B << endl;
    return 0;
}