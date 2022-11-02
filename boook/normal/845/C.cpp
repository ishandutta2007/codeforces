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
#define MAX 
#define INF 0x3f3f3f3f

int n;
vector<PII> v;
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 0 , n){
        int q , w;
        cin >> q >> w;
        v.pb(q , 1);
        v.pb(w + 1 , -1);
    }
    sort(ALL(v));
    int cnt = 0 , ok = 1;
    REP(i , 0 , v.size()){
        cnt += v[i].B;
        if(i + 1 != v.size() && v[i].A != v[i + 1].A){
            if(cnt > 2) ok = 0;
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}