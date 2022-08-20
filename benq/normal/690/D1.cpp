#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

bool arr[100][100], visit[100][100];
int ans = 0, xdir[4] = {0,1,0,-1}, ydir[4] = {1,0,-1,0};

bool ok(int x, int y) {
    if (x<0 || x>99 || y<0 || y>99) return 0;
    if (!arr[x][y]) return 0;
    if (visit[x][y]) return 0;
    return 1;
}

void ff(int a, int b) {
    visit[a][b] = 1;
    F0R(i,4) if (ok(a+xdir[i],b+ydir[i])) ff(a+xdir[i],b+ydir[i]);
}

int main() {
    int R,C; cin >> R >> C;
    F0R(i,R) F0R(j,C) {
        char x; cin >> x;
        if (x == 'B') arr[j][i] = 1;
    }
    F0R(i,R) F0R(j,C) if (arr[j][i] && !visit[j][i]) {
        ff(j,i);
        ans++;
    }
    cout << ans;
}