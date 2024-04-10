/*input
2
0 2 1
0 2 -1
4
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
#define int int_fast64_t
#define MAX 50900
#define INF 10000000000000000LL

int n , idx , k;
int t[MAX] , s[MAX] , ss[MAX] , p[MAX] , sol[MAX] , ans[MAX];
int cmp(int a , int b){
    if(p[a] == -1 || p[b] == -1) return p[a] > p[b];
    return t[a] < t[b];
}
map<int , int> cc;
int solve(int mid){
    if(cc.find(mid) != cc.end()) mid = cc[mid];
    p[idx] = mid;
    // DBGG("now solve mid = " , mid);
    sort(sol + 1 , sol + 1 + n , cmp);
    REP(i , 1 , n + 1) s[i] = ss[i];

    priority_queue<PII> pq;
    int pos = 1 , times = 0;
    REP(i , 1 , n + 1){
        while(pos <= n && t[sol[pos]] <= times)
            pq.push(mp(p[sol[pos]] , sol[pos])) , pos ++;
        int nxt = INF;
        if(pos <= n) nxt = min(nxt , t[sol[pos]]);
        // DB4("times = " , times , "nxt = " , nxt);
        if(pq.size()){
            PII now = pq.top(); pq.pop();
            if(nxt - times >= s[now.B]){
                ans[now.B] = times + s[now.B];
                if(now.B == idx && ans[now.B] != k) return ans[now.B]; 
                // DB4("get ans[" , now.B , "] = " , ans[now.B]);
                times = ans[now.B];
            }
            else {
                pq.push(now);
                s[now.B] -= nxt - times;
                times = nxt , i --;
            }
        }
        else times = nxt , i --;
    }
    if(ans[idx] == k){
        cout << mid << endl;
        REP(i , 1 , n + 1) cout << ans[i] << " "; cout << endl;
        exit(0);
    }
    else return ans[idx];
}
int32_t main(){
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> t[i] >> ss[i] >> p[i];
    REP(i , 1 , n + 1) if(p[i] != -1) cc[p[i]] = p[i] - 1;
    REP(i , 1 , n + 1) if(p[i] == -1) idx = i;
    REP(i , 1 , n + 1) sol[i] = i;
    cin >> k;

    for(auto to = cc.begin() ; to != cc.end() ; to = next(to)){
        if(cc.find((*to).A - 1) != cc.end()) (*to).B = cc[(*to).A - 1];
    }
    int now = 1000000000;
    RREP(i , 30 , 0){
        int to = now - (1 << i);
        if(to >= 0 && solve(to) < k) now = to;
    }
    solve(now - 1);
    cout << "wrong answer" << endl;
    return 0;
}