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
#define MAX 400000
#define INF 0x3f3f3f3f

int n , x[MAX];
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    int mm = x[1];
    REP(i , 1 , n + 1) mm = min(x[i] , mm);
    int ans = mm * n;
    vector<int> tmp;
    REP(i , 1 , n + 1) if(x[i] == mm) tmp.pb(i);
    int cnt = 0;
    REP(i , 1 , tmp.size()){
        cnt = max(cnt , tmp[i] - tmp[i - 1] - 1);
    }
    if(tmp.size() == 1) cnt = max(cnt , n - 1);
    else {
        cnt = max(cnt , tmp[0] - 1 + n - (tmp.back() + 1) + 1);
    }
    cout << ans + cnt << endl;
    return 0;
}