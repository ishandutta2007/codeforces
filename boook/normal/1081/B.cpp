#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define pb push_back
#define MAX 109000
int n , x[MAX] , ans[MAX] , pos = 1;
vector<int> v[MAX];
int main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1){
        x[i] = n - x[i];
    }
    REP(i , 1 , n + 1){
        v[x[i]].pb(i);
    }
    REP(i , 1 , n + 1){
        if(v[i].size() % i != 0) return cout << "Impossible" << endl , 0;
        else {
            REP(j , 0 , v[i].size()){
                ans[v[i][j]] = pos;
                if((j + 1) % i == 0) pos ++;
            }
        }
    }
    cout << "Possible" << endl;
    REP(i , 1 , n + 1) cout << ans[i] << " " ; cout << endl;
    return 0;
}