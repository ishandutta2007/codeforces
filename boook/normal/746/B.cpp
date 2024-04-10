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
#define MAX 4040
#define INF 0x3f3f3f3f

string s;
int ans[MAX];
vector<int> v , sol;
int32_t main(){
    cin >> s >> s;
    REP(i , 0 , s.size()) v.pb(i);
    while(v.size()){
        int val = (v.size() - 1) / 2;
        sol.pb(v[val]);
        v.erase(v.begin() + val);
    }
    REP(i , 0 , sol.size()) ans[sol[i]] = i;
    REP(i , 0 , sol.size()) cout << s[ans[i]] ; cout << endl;
    return 0;
}