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
#define MAX 
#define INF 0x3f3f3f3f

string s;
string a , b , c , tmp;
int A(){
    int siz = a.size();
    if(1 <= siz && siz <= 16){
        REP(i , 0 , a.size()){
            if(a[i] >= 'a' && a[i] <= 'z') continue;
            if(a[i] >= 'A' && a[i] <= 'Z') continue;
            if(a[i] >= '0' && a[i] <= '9') continue; 
            if(a[i] == '_') continue;
            return 0;
        }
        return 1;
    }
    return 0;
}
int B(){
    int siz = b.size();
    if(1 <= siz && siz <= 32){
        vector<int> qq;
        qq.pb(-1);
        REP(i , 0 , b.size()){
            if(b[i] == '.') qq.pb(i);
        }qq.pb(b.size());

        // for(auto to : qq) cout << to << " " ; cout << endl;

        REP(i , 1 , qq.size()){
            int l = qq[i - 1] + 1 , r = qq[i] - 1;
            int ssiz = r - l + 1;
            if(1 <= ssiz && ssiz <= 16){
                REP(k , l , r + 1){
                    if(b[k] >= 'a' && b[k] <= 'z') continue;
                    if(b[k] >= 'A' && b[k] <= 'Z') continue;
                    if(b[k] >= '0' && b[k] <= '9') continue; 
                    // DB4(i , b[k] , l , r);

                    if(b[k] == '_') continue;
                    return 0;
                }
            }
            else return 0;
        }
        return 1;
    }
    return 0;
}
int C(){
    int siz = c.size();
    // DBGG("now = " , c);
    if(1 <= siz && siz <= 16){
        REP(i , 0 , c.size()){
            if(c[i] >= 'a' && c[i] <= 'z') continue;
            if(c[i] >= 'A' && c[i] <= 'Z') continue;
            if(c[i] >= '0' && c[i] <= '9') continue; 
            if(c[i] == '_') continue;
            return 0;
        }
        return 1;
    }
    return 0;
}
int32_t main(){
    cin >> s;
    int cnt = -1;
    RREP(i , s.size() - 1 , 0){
        if(s[i] == '@') cnt = i;
    }
    if(cnt == -1) cout << "NO" << endl;
    else {
        REP(i , 0 , cnt) a += s[i];
        if(A() == 0){
            cout << "NO" << endl;
            return 0;
        }
        REP(i , cnt + 1 , s.size()) tmp += s[i];
        int res = -1;
        RREP(i , tmp.size() - 1 , 0) 
            if(tmp[i] == '/') res = i;
        if(res == -1) {
            b = tmp;
            if(B() == 0){
                cout << "NO" << endl;
                return 0;
            }
        }
        else {
            REP(i , 0 , res) b += tmp[i];
            REP(i , res + 1 , tmp.size()) c += tmp[i];
            if(B() == 0 || C() == 0){
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << "YES" << endl;
    }
    return 0;
}