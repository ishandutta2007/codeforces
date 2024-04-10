#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
char _;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef pair<ld,ld> line;
template <typename t> void scan (t& x) {do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MN = 2e5+2;
int main () {
    int n,a;
    scanf ("%d",&n);
    vector<int> pos,neg;
    int zeros = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d",&a);
        if (a < 0) neg.push_back(a);
        else if (a > 0) pos.push_back(a);
        else ++zeros;
    }
    ll ans = 0;
    for (int i : pos) {
        ans += abs(i-1);
    }
    for (int i : neg) {
        ans += abs(-1-i);
    }
    ans += zeros;
    if (neg.size()&1 && !zeros) ans += 2;
    printf ("%lld\n",ans);
    return 0;
}