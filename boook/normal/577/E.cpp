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
#define MAX 1000900
#define INF 0x3f3f3f3f

int n;
PII val[MAX];
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 0 , n){
        int q , w;
        cin >> q >> w;
        val[i].A = (q / 1050) * 1050 + w / 1050;
        val[i].B = i;
    }
    sort(val , val + n);
    REP(i , 0 , n) cout << val[i].B + 1 << " ";
    cout << endl;

    return 0;
}