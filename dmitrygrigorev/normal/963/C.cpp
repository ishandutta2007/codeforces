#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Pr{int W; int H; int C;};
int gcd(int x, int y){
    if (y==0) return x;
    return gcd(y, x%y);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<int, int> a, b;
    vector<Pr> p;
    for (int i=0; i < n; i++){
        int W, H, C;
        cin >> W >> H >> C;
        int asz = a.size(), bsz = b.size();
        if (!a.count(W)) a[W] = asz;
        if (!b.count(H)) b[H] = bsz;
        p.push_back({W, H, C});
    }
    int P = a.size() * b.size();
    if (P != n){
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int> > matrix;
    for (int i=0; i < a.size(); i++){
        vector<int> help;
        for (int j=0; j < b.size(); j++) help.push_back(0);
        matrix.push_back(help);
    }
    for (int i=0; i < n; i++){
        matrix[a[p[i].W]][b[p[i].H]] = p[i].C;
    }
    for (int j=1; j < b.size(); j++){
        for (int i=1; i < a.size(); i++){
            int A = matrix[i-1][j-1], B = matrix[i-1][j], C = matrix[i][j-1], D = matrix[i][j];
            int G1 = gcd(A, B), G2 = gcd(C, D);
            A/=G1, B/=G1, C/=G2, D/=G2;
            if (A!=C || B != D){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    int ff = matrix[0][0];
    for (int i=1; i < b.size(); i++) ff = gcd(ff, matrix[0][i]);
    int th = 1, INF = 1e18;
    for (int i=0; i < b.size(); i++){
        for (int j=1; j < a.size(); j++){
            int rzmw = gcd(matrix[0][i], matrix[j][i]);
            int tt = matrix[0][i] / rzmw;
            int gg = gcd(th, tt);
            tt /= gg;
            if (INF / tt < th){
                cout << 0 << endl;
                return 0;
            }
            th *= tt;
        }
    }
    if (ff % th != 0){
        cout << 0 << endl;
        return 0;
    }
    ff /= th;
    int dl = 0;
    for (int i=1; i*i <= ff; i++){
        if (ff%i) continue;
        dl++;
        if (i*i!=ff) dl++;
    }
    cout << dl << endl;

}