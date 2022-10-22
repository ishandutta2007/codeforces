#include<bits/stdc++.h>
using namespace std;
char _;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename t> void scan (t& x) {do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MN = 3e5+2, MOD = 998244353;
int main () {
    int ans = 0;
    printf ("? ");
    for (int i = 0; i < 100; i++) printf ("%d ",i);
    printf ("\n");
    fflush(stdout);
    int ret;
    scanf ("%d",&ret);
    assert(ret != -1);
    for (int i = 13; i >= 7; i--) if (ret & (1 << i)) ans |= (1 << i);
    printf ("? ");
    for (int i = 1; i <= 100; i++) printf ("%d ",i<<7);
    printf ("\n");
    fflush(stdout);
    scanf ("%d",&ret);
    assert(ret != -1);
    for (int i = 0; i < 7; i++) if (ret & (1 << i)) ans |= (1 << i);
    printf ("! %d\n",ans);
    fflush(stdout);
    return 0;
}