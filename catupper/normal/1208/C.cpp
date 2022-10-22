#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;



Int n, cnt;
Int ans[1080][1080];
int main(){
    cin >> n;
    for(int i = 0;i < n/4;i++){
        for(int j = 0;j < n/4;j++){
            for(int k = 0;k < 4;k++){
                for(int l = 0;l < 4;l++){
                    ans[i * 4 + k][j * 4 + l] = cnt++;
                }
            }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            printf("%lld ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}