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
#define MAX 
#define INF 0x3f3f3f3f

int n;
int P(int now){
    REP(i , 2 , now + 1){
        if(i * i > now) return 1;
        else if(now % i == 0) return 0;
    }
    return 1;
}
int ppow(int a , int b){
    int ans = 1 % n , res = a;
    while(b){
        if(b & 1) ans = ans * res % n;
        res = res * res % n;
        b >>= 1;
    }
    return ans;
}
int32_t main(){
    cin >> n;
    if(n == 4){
        cout << "YES" << endl;
        cout << "1" << endl;
        cout << "3" << endl;
        cout << "2" << endl;
        cout << "4" << endl;
    }
    else if(n == 1) {
        cout << "YES" << endl;
        cout << 1 << endl;
    }
    else {
        if(P(n) == 0) cout << "NO" << endl;
        else {
            vector<int> sol;
            sol.pb(1);
            REP(i , 2 , n){
                sol.pb(ppow(i - 1 , n - 2) * i % n);
            }
            sol.pb(n);
            cout << "YES" << endl;
            for(auto to : sol) cout << to << endl;
        }
    }
    return 0;
}