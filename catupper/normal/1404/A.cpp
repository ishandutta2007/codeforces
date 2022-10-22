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

int l, n;
char str[330000];

void solve(){
    scanf(" %d%d", &l, &n);
    scanf(" %s", str);
    bool ok = true;
    int cnt[]  = {0,0};
    for(int i = 0;i < n;i++){
        int used[] = {0, 0, 0};
        for(int j = i;j < l;j += n){
            if(str[j] == '0')used[0] = 1;
            if(str[j] == '1')used[1] = 1;
            if(str[j] == '?')used[2] = 1;
        }
        if(used[0] && used[1])ok = false;
        cnt[0] += used[0];
        cnt[1] += used[1];
    }
    if(cnt[0] > n/2 || cnt[1] > n/2)ok = false;
    if(ok)puts("YES");
    else puts("NO");
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--)solve();
    return 0;
}