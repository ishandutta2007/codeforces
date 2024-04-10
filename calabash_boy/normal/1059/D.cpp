#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 0x3f3f3f3f;

#define PB(x) push_back(x)
#define rep(i,l,r) for (ll i = l,_ = r;i< _;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0);
#define untie do{ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}while (0)

/************* header ******************/
const db eps = 1e-8;
int n;
struct Point{
    int x,y;
};
vector<Point> points(0);
bool check(db r){
    db L = -1e14-100;
    db R = 1e14+100;
    rep(i,0,n){
        db limit = pow(r,2) - pow(r-points[i].y,2);
        if (limit <=0)return false;
        limit = sqrt(limit);
        db ll = points[i].x - limit;
        db rr = points[i].x + limit;
        L = max(L,ll);
        R = min(R,rr);
        if (L>R+eps)return false;
    }
    return true;
}
int main(){
    cin>>n;
    bool pos = 0,neg = 0;
    rep(i,0,n){
        Point p;
        scanf("%d%d",&p.x,&p.y);
        pos |= p.y>0;
        neg |= p.y <0;
        p.y = abs(p.y);
        points.push_back(p);
    }
    if (pos&&neg)return puts("-1"),0;
    db l = 0;
    db r = 2e14+10;
    for (int i=0;i<100;i++){

        db mid = (l+r)/2;
        if (check(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    printf("%.9Lf\n",l);
    return 0;
}