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
#define int long long
#define INF 0x3f3f3f3f

string s;
int32_t main(){
    cin >> s;
    priority_queue<PII , vector<PII> , greater<PII> > pq;
    int cnt = 0 , sum = 0;
    REP(i , 0 , s.size()){
        if(s[i] == '(') cnt ++;
        else if(s[i] == '?'){
            int q , w;
            cin >> q >> w;
            sum += w;
            cnt --;
            s[i] = ')';
            pq.push(mp(q - w , i));
        }
        else if(s[i] == ')') cnt --;
        if(cnt < 0){
            if(pq.size() == 0) return 0 * puts("-1");
            else sum += pq.top().A , s[pq.top().B] = '(' , pq.pop();
            cnt += 2;
        }
    }
    if(cnt != 0) cout << -1 << endl;
    else cout << sum << endl << s << endl;
    return 0;
}