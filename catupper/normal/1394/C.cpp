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
#include<cstring>
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

struct Hexagon{
    int xl, xr;
    int yl, yr;
    int xyl, xyr;
    Hexagon(int xl = -INF, int xr=INF, int yl=-INF, int yr=INF, int xyl=-INF, int xyr=INF):
        xl(xl), xr(xr), yl(yl), yr(yr), xyl(xyl), xyr(xyr){}
};

Hexagon intersection(Hexagon a, Hexagon b){
    return Hexagon(max(a.xl, b.xl), min(a.xr, b.xr), max(a.yl, b.yl), min(a.yr, b.yr), max(a.xyl, b.xyl), min(a.xyr, b.xyr));
}

vector<P> points;
char s[550000];
P ok_str;
bool ok(int t){
    Hexagon hex;
    for(auto p:points){
        int x = p.first, y = p.second;
        auto tmp = Hexagon(x - t, x + t, y - t, y + t, x - y - t, x - y + t);
        hex = intersection(tmp, hex);
    }
    if(hex.xl > hex.xr)return false;
    if(hex.yl > hex.yr)return false;
    if(hex.xyl > hex.xyr)return false;
    int xyl = hex.xl - hex.yr;
    int xyr = hex.xr - hex.yl;
    if(xyr < hex.xyl || hex.xyr < xyl)return false;
    int xy = min(xyr, hex.xyr);
    int xr = xy + hex.yr;
    int x = min(xr, hex.xr);
    int y = x - xy;
    ok_str = {x, y};
    return true;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        scanf("%s", s);
        int bcnt=0,ncnt= 0;
        int l = strlen(s);
        for(int i = 0;i < l;i++){
            if(s[i] == 'B')bcnt++;
            else ncnt++;
        }
        points.emplace_back(ncnt, bcnt);
    }
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    int bottom = 0, top = 1000000;
    if(points.size() == 1)top = 0;
    while(top - bottom > 1){
        int mid = (top + bottom) / 2;
        if(ok(mid))top = mid;
        else bottom = mid;                       
    }
    ok(top);
    cout << top << endl;
    for(int i = 0;i < ok_str.first;i++)cout << 'N';
    for(int i = 0;i < ok_str.second;i++)cout << 'B';
    cout << endl;
    return 0;
}