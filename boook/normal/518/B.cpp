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

string a , b;
multiset<char> cc;
int32_t main(){
    cin >> a >> b;
    REP(i , 0 , b.size()) cc.insert(b[i]);
    int aa = 0 , bb = 0;
    vector<char> tmp;
    REP(i , 0 , a.size()){
        if(cc.find(a[i]) != cc.end()){
            aa ++;
            cc.erase(cc.find(a[i]));
        }   
        else {
            tmp.pb(a[i]);
        }     
    }
    REP(i , 0 , tmp.size()){
        char qq = tmp[i];
        if(qq >= 'a' && qq <= 'z') qq = qq - 'a' + 'A';
        else qq = qq + 'a' - 'A';
        if(cc.find(qq) != cc.end()){
            bb ++;
            cc.erase(cc.find(qq));
        }   
    }
    cout << aa << " " << bb  << endl;
    return 0;
}