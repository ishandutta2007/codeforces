#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int MN = 1e6+2;
vector<vector<int>> bit;
vector<vector<char>> grid, fin;
int n,m;
char s[MN];
void inc (int x, int y) {
    for (;x<=n;x+=x&-x)
        for (int i=y;i<=m;i+=i&-i)
            ++bit[x][i];
}
int query (int x, int y) {
    int ret = 0;
    for(;x;x^=x&-x)
        for (int i=y;i;i^=i&-i)
            ret += bit[x][i];
    return ret;
}
bool full (int x, int y, int x2, int y2) {
    if (x2 > n || y2 > m || x < 1 || y < 1) return 0;
    return (query(x2,y2) - query(x-1,y2) - query(x2,y-1) + query(x-1,y-1)) == (x2-x+1)*(y2-y+1);
}
bool left (int x, int y) {
    return y == 1 || grid[x][y-1] == '.';
}
bool right (int x, int y) {
    return y == m || grid[x][y+1] == '.';
}
bool up (int x, int y) {
    return x == 1 || grid[x-1][y] == '.';
}
bool down (int x, int y) {
    return x == n || grid[x+1][y] == '.'; 
}
bool check (int t) {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (grid[i][j] == 'X'){
        if (left(i,j) && down(i,j) && !full(i-t*2,j,i,j+t*2)) return 0;
        if (left(i,j) && up(i,j) && !full(i,j,i+t*2,j+t*2)) return 0;
        if (right(i,j) && up(i,j) && !full(i,j-t*2,i+t*2,j)) return 0;
        if (right(i,j) && down(i,j) && !full(i-t*2,j-t*2,i,j)) return 0;
        if (left(i,j) && !full(i,j,i,j+t*2)) return 0;
        if (up(i,j) && !full(i,j,i+t*2,j)) return 0;
        if (right(i,j) && !full(i,j-t*2,i,j)) return 0;
        if (down(i,j) && !full(i-t*2,j,i,j)) return 0;
    }
    return 1;
}
void solve (int t) {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (grid[i][j] == 'X') {
        if (full(i-t*2,j,i,j+t*2)) fin[i-t][j+t] = 'X';
        if (full(i,j,i+t*2,j+t*2)) fin[i+t][j+t] = 'X';
        if (full(i,j-t*2,i+t*2,j)) fin[i+t][j-t] = 'X';
        if (full(i-t*2,j-t*2,i,j)) fin[i-t][j-t] = 'X';
    }
}
int main () {
    scanf ("%d %d",&n,&m);
    bit.resize(n+1,vector<int>(m+1));
    grid.resize(n+1,vector<char>(m+1));
    fin.resize(n+1,vector<char>(m+1));
    for (int i = 1; i <= n; i++) {
        scanf ("%s",s);
        for (int j = 1; j <= m; j++) if ((grid[i][j] = s[j-1]) == 'X') inc(i,j);
    }
    int low = 0, high = 10000, mid, ans = -1;
    while (low <= high) {
        mid = low+high>>1;
        if (check(mid)) low = mid+1, ans = mid;
        else high = mid-1; 
    }
    for (int i = 1; i <= n; i++) fill(fin[i].begin(),fin[i].end(),'.');
    solve(ans);
    printf ("%d\n",ans);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) putchar(fin[i][j]);
        putchar(10);
    }
    return 0;
}