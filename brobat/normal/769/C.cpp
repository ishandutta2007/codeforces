#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 1010
#define MOD 1000000007

int n, m, k;
int Sx, Sy, Tx, Ty;
char arr[MAXN][MAXN];
int dist[MAXN][MAXN];
int grr[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}}; // DLRU
char brr[4] = {'D', 'L', 'R', 'U'};
vector<char> ans;

void bfs_dist() {
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    dist[Sx][Sy] = 0;
    q.push({Sx, Sy});
    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        forn(i, 0, 4) {
            int x = a + grr[i][0];
            int y = b + grr[i][1];
            if(x<0||x>=n||y<0||y>=m) continue;
            if(dist[x][y] == -1 && arr[x][y]!='*') {
                dist[x][y] = dist[a][b] + 1;
                q.push({x, y});
            }
        }
    }
}

void bfs_forward() {
    forn(i, 0, k/2) {
        forn(j, 0, 4) {
            int x = Tx + grr[j][0];
            int y = Ty + grr[j][1];
            if(x<0||x>=n||y<0||y>=m) continue;
            if(arr[x][y]!='*') {
                ans.push_back(brr[j]);
                Tx = x;
                Ty = y;
                break;
            }
        }
    }
}

// i = 0, k/2 = 5. i.e. dist[x][y] must be less than or equal to 4.
// i = 1, k/2 = 5, dist[x][y] ---> <= 3.
// i = 4, k/2 = 5, dist[x][y] ---> <= 0.

void bfs_backward() {
    forn(i, 0, k/2) {
        forn(j, 0, 4) {
            int x = Tx + grr[j][0];
            int y = Ty + grr[j][1];
            if(x<0||x>=n||y<0||y>=m) continue;
            if(arr[x][y]!='*' && dist[x][y]<(k/2-i)) {
                ans.push_back(brr[j]);
                Tx = x;
                Ty = y;
                break;
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    forn(i, 0, n) forn(j, 0, m) {
        cin >> arr[i][j];
        if(arr[i][j]=='X') {
            Sx = i;
            Sy = j;
            Tx = Sx;
            Ty = Sy;
        }
    }
    if(k%2) {
        cout << "IMPOSSIBLE";
        return;
    }
    bfs_dist();
    bfs_forward();
    bfs_backward();
    if(ans.size()==0) cout << "IMPOSSIBLE";
    else {
        for(auto i : ans) cout << i;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t; cin >> t; while(t--)
    {solve();}
    return 0;
}