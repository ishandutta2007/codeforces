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
// #define DBGG(i,j)     cout << i << " " << j << endl
// #define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 40
#define INF 0x3f3f3f3f

int good[MAX];
string s , p , fr , ba;
int n;
int F(char a , char b){
    // DBGG(b , good[b - 'a']);
    if(a == '?') return good[b - 'a'];
    else return a == b;
}
int32_t main(){
    IOS;
    cin >> s;
    REP(i , 0 , s.size())
        good[s[i] - 'a'] = 1;
    int star = 0;
    cin >> p;
    REP(i , 0 , p.size()){
        if(p[i] == '*'){
            star = 1;
            fr = p.substr(0 , i);
            ba = p.substr(i + 1);
            // DB4("fr = " , fr , "ba = " , ba);
            break;
        }
    }

    cin >> n;
    REP(times , 0 , n){
        cin >> s;
        if(star == 0){
            int ok = 1;
            if(s.size() != p.size()) ok = 0;
            else {
                // DBGG("ok = " , ok);
                REP(i , 0 , s.size()){
                    if(F(p[i] , s[i]) == 0) ok = 0;
                }
            }
            if(ok == 0) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        else {
            int ok = 1;
            if(fr.size() + ba.size() > s.size()) ok = 0;
            else {
                int lpo = 0 , rpo = s.size() - 1;
                REP(i , 0 , fr.size()){
                    if(F(fr[i] , s[lpo]) == 0) ok = 0;
                    lpo ++;
                }
                RREP(i , ba.size() - 1 , 0){
                    if(F(ba[i] , s[rpo]) == 0) ok = 0;
                    rpo --;
                }
                REP(i , lpo , rpo + 1){
                    if(good[s[i] - 'a'] == 1) ok = 0;
                }
            }
            if(ok == 0) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
    return 0;
}