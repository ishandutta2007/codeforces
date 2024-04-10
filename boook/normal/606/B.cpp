#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 1000
#define INF 0x3f3f3f3f

int use[MAX][MAX];
int n , m;
PII now;
int IN(PII tmp){
    return (tmp.A >= 0 && tmp.A < n && tmp.B >= 0 && tmp.B < m);
}
int32_t main(){
    cin >> n >> m;
    cin >> now.A >> now.B;
    now = mp(now.A - 1 , now.B - 1);
    string s;
    cin >> s;
    
    use[now.A][now.B] ++;
    REP(i , 0 , s.size()){
        PII d;
        if(s[i] == 'U') d = mp(-1 , 0);
        if(s[i] == 'R') d = mp(0 , 1);
        if(s[i] == 'L') d = mp(0 , -1);
        if(s[i] == 'D') d = mp(1 , 0);
        if(use[now.A][now.B] == 1) cout << "1 ";
        else cout << "0 ";
        if(i + 1 == s.size()) continue;
        if(IN(mp(now.A + d.A , now.B + d.B))){
            now.A += d.A , now.B += d.B;
            use[now.A][now.B] ++;
        }
        else use[now.A][now.B] ++;
    }
    int sum = 0;
    REP(i , 0 , n) REP(j , 0 , m) if(use[i][j] == 0) sum ++;
    cout << sum << endl;
    return 0;
}