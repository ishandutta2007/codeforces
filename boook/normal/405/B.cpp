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
#define MAX 
#define INF 0x3f3f3f3f

int n;
string s;

int32_t main(){
    IOS;
    cin >> n >> s;
    int ans = 0;
    REP(i , 0 , s.size()){
        if(s[i] != '.') continue;
        int a = 0 , b = 0;
        int fr = i , ba = i;
        while(fr >= 0 && s[fr] == '.') fr --;
        while(ba < s.size() && s[ba] == '.') ba ++;
        if(fr != -1 && s[fr] == 'L') fr = -1;
        if(ba != s.size() && s[ba] == 'R') ba = s.size();
        if(fr == -1 && ba == s.size()) ans ++;
        else if(fr != -1 && ba != s.size()){
            if(i - fr == ba - i) ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}