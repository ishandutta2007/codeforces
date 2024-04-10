#include <bits/stdc++.h>
using namespace std;
 
#define lld long double
#define ll long long
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define ull unsigned long long
#define PII pair<int, int>
#define fi first
#define se second
#define mod 1000000007
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define fire ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fire2 cin.tie(0)->sync_with_stdio(false);
const int N = 200010;
int a[2][N];
int b[2][N];
int n;
void slove(){
    cin >> n;
    for(int i = 0; i < 2; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
    a[0][0] = -1;
    b[0][n] = b[1][n] = 0;
    for(int i = 0; i < 2; i++){
        for(int j = n - 1; j >= 0; j--){
            b[i][j] = max({a[i ^ 1][j] + 1, a[i][j] + 1 + 2 * (n - j) - 1, b[i][j + 1] + 1});
        }
    }
    int ans = inf;
    int cur = 0;
    for(int j = 0; j < n; j++){
        int k = j & 1;
        ans = min(ans, max(cur + 2 * (n - j) - 1, b[k][j]));
        cur = max(cur, a[k][j] + 1);
        cur++;
        cur = max(cur, a[k ^ 1][j] + 1);
        cur++;
    }
    cout << ans << '\n';
}
int main()
{
    fire;
    int t; cin >> t;
    while(t--) slove();
    return 0;
}