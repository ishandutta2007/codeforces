#include <bits/stdc++.h>
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using ll=long long;
using pii=pair<int, int>;
//#define int ll

int aray[1505][1505];
int N, M;
bool ok;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

inline int hsh(unsigned int r, unsigned int c) {
    return ((r*7) ^ (c*3)) % (N*M + 103) + 1;
}

void dfs(int r, int c) {
    if(ok) return;
    int R = ((r % N) + N) % N, C = ((c % M) + M) % M;
    if(aray[R][C] == 0 || aray[R][C] == hsh(r, c)) return;
    if(aray[R][C] > 0) {
        ok = true;
        return;
    }
    aray[R][C] = hsh(r, c);
    rep(d, 4)
        dfs(r+dx[d], c+dy[d]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M;
	int sr, sc;
	rep(i, N) {
	    rep(j, M) {
	        char c; cin >> c;
	        if(c != '#') aray[i][j] = -1;
	        if(c == 'S') {
	            sr = i;
	            sc = j;
	        }
	    }
	}
	dfs(sr, sc);
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}