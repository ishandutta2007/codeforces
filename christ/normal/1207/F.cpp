#include<bits/stdc++.h>
using namespace std;
char _;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename t> void scan (t& x) {do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MN = 5e5+2, MOD = 998244353, SQ = 400;
int ans[SQ][SQ];
int arr[MN];
int main () {
    int q,t,a,b;
    scan(q);
    while (q--) {
        scanf ("%d %d %d",&t,&a,&b);
        if (t == 1) {
            for (int i = 1; i < SQ; i++) ans[i][a%i] += b;
            arr[a] += b;
        } else {
            if (a < SQ) {
                printf ("%d\n",ans[a][b]);
            } else {
                int ans = 0;
                for (int i = b; i <= 500000; i += a) ans += arr[i];
                printf ("%d\n",ans);
            }
        }
    }
    return 0;
}