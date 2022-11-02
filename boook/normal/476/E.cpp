#include <bits/stdc++.h>
using namespace std;
#define MAX 2010
#define INF 0x3f3f3f3f

int dp[MAX][MAX];
string s , a , b;
int32_t main(){
    cin >> s >> b;
    a = " " + s;
    for(int i = 0 ; i < a.size() ; i ++)
        for(int j = 0 ; j < a.size() ; j ++)
            if(j > i) dp[i][j] = -INF;
    for(int i = 1 ; i < a.size() ; i ++){
        int po = i , cnt = 0;
        for(int j = b.size() - 1 ; j >= 0 ; j--){
            while(po >= 0 && a[po] != b[j]) po -- , cnt ++;
            po--;
        }
        for(int j = 0 ; j < a.size() ; j ++){
            dp[i][j] = max(dp[i][j] , dp[i - 1][j]);
            if(po >= 0 && j >= cnt) dp[i][j] = max(dp[i][j] , dp[po][j - cnt] + 1);
        }
    }
    for(int i = 0 ; i < a.size() ; i ++)
        cout << dp[a.size() - 1][i] << " " ;
    cout << endl;
    return 0;
}