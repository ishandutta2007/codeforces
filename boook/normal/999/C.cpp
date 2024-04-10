/*input
1 1
u
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
#define MAX 400090
#define INF 0x3f3f3f3f

int n , k , ans[MAX];
queue<int> qu[100];
string s;
int32_t main(){
    IOS;
    cin >> n >> k;
    cin >> s;
    REP(i , 0 , s.size()) qu[s[i] - 'a'].push(i) , ans[i] = -1;
    int pos = 0;
    while(k){
        if(qu[pos].size() == 0) pos ++;
        else qu[pos].pop() , k --;
    }
    REP(i , 0 , 26){
        while(qu[i].size()){
            int now = qu[i].front(); qu[i].pop();
            ans[now] = i;
        }
    }
    REP(i , 0 , s.size()) if(ans[i] != -1) cout << char('a' + ans[i]) ;
    cout << endl;
    return 0;
}