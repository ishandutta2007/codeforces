/*input
3
telegram
digital
resistance
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , sum[MAX] , tr[MAX][26] , pos = 2;
multiset<int> cc[MAX];
string s;
void Insert(int now , int floor){
    if(floor == s.size()) sum[now] = 1;
    else {
        int idx = s[floor] - 'a';
        if(tr[now][idx] == 0) tr[now][idx] = pos ++;
        Insert(tr[now][idx] , floor + 1);
    }
}
void DFS(int now , int deep){
    REP(i , 0 , 26) if(tr[now][i]) {
        DFS(tr[now][i] , deep + 1);
        if(cc[tr[now][i]].size() > cc[now].size()) swap(cc[now] , cc[tr[now][i]]);
        for(auto to : cc[tr[now][i]]) cc[now].insert(to);
    }
    if(sum[now] == 1) cc[now].insert(deep);
    else if(cc[now].size()){
        cc[now].erase(prev(cc[now].end()));
        cc[now].insert(deep);
    }
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 0 , n) cin >> s , Insert(1 , 0);
    int sum = 0;
    REP(i , 0 , 26){
        if(tr[1][i] != 0){
            DFS(tr[1][i] , 1);
            for(auto to : cc[tr[1][i]]){
                sum += to;
                // cout << to << " ";
            }
            // cout << endl;
        }
    }
    cout << sum << endl;
    return 0;
}