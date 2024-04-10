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

int n , m;
int x[MAX] , a[MAX];
int32_t main(){
    cin >> n >> m;
    REP(i , n) cin >> x[i];
    REP(i , m) cin >> a[i];
    sort(a , a + m , greater<int>());
    VI qq;
    int po = 0;
    REP(i , n){
        if(x[i] == 0) x[i] = a[po++];
    }
    REP(i , n) qq.pb(x[i]);
    sort(ALL(qq));
    REP(i , n){
        if(qq[i] != x[i]) return puts("YES");
    }
    return puts("NO");
    return 0;
}