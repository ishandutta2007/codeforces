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
int use[MAX][MAX];
int32_t main(){
    cin >> n >> m >> k;
    vector<int> ans;
    REP(i , 0 , k){
        int q , w;
        cin >> q >> w;
        use[q][w] = 1;
        if(use[q][w] && use[q - 1][w] && use[q][w - 1] && use[q - 1][w - 1]) ans.pb(i);
        if(use[q][w] && use[q + 1][w] && use[q][w - 1] && use[q + 1][w - 1]) ans.pb(i);
        if(use[q][w] && use[q - 1][w] && use[q][w + 1] && use[q - 1][w + 1]) ans.pb(i);
        if(use[q][w] && use[q + 1][w] && use[q][w + 1] && use[q + 1][w + 1]) ans.pb(i);
    }
    if(ans.size() == 0) cout << 0 << endl;
    else cout << ans[0] + 1 << endl;
    return 0;
}