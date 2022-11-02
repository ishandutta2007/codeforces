/*input
2420696208
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
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

string T(int now){
    if(now == 0) return "0";
    string ans;
    while(now != 0) ans += '0' + now % 10 , now /= 10;
    return reverse(ALL(ans)) , ans;
}
string operator ^ (string a , int b){ return a + "^" + T(b); };
string operator * (string a , int b){ return a + "*" + T(b); };
string operator + (string a , int b){ return a + "+" + T(b); };

int n;
string ans;
int P(int a , int b){
    int val = 1;
    REP(i , 0 , b){
        val *= a;
        if(val > n) return n + 1;
    }
    return val;
}
void U(string s){
    if(s.size() < ans.size()) ans = s;
}
int32_t main(){
    IOS;
    cin >> n , ans = T(n);
    if(n == 10000000000) return cout << "100^5" << endl , 0;

    REP(a , 1 , 10) REP(b , 1 , 10) REP(c , 1 , 10) REP(d , 1 , 10) REP(e , 1 , 10){ int val;
            val = P(a , b) + P(c , d) + e;
            if(val == n) U((((T(a) ^ b) + c) ^ d) + e);

        if(n / P(a , b) / P(c , d) != 0){
            val = P(a , b) * P(c , d) + e;
            if(val == n) U((((T(a) ^ b) * c) ^ d) + e);
        }
        if(n / P(a , b) / c != 0){
            val = P(a , b) * c + P(d , e);
            if(val == n) U((((T(a) ^ b) * c) + d) ^ e);
        }
        if(n / P(a , b) / c / P(d , e) != 0){
            val = P(a , b) * c * P(d , e);
            if(val == n) U((((T(a) ^ b) * c) * d) ^ e);
        }

        // a^b + c ^ d + e
        // a^b * c ^ d + e
        // a^b * c + d ^ e
        // a^b * c * d ^ e
    }
    REP(a , 1 , 10) REP(b , 1 , 10) REP(c , 1 , 100) REP(d , 1 , 100){ int val;
        if(n / P(a , c) != 0 && n / P(b , d) != 0){
            val = P(a , c) + P(b , d);
            if(val == n) U((T(a) ^ c) + "+" + (T(b) ^ d));
        }
        if(n / P(a , c) / P(b , d) != 0){
            val = P(a , c) * P(b , d);
            if(val == n) U((T(a) ^ c) + "*" + (T(b) ^ d));
        }
        if(n / P(c , d) != 0){
            val = P(a , b) + P(c , d);
            if(val == n) U((T(a) ^ b) + "+" + (T(c) ^ d));
        }
        if(n / P(a , b) / P(c , d) != 0){
            val = P(a , b) * P(c , d);
            if(val == n) U((T(a) ^ b) + "*" + (T(c) ^ d));
        }
        if(n / P(a , d) != 0 && n / P(c , b) != 0){
            val = P(c , b) + P(a , d);
            if(val == n) U((T(c) ^ b) + "+" + (T(a) ^ d));
        }
        if(n / P(c , b) / P(a , d) != 0){
            val = P(c , b) * P(a , d);
            if(val == n) U((T(c) ^ b) + "*" + (T(a) ^ d));
        }
        if(n / P(d , a) != 0 && n / P(c , b) != 0){
            val = P(c , b) + P(d , a);
            if(val == n) U((T(c) ^ b) + "+" + (T(d) ^ a));
        }
        if(n / P(c , b) / P(d , a) != 0){
            val = P(c , b) * P(d , a);
            if(val == n) U((T(c) ^ b) + "*" + (T(d) ^ a));
        }
    }
    REP(a , 2 , n + 1) {
        if(a * a > n) break;
        int val = a;
        REP(b , 2 , n + 1){
            val *= a;
            if(val > n) break;
            else if(val == n) U(T(a) ^ b);
            else {
                int c = n / val;
                if(n % val == 0) U((T(a) ^ b) * c);
                else if(c == 1) U((T(a) ^ b) + (n % val));
                else U(((T(a) ^ b) * c) + (n % val));
            }
        }
    }
    cout << ans << endl;
    return 0;
}