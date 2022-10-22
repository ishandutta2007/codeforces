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
    int mx = INT_MIN, mx2 = mx;
    for (int i = 0; i < n; i++) {
        scanf ("%d",&a);
        mx = max(mx,a);
    }
    int m;
    scanf ("%d",&m);
    for (int i = 0; i < m; i++) {
        scanf ("%d",&a);
        mx2 = max(mx2,a);
    }
    printf ("%d %d\n",mx,mx2);
    return 0;
}