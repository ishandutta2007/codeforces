/*input
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int n , m;
map<int , int> x;
int32_t main(){
    cin >> n >> m;
    int siz = 0;
    REP(i , 0 , 62) if(n & (1LL << i)) x[i] = 1 , siz ++;
    if(siz > m) return cout << "No" << endl , 0;
    RREP(i , 61 , -INF) if(x[i] != 0){
        if(siz + x[i] <= m){
            x[i - 1] += x[i] + x[i];
            siz += x[i];
            x[i] = 0;
        }
        else break;
    }
    priority_queue<int , vector<int> , greater<int>> pq;
    for(auto to : x){
        REP(times , 0 , to.B) pq.push(to.A);
    }
    stack<int> st;
    while(pq.size() != m){
        int now = pq.top();
        pq.pop();
        pq.push(now - 1);
        pq.push(now - 1);
    }
    cout << "Yes" << endl;
    while(pq.size()){
        st.push(pq.top());
        pq.pop();
    }
    while(st.size()){
        cout << st.top() << " " ;
        st.pop();
    }
    cout << endl;
    return 0;
}