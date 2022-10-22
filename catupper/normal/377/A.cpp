    #include <iostream>
    using namespace std;
    int n, m;
    char c[525][525];
    bool come[525][525];
    int xs[] ={0, -1, 0, 1}, ys[] = {1, 0, -1, 0};
    int dfs(int x, int y, int k){
    if(come[x][y])return 0;
    come[x][y] = true;
    if(c[x][y] == '#')return 0;
    if(k == 0)return 0;
    int res = k;
    for(int i = 0;i < 4;i++){
    int tx = x + xs[i], ty = y + ys[i];
    if(tx < 0 || tx >= n || ty < 0 || ty >= m)continue;
    res -= dfs(tx, ty, res);
    }
    if(res){
    c[x][y] = 'X';
    res--;
    }
    return k - res;
    }
     
    int main() {
    int k;
    cin >> n >> m >> k;
    int si, sj;
    for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
    cin >> c[i][j];
    if(c[i][j] == '.') si = i, sj = j;
    }
    }
    dfs(si, sj, k);
    for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
    cout << c[i][j];
    }
    cout << endl;
    }
    return 0;
    }