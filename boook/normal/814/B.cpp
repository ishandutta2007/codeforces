#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 100000
#define INF 0x3f3f3f3f

int n , a[MAX] , b[MAX] , x[MAX] , use[MAX];

int32_t main(){
    cin >> n;
    REP(i , n) cin >> a[i];
    REP(i , n) cin >> b[i];
    int q , w;
    REP(i , n) x[i] = a[i];
    REP(i , n){
        use[x[i]] ++;
        if(use[x[i]] == 2) q = x[i];
    }
    REPNM(i , 1 , n + 1) if(use[i] == 0) w = i; 
    REP(i , n){
        if(x[i] == q){
            x[i] = w;
            int ok = 1 , aa = 0 , bb = 0;
            REP(j , n) if(x[j] != a[j]) aa++;
            REP(j , n) if(x[j] != b[j]) bb++;
            if(aa == 1 && bb == 1){
                REP(j , n) cout << x[j] << " ";
                cout << endl;
                return 0;
            }
            x[i] = q;
        }
    }
    return 0;
}