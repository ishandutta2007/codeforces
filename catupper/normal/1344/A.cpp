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

void ok(){
    cout << "YES" << endl;
    exit(0);
}

void ng(){
    cout <<  "NO" << endl;
    exit(0);
}

bool used[220000];

void solve(){
    int n, a;
    scanf("%d", &n);
    bool ok = true;
    fill(used, used + n, false);
    for(int i = 0;i < n;i++){
        scanf("%d", &a);
        int dest = (i + a) % n;
        if(dest < 0)dest += n;
        if(used[dest])ok = false;
        else used[dest] = true;        
    }
    if(ok)puts("YES");
    else puts("NO");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)solve();
    return 0;
}