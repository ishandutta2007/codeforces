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
#include<complex>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

int a[110000];

void solve(){
    int n;
    scanf("%d", &n);
    int all = 0;
    for(int i = 0;i < n;i++){
        scanf("%d", &a[i]);
        all ^= a[i];
    }    
    if(all == 0){puts("DRAW");return;}
    while((all & -all) != all)all -= all & -all;
    int one_cnt = 0;
    for(int i = 0;i < n;i++){
        if(a[i] & all)one_cnt++;
    }
    int zero_cnt = n - one_cnt;
    one_cnt = (one_cnt - 1) / 2;
    if(one_cnt % 2 == 1 && zero_cnt % 2 == 0)puts("LOSE");
    else puts("WIN");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)solve();
    return 0;
}