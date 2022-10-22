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
#define INF (1<<30)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

int a[4400];
int mx[4400];
void solve(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    k = min(k, m-1);
    for(int i = 0;i < n;i++){
        scanf("%d", a+i);
    }
    int rest = n - m + 1;
    for(int i = 0;i+rest-1 < n;i++){
        mx[i] = max(a[i], a[i + rest - 1]);
    }
    int ambiguous = m - k;
    int ans = 0;
    for(int i = 0;i+rest-1 < n;i++){
        int tmp = INF;
        for(int j = 0;j < ambiguous;j++){
            if(i + j + rest - 1 >= n){
                tmp = -INF;
                break;
            }
            tmp = min(tmp, mx[i+j]);
        }
        ans = max(ans, tmp);
    }
    printf("%d\n", ans);
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}