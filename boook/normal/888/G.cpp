/*input
4
1 2 3 4
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 200900
#define INF 0x3f3f3f3f

int sum[MAX * 30] , ls[MAX * 30] , rs[MAX * 30] , po = 2;
void update(int now , int floor , int val , int add){
    if(floor == -1) sum[now] += add;
    else {
        if(val & (1 << floor)){
            if(rs[now] == 0) rs[now] = po ++ , sum[rs[now]] = 0;
            update(rs[now] , floor - 1 , val , add);
        }
        else {
            if(ls[now] == 0) ls[now] = po ++ , sum[ls[now]] = 0;
            update(ls[now] , floor - 1 , val , add);
        }
        sum[now] = sum[ls[now]] + sum[rs[now]];
    }
}
int query(int now , int floor , int val){
    if(floor == -1) return 0;
    if(val & (1 << floor)){
        if(sum[rs[now]]) return query(rs[now] , floor - 1 , val);
        else return query(ls[now] , floor - 1 , val) + (1 << floor);
    }
    else {
        if(sum[ls[now]]) return query(ls[now] , floor - 1 , val);
        else return query(rs[now] , floor - 1 , val) + (1 << floor);
    }
}
long long solve(vector<int> sol , int floor){
    if(floor == -1 || sol.size() == 0) return 0;
    vector<int> lth , rth;
    for(auto to : sol){
        if(to & (1 << floor)) rth.pb(to);
        else lth.pb(to);
    }
    long long cnt = solve(lth , floor - 1) + solve(rth , floor - 1);

    // cout << "lth = "; for(auto to : lth) cout << to << " ";
    // cout << "rth = "; for(auto to : rth) cout << to << " "; cout << endl;
    if(lth.size() == 0 || rth.size() == 0) return cnt;
    long long sml = 2147483647;
    for(auto to : lth){
        sml = min(sml , (long long)query(1 , 30 , to ^ (1 << floor)) + (1 << floor));
    }
    return cnt + sml;
}
int n;
int32_t main(){
    IOS;
    cin >> n;
    vector<int> sol;
    REP(i , 0 , n){
        int in;
        cin >> in;
        update(1 , 30 , in , 1);
        sol.pb(in);
    }
    cout << solve(sol , 30) << endl;
    return 0;
}