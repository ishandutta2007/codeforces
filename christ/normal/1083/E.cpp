#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MN = 1e6+2;
struct Rect {
    int x,y;ll a;
    void read () {scanf ("%d%d%lld",&x,&y,&a);a-=x*1LL*y;}
} rects[MN];
struct Line {
    ll m,b; int which;
    ll get (ll x) {return m*x+b;}
    double intersect (Line &o) {return m==o.m?-1e18:(b-o.b)/double(o.m-m);}
} lines[MN];
int main () {
    int n;
    scanf ("%d",&n);
    for (int i = 1; i <= n; i++) rects[i].read();
    rects[0] = {0,0,0};
    sort(rects+1,rects+1+n,[](Rect a, Rect b) {return a.x < b.x;});
    lines[0] = {0,0,0}; int l = 0, r = 1;
    ll ans = 0,dp;
    for (int i = 1; i <= n; i++) {
   	 while (r-l>1&&lines[l].get(rects[i].y)<lines[l+1].get(rects[i].y))
   		 ++l;
   	 ans = max(ans,dp = lines[l].get(rects[i].y)-rects[i].a);
   	 Line nline = {-rects[i].x,dp,i};
   	 while (r-l>1 && nline.intersect(lines[r-1]) > lines[r-1].intersect(lines[r-2]))
   		 --r;
   	 lines[r++] = nline;
    }
    printf ("%lld\n",ans);
    return 0;
}
//dp[i] = max(dp[j]-y[i]*x[j]-a[i])