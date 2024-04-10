#include<bits/stdc++.h>
using namespace std;
char _;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename t> void scan (t& x) {do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MN = 2e5+2;
int main () {
    int t,b,p,f,h,c;
    scanf ("%d",&t);
    while (t--) {
        scan(b,p,f,h,c);
        int ans = 0;
        if (c > h) {
            int buy = min(b/2,f);
            ans += buy * c;
            b -= buy * 2;
            f -= buy;
            buy = min(b/2,p);
            ans += buy * h;
        } else {
            int buy = min(b/2,p);
            ans += buy * h;
            p -= buy;
            b -= buy * 2;
            buy = min(b/2,f);
            ans += buy * c;
        }
        printf ("%d\n",ans);
    }
    return 0;
}