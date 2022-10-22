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

int p[4400];
bool used[4400];
bool ok[4400];
int n, t;
void solve(){
    scanf("%d", &n);
    int mx = 2*n;
    for(int i = 1;i <= n * 2;i++)ok[i] = used[i] = false;    
    for(int i = 0;i < n * 2;i++)scanf("%d", &p[i]);
    int now = 2*n-1;
    int cnt = 0;
    vector<int> cnts;
    while(mx){
        while(true){
            int x = p[now];
            used[x] = true;
            now--;
            cnt++;
            if(x == mx)break;
        }
        cnts.push_back(cnt);
        cnt = 0;
        while(used[mx])mx--;
    }

    ok[0] = true;
    for(auto cnt:cnts){
        for(int i = n;i-cnt >= 0;i--){
            ok[i] |= ok[i-cnt];
        }
    }
    if(ok[n])puts("YES");
    else puts("NO");
}

int main(){
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}