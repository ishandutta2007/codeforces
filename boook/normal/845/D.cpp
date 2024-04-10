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


stack<int> cc;
int speed;
PII over = mp(4 , 0);
int32_t main(){
    IOS;
    int n , ans = 0;
    cin >> n;
    cc.push(500);
    REP(i , 0 , n){
        int q , w;
        cin >> q;
        if(q == 1){
            cin >> w , speed = w;
        }
        else if(q == 3){
            cin >> w , cc.push(w);
        }
        else if(q == 5){
            cc.push(500);
        }
        else if(q == 2){
            if(over.A == 6) ans += over.B , over.B = 0;
        }
        else if(q == 4){
            over = mp(4 , 0);
        }
        else if(q == 6){
            over.A = 6;
            over.B ++;
        }
        while(cc.size()){
            if(cc.top() < speed) ans ++ , cc.pop();
            else break;
        }
    }
    cout << ans << endl;
    return 0;
}


// 1   x
// 3  x
// 5 

// 2 
// 4 
// 6 

// 1 (
// 