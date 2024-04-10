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
#define MAX 1000900
#define INF 0x3f3f3f3f

int bit[MAX];
void update(int from , int val){
    // DB4("now upadte" , from , "val = " , val);
    from += 10;
    for(int i = from ; i < MAX ; i += i & -i)
        bit[i] += val;
}
int query(int from){
    from += 10;
    int res = 0;
    for(int i = from ; i > 0 ; i -= i & -i)
        res += bit[i];
    return res;
}
int n , m;
vector<int> v[MAX];
void solve(int a , int b){
    // DB4("solve" , a , b , "");
    if(a < b){
        update(0 , 1) , update(m - 1 - b   + 1 , -1);
        update(m - a , 1) , update(m , -1);
    }
    else if(a > b){
        int l = m - a;
        int r = m - b - 1;
        update(l , 1) , update(r + 1 , -1);
    }
}
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , n + 1){
        int tmp , x; cin >> tmp;
        REP(j , 1 , tmp + 1) cin >> x , v[i].pb(x - 1);
    }
    REP(i , 2 , n + 1){
        int sml = min(v[i - 1].size() , v[i].size()) , id = -1;

        REP(j , 0 , sml){
            if(v[i - 1][j] != v[i][j]){
                id = j; break;
            }
        }

        if(id == -1){
            if(v[i - 1].size() <= v[i].size()) update(0 , 1) , update(m , -1);
        }
        else {
            int a = v[i - 1][id] , b = v[i][id];
            solve(a , b);            
        }
    }
    REP(i , 0 , m){
        if(query(i) == n - 1){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}