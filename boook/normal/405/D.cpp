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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 1000900
#define INF 0x3f3f3f3f

inline int rit(){
    char c = getchar();
    int res = 0;
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) res = (res << 1) + (res << 3) + c - '0' , c = getchar();
    return res;
}
int n , use[MAX] , N = 1000001;
int ans[MAX] , po = 0;
int32_t main(){
    n = rit();
    REP(i , 0 , n) use[rit()] ++;
    int pr = 0;
    REP(i , 1 , N){
        if(N - i > i) continue;
        if(use[i] && use[N - i]) pr ++;
        else if(use[i]) ans[po ++] = N - i;
        else if(use[N - i]) ans[po ++] = i;
    }
    REP(i , 1 , N){
        if(pr == 0) break;
        if(use[i] == 0 && use[N - i] == 0){
            pr --;
            ans[po ++] = i;
            ans[po ++] = N - i;
        }
    }
    printf("%d\n", po);
    REP(i , 0 , po) printf("%d ", ans[i]); puts("");
    return 0;
}