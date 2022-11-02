#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k)  for(int i = j ; i <  k ; i ++)
#define RREP(i , j , k) for(int i = j ; i >= k ; i --)
#define MEM(i , j) memset(i , j , sizeof i)
#define pb push_back
#define MAX 5050
#define int long long
int sol[] = {0 , 1 , 2 , 3};
int x[] = {1 , 6 , 8 , 9};
int p[10] , cnt[200];
int32_t main() {
//    cout << 1689 << " " << 1689 % 7 << endl;
    while(next_permutation(sol , sol + 4)){
        int tmp = 0;
        REP(i , 0 , 4){
            tmp = tmp * 10 + x[sol[i]];
        }
        p[tmp % 7] = tmp;
    }
//    REP(i , 0 , 7) cout << p[i] << " "; cout << endl;
    string s;
    cin >> s;
    REP(i , 0 , s.size()){
        cnt[s[i] - '0'] ++;
    }
    cnt[1] --;
    cnt[6] --;
    cnt[8] --;
    cnt[9] --;
    int ok = 0;
    REP(i , 1 , 10){
        if(cnt[i]) ok = 1;
    }
    if(ok == 0){
        cout << p[0] ;
        REP(i , 0 , cnt[0]) cout << 0 ;
        cout << endl;
        return 0;
    }
    int val = 0;
    string ans;
    RREP(i , 9 , 0){
        REP(j , 0 , cnt[i]){
            cout << i ;
            val = (val * 10 + i) % 7;
        }
    }
    val = val * 10000 % 7;
    val = 7 - val;
    cout << p[val % 7] << endl;
	return 0;
}