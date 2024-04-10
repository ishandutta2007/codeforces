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

int R,G,B;
vector<Int> r, g, b;
#define sq(x) ((x)*(x))

Int calc(vector<Int> &r, vector<Int> &g, vector<Int> &b){
    Int gp = 0;
    Int bp = 0;
    Int ans = LINF* 4;
    for(auto x: r){
        while(gp+1 < g.size() && g[gp] < x)gp++;
        while(bp+1 < b.size() && b[bp+1] <= x)bp++;
        Int aa = x - g[gp], bb = g[gp] - b[bp], cc = x - b[bp];
        ans = min(ans, aa*aa+bb*bb+cc*cc);
    }
    gp = 0;
    bp = 0;        
    for(auto x: r){
        while(bp+1 < b.size() && b[bp] < x)bp++;
        while(gp+1 < g.size() && g[gp+1] <= x)gp++;
        Int aa = x - g[gp], bb = g[gp] - b[bp], cc = x - b[bp];
        ans = min(ans, aa*aa+bb*bb+cc*cc);
    }
    return ans;
}

void solve(){
    scanf("%d%d%d", &R, &G, &B);
    r.resize(R);g.resize(G);b.resize(B);
    for(int i = 0;i < R;i++)scanf("%lld", &r[i]);
    for(int i = 0;i < G;i++)scanf("%lld", &g[i]);
    for(int i = 0;i < B;i++)scanf("%lld", &b[i]);
    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());

    printf("%lld\n", min({calc(r,g,b), calc(b,r,g), calc(g,b,r)}));
    
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)solve();
    return 0;
}