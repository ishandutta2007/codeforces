#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int ans[200][200];

int main(){
    int n = 165, k;
    ans[0][0] = 1;
    ans[1][1] = 1;
    for(int i = 2;i <= n;i++){
        int b = 1;
        for(int j = n;j >= 1;j--){
            ans[i][j] = ans[i-1][j-1];
            if(ans[i][j] != 0 && ans[i][j] == ans[i-2][j])b=-1;            
        }
        for(int j = 0;j < n-2;j++)ans[i][j] += ans[i-2][j] * b;
        
    }
    cin >> n;
    cout << n << endl;
    for(int i = 0;i <= n;i++){
        cout << ans[n][i] << " ";
    }cout << endl;
    while(n--){
    cout << n << endl;
    for(int i = 0;i <= n;i++){
        cout << ans[n][i] << " ";
    }cout << endl;
break;
    }
    return 0;
}