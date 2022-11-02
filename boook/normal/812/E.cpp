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
#define int long long
#define MAX 100090
#define INF 0x3f3f3f3f

int n , val[MAX] , col[MAX];
VI v[MAX];
void DFS(int now){
    if(v[now].empty()) col[now] = 1;
    else {
        for(auto to : v[now]) DFS(to);
        col[now] = !col[v[now][0]];
    }
}
int32_t main(){
    cin >> n;
    REPNM(i , 1 , n + 1) cin >> val[i];
    REPNM(i , 2 , n + 1) cin >> col[0] , v[col[0]].pb(i);

    DFS(1);
    int res = 0 , ans = 0;
    REPNM(i , 1 , n + 1)
        if(col[i]) res ^= val[i];
    if(res == 0){
        int uncnt = 0 , cnt = 0;
        REPNM(i , 1 , n + 1){
            if(col[i] == 0) uncnt ++;
            if(col[i] == 1) cnt++;
        }
        ans += uncnt * (uncnt - 1) / 2;
        ans += cnt * (cnt - 1) / 2;

        map<int , int> a , b;
        REPNM(i , 1 , n + 1){
            if(col[i] == 0) a[val[i]] ++;
            if(col[i] == 1) b[val[i]] ++;
        }
        REPNM(i , 1 , n + 1){
            if(col[i] == 1){
                ans += a[val[i]] * b[val[i]];
                a[val[i]] = b[val[i]] = 0;
            }
        }
    }
    if(res != 0){
        map<int , int> uncol;
        REPNM(i , 1 , n + 1)
            if(col[i] == 0) uncol[val[i]] ++;
        REPNM(i , 1 , n + 1){
            if(col[i] == 1){
                int tmp = res ^ val[i];
                ans += uncol[tmp];
            }
        }
    }


    cout << ans << "\n";
    return 0;
}