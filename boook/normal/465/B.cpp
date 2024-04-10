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
#define MAX 50000
#define INF 0x3f3f3f3f

vector<int> v;
int n , x[MAX];

int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1){
        if(x[i] == 1) v.pb(i);
    }
    int cnt = (v.size() > 0) ? 1 : 0;
    REP(i , 1 , v.size()){
        if(v[i] == v[i - 1] + 1) cnt ++;
        else cnt += 2;
    }
    cout << cnt << endl;
    return 0;
}