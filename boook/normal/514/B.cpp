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

int n , a , b;

int32_t main(){
    cin >> n >> a >> b;
    set<PII> cc;
    int ok = 0;
    REP(i , 0 , n){
        int q , w;
        cin >> q >> w;
        q -= a , w -= b;
        if(q == 0 && w == 0) ok = 1;
        else {
            if(q == 0) w = 1;
            else if(w == 0) q = 1;
            else {
                if(q < 0) q *= -1 , w *= -1;
                int tmp = __gcd(q , w);
                q /= tmp , w /= tmp;
            }
            cc.insert(mp(q , w));
        }
    }
    if(cc.size() == 0) cout << ok << endl;
    else cout << cc.size() << endl;
    return 0;
}