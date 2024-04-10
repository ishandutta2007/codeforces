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
#define MAX 
#define INF 0x3f3f3f3f

string s;
int big = 0 , sml = 0;
int check(){
    int now = 0;
    REP(i , int(s.size()) - 1){
        now += 1 - (s[i] == 'L') * 2;
        big = max(big , now);
        sml = min(sml , now);
    }
    now += 1 - (s[int(s.size() - 1)] == 'L') * 2;
    return (now > big || now < sml);
}
int judge(int x){
    int now = 0 , bi = 0 , sm = 0;
    REP(i , int(s.size()) - 1){
        if(s[i] == 'R' && now + 1 != x) now ++;
        if(s[i] == 'L' && now - 1 != x) now --;
        bi = max(now , bi) , sm = min(now , sm);
    }
    if(s[int(s.size()) - 1] == 'R' && now + 1 != x) now ++;
    if(s[int(s.size()) - 1] == 'L' && now - 1 != x) now --;
    // DB4("big = " , bi , "sml = " , sm);
    // DBGG("s[int(s.size()) - 1] = " , s.back());
    // DB4("x = " , x , "now =" , now);
    return (now > bi || now < sm);
}
int32_t main(){
    IOS;
    cin >> s;
    if(check()) return puts("1");
    else {
        int ans = 0;
        if(judge(1)){
            int now = 1;
            RREP(i , 20 , 0){
                int to = now + (1 << i);
                if(judge(to)) now = to;
            }
            ans += now;
        }
        if(judge(-1)){
            int now = -1;
            RREP(i , 20 , 0){
                int to = now - (1 << i);
                if(judge(to)) now = to;
            }
            ans += abs(now);
        }
        cout << ans << "\n";
    }
    return 0;
}