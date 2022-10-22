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

Int ax, ay, bx, by, tx, ty;
Int n;
Int x, y;

Real dist(Real x1, Real y1, Real x2, Real y2){
    Real dx = x1 - x2;
    Real dy = y1 - y2;
    return sqrt(dx*dx+dy*dy);
}

int main(){
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    cin >> n;
    vector<pair<Real, int>> alice, bob;
    Real base = 0;
    for(int i = 0;i < n;i++){
        cin >> x >> y;
        Real dbin = dist(tx, ty, x, y);
        Real dalice = dist(ax, ay, x, y);
        Real dbob = dist(bx, by, x, y);
        
        base += 2 * dbin;
        alice.push_back({dalice - dbin, i});
        bob.push_back({dbob - dbin, i});
    }
    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());

    Real ans;
    if(alice[0].second != bob[0].second){        
        ans = base + alice[0].first + Real(0) + bob[0].first;
    }
    else if(n == 1){
        ans = base + min(alice[0].first, bob[0].first);
    }
    else{
        ans = base + min(alice[0].first + bob[1].first, alice[1].first + bob[0].first);
    }
    ans = min({ans, base + alice[0].first, base + bob[0].first});
    printf("%.10f\n", double(ans));
    
    return 0;
}