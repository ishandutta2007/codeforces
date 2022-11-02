#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define PII pair<int , int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
// #define DBGG(i , j) cout << i << " " << j << endl
// #define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define MAX 200900

string s = "101";
int n , k;
int times = 0;
// int GET(int l , int r){
// 	// cout << "l = " << l << " " << "r = " << r << endl;
// 	times ++;
//     l -- , r --;
//     if(rand() % 2 == 0){
//         REP(i , 0 , s.size()) if(i <= r) s[i] = s[i] == '1' ? '0' : '1';
//     }
//     else {
//     	REP(i , 0 , s.size()) if(i >= l) s[i] = s[i] == '1' ? '0' : '1';
//     }
//     cout << s << endl;
//     // exit(0);
//     int cnt = 0;
//     REP(i , 0 , s.size()) cnt += s[i] == '1';
//     // cout << "cnt = " << cnt << endl;
//     return cnt;
// }
int ask(int l , int r){
	// return GET(l , r);
    cout << "? " << l << " " << r << endl;
    fflush(stdout);
	int res; cin >> res;
	return res;
}
int Q(int l , int r){
    int ks = k , res , ans;

    int q[2] = {0 , 0};
    res = ask(l , r) , ans = res;
    q[abs(res - ks) % 2] ^= 1 , ks = res;

    while(q[0] == 1 || q[1] == 1){
        res = ask(l , r);
        q[abs(res - ks) % 2] ^= 1 , ks = res;
    }
    // DBGG("res = " , ans);
    // exit(0);
    return ans;
}
int ans[MAX];
int32_t main(){
    cin >> n >> k;
// n = s.size() , k = 0;
// REP(i , 0 , s.size()) k += s[i] == '1';

    memset(ans , -1 , sizeof ans);
    if(n == 1){
        cout << "! " << k << endl;
    }
    else if(n == 2){
        if(k == 0) cout << "! 00" << endl;
        else if(k == 1){
            int res = Q(1 , 1);
            while(res == k) res = Q(1 , 1);
            if(res > k) cout << "! 01" << endl;
            if(res < k) cout << "! 10" << endl;
        }
        else if(k == 2) cout << "! 11" << endl;
    }
    else if(n % 2 == 0){
    	// cout << "begin = " << endl;
        int sum = 0;
        REP(i , 1 , n + 1){
            int res = Q(i , i);
            while(abs(res - k) % 2 != i % 2) res = Q(i , i);
            // DB4("res = " , res , "s = " , s);
            int tmp = k - sum + (i - 1 - sum);
            if(tmp + 1 == res) ans[i] = 0;
            if(tmp - 1 == res) ans[i] = 1;
            sum += ans[i];
            // break;
        }
        cout << "! ";
        REP(i , 1 , n + 1) cout << ans[i] ;
        cout << endl;
    }
    else if(n % 2 == 1){
        int fir = Q(2 , 3);
        while(abs(fir - k) % 2 != 0) fir = Q(2 , 3);
        
        int ccc = 0;
        if(1 + (n - 1) - (k - 1) == fir) ans[1] = 1 , ccc ++;
        if(0 + (n - 1) - (k - 0) == fir) ans[1] = 0 , ccc ++;
        assert(ccc == 1);

        int sum = ans[1];
        REP(i , 2 , n + 1){
            int res = Q(i - 1 , i);
            while(abs(res - k) % 2 != i % 2) res = Q(i - 1 , i);
            int tmp = k - sum + (i - 1 - sum);
            // DB4("res = " , res , "i = " , i);
            // DB4("tmp = " , tmp , "s = " , s);
            if(tmp + 1 == res) ans[i] = 0;
            if(tmp - 1 == res) ans[i] = 1;
            sum += ans[i];
            // if(ans[i] == -1)
             // return 0;
        }
        cout << "! ";
        REP(i , 1 , n + 1) cout << ans[i] ;
        cout << endl;
    }
    fflush(stdout);

    // int ok = 1;
    // REP(i , 0 , s.size()) if(ans[i + 1] != s[i] - '0') ok = 0;


   //  if(ok == 0) cout << "wA" << endl;
   //  else cout << "AC" << endl;
   // cout << "times = " << times << endl;
    return 0;
}