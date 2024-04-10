/*input
3 3 6
1 2 3
1 1
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f

int n , l , s , ans = 0;
int w[MAX] , p[MAX] , dep[MAX] , base[MAX];
vector<int> v[MAX];
set<PII> cc[MAX];
void DFS0(int now , int deep = 1){
    dep[now] = deep;
    for(auto to : v[now]) DFS0(to , deep + 1);
}
void DFS1(int now){


    for(auto to : v[now]){
        DFS1(to);
        if(cc[to].size() > cc[now].size()) swap(cc[to] , cc[now]) , swap(base[to] , base[now]);
        // so cc[to] < cc[now]
        for(auto item : cc[to]){
            int deep = item.A , val = item.B + base[to] - base[now];

            auto pre = cc[now].lower_bound(mp(deep , val)) , nxt = pre;

            if(pre != cc[now].begin()){
                pre = prev(pre);
                if(deep >= (*pre).A && val >= (*pre).B)
                    { ans ++; continue; }
            }
            while(nxt != cc[now].end()){
                if((*nxt).A >= deep && (*nxt).B >= val){
                    cc[now].erase(nxt);
                    ans ++;
                    nxt = cc[now].lower_bound(mp(deep , val));
                }
                else break;
            }
            cc[now].insert(mp(deep , val));
        }
    }
    while(cc[now].size() && (*cc[now].begin()).B + base[now] + w[now] > s)
        cc[now].erase(cc[now].begin()) , ans ++;
    while(cc[now].size() && (*prev(cc[now].end())).A - dep[now] + 1 > l)
        cc[now].erase(prev(cc[now].end())) , ans ++;

    if(cc[now].size() == 0){
        base[now] = 0;
        cc[now].insert(mp(dep[now] , w[now]));
    }
    else base[now] += w[now];

    // cout << "now = " << now << endl;
    // for(auto to : cc[now]){
    //     DBGG(to.A , to.B + base[now]);
    // }
}
int32_t main(){
    IOS;
    cin >> n >> l >> s;
    REP(i , 1 , n + 1) cin >> w[i];
    REP(i , 2 , n + 1) cin >> p[i] , v[p[i]].pb(i);
    REP(i , 1 , n + 1) if(w[i] > s) return cout << -1 << endl , 0;

    DFS0(1);
    DFS1(1);
    ans += cc[1].size();
    cout << ans << endl;
    return 0;
}