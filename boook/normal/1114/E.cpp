/*input

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)  for(int i = j ; i < k ; ++i)
#define RREP(i,j,k) for(int i = j ; i >=k ; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i,j) memset(i , j , sizeof i)
#define ALL(i)   i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define int long long
#define MAX 1000090
#define INF 0x3f3f3f3f

int n , u[MAX];
int Rand(){
    int res = 0;
    REP(i , 0 , 28) res = res * 2 + rand() % 2;
    return res;
}
int32_t main(){
    IOS;

    srand(time(0));

    cin >> n;
    int big = 0 , tmp;
    RREP(i , 29 , 0){
        int to = big + (1 << i);
        if(to > 1000000000) continue;
        cout << "> " << to << endl , fflush(stdout);
        cin >> tmp;
        if(tmp == 1) big = to;
    } big ++;

    vector<int> res;
    res.pb(big);
    REP(i , 0 , 30){
        int idx = Rand() % n + 1;
        while(u[idx] && n > 40) idx = Rand() % n + 1;
        u[idx] = 1;
        cout << "? " << idx << endl , fflush(stdout);
        cin >> tmp;
        res.pb(tmp);
    }
    int val = big - res[0];
    for(auto v1 : res) for(auto v2 : res) val = __gcd(val , abs(v1 - v2));
    cout << "! " << big - (n - 1) * val << " " << val << endl;
    fflush(stdout);
    return 0;
}