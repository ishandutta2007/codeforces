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
#define MAX 2000000
#define INF 0x3f3f3f3f

int n;
vector<int> ans , v;

int32_t main(){
    cin >> n;
    while(n > 0){
        v.pb(n % 10) , n /= 10;
    }
    while(v.size()){
        int tmp = 0;
        RREP(i , v.size() - 1 , 0){
            if(v[i] > 0) v[i]-- , tmp = tmp * 10 + 1;
            else tmp = tmp * 10;
        }
        while(v.size() && v.back() == 0) v.pop_back();
        ans.pb(tmp);
    }
    cout << ans.size() << endl;
    for(auto now : ans) cout << now << " " ; cout << endl;
    return 0;
}