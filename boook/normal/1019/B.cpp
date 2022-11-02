/*input

*/
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
// #define endl "\n"
///------------------------------------------------------------
#define MAX 100090
#define INF 0x3f3f3f3f

int n , ans[MAX];
int query(int idx){
    idx ++;
    if(ans[idx] == INF){
        cout << "? " << idx << endl;
        fflush(stdout);
        cin >> ans[idx];
    }
    return ans[idx];
}
int two(int idx){
    return query(idx) - query((idx + (n / 2)) % n);
}
int32_t main(){
    IOS;
    MEM(ans , INF);
    cin >> n;
    if(n % 4 != 0) return cout << "! -1" << endl , 0;
    int l = 0 , r = n / 2;
    int vl = two(0) , vr = two((n / 2));
    if(vl == 0) return cout << "! 1" << endl , 0;
    else {
        while(l < r){
            int mid = (l + r) / 2;
            int val = two(mid);
            if(val == 0){
                cout << "! " << mid + 1 << endl;
                return 0;
            }
            if((val > 0) == (vl > 0))
                 vl = val , l = mid;
            else vr = val , r = mid;
        }
    }
    return 0;
}