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

int n , k;
vector<int> v[MAX];
int32_t main(){
    cin >> n >> k;
    int ans = 0 , tmp , q;
    REP(i , 0 , k){
        cin >> tmp;
        REP(j , 0 , tmp) cin >> q , v[i].pb(q);
    }

    REP(i , 0 , k){
        if(v[i][0] == 1) tmp = i;
    }
    REP(i , 0 , k){
        int siz = v[i].size();
        if(i != tmp){
            ans += siz + siz - 1;
        }
        else {
            int tok = 0;
            REP(j , 1 , v[i].size()){
                if(v[i][j] != v[i][j - 1] + 1) tok = 1;
                if(tok) ans += 2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}