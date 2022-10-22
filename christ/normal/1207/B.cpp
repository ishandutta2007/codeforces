#include<bits/stdc++.h>
using namespace std;
char _;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename t> void scan (t& x) {do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MN = 2e5+2;
int a[100][100], b[100][100];
vector<pii> ans;
int main () {
    int n,m;
    scan(n,m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scan(a[i][j]);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] == 1 && a[i+1][j] == 1 && a[i][j+1] == 1 && a[i+1][j+1] == 1) {
                ans.push_back({i,j});
                b[i][j] = b[i+1][j] = b[i][j+1] = b[i+1][j+1] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] != b[i][j])
                return !printf ("-1\n");
    printf ("%d\n",ans.size());
    for (pii p : ans) printf ("%d %d\n",p.first,p.second);

    return 0;
}