#include<iostream>
using namespace std;
const int MAX_N = 4'000'000;
int a[MAX_N + 1];

int an[MAX_N + 1];
int tmp[MAX_N + 1];
int pos[MAX_N + 1];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char c[] = "DRUL";
string s[2000];
int N, M;
int get(int x, int y) {
    return M * x + y;
}
int get_dir(char cc) {
    for(int i = 0; i < 4; i++) {
        if(c[i] == cc) return i;
    }
    return -1;
}
void solve(){
    cin >> N >> M;
    int n;
    n = N * M;
    int output = 0;
    for(int i = 0; i < N; i++) {
        cin >> s[i];
        for(int j = 0; j < M; j++) {
            an[i * M + j] = pos[i * M + j] = 0;
            int dir = get_dir(s[i][j]);
            int nx = i + dx[dir];
            int ny = j + dy[dir];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) {
                a[get(i, j)] = get(i, j);
            } else {
                a[get(i, j)] = get(nx, ny);
            }
        }
    }
    int ma = -1;
    int an_x;
    int an_y;
    for(int i = 0; i < n; i++) {
        if(!an[i]) {
            int now = i;
            for(int j = 1; ; j++) {
                if(an[now]) {
                    for(int k = 1; k < j; k++) {
                        an[tmp[k]] = an[now] + j - k;
                    }
                    break;
                }
                if(!pos[now]) {
                    pos[now] = j;
                    tmp[j] = now;
                }else{
                    for(int k = 1; k < j; k++){
                        an[tmp[k]]=max(j - pos[now], j - k);
                    }
                    break;
                }
                now = a[now];
            }
        }
        if(an[i] > ma) {
            ma = an[i];
            an_x = i / M + 1;
            an_y = i % M + 1;
        }
    }
    cout << an_x << ' ' << an_y << ' ' << ma << endl;
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}