#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, INF = 1e9;
vector<string> a, b;
vector<int> mods = {INF+7, INF+9, 27644437, 9369319}, prs = {223, 239, 569, 109};
bool matrix[2000][2000];
int pw(int e, int f, int g){
    if (f==0) return 1;
    if (f==1) return e%g;
    if (f%2){
        int rs = pw(e, f-1, g);
        return (e*rs)%g;
    }
    int rs = pw(e, f/2, g);
    return (rs*rs)%g;
}
void calculate(int MOD, int PRIME){
    vector<int> p;
    p.push_back(1);
    for (int i=0; i < 1e5; i++){
        p.push_back((p.back() * PRIME)%MOD);
    }
    vector<int> hashs;
    for (int i=0; i < n; i++){
        int H = 0;
        for (int j=0; j < m; j++){
            H += p[j] * (a[i][j] - 'a' + 1);
            H %= MOD;
        }
        hashs.push_back(H);
    }
    map<int, vector<int> > huj;
    for (int i=0; i < n-m+1; i++){
        int MD = 1, ns=0;
        for (int j=i; j < i+m; j++){
            ns += (MD * hashs[j]);
            ns %= MOD;
            MD *= p[m];
            MD %= MOD;
        }
        if (!huj.count(ns)){
            vector<int> th;
            th.push_back(i);
            huj[ns] = th;
        }
        huj[ns].push_back(i);
    }
    bool mx[n-m+1][n-m+1];
    for (int i=0; i < n-m+1; i++) for (int j=0; j < n-m+1; j++) mx[i][j] = false;
    vector<int> our;
    for (int i=0; i < m; i++){
        int H = 0;
        for (int j=0; j < m; j++){
            H += p[j] * (b[i][j] - 'a' + 1);
            H %= MOD;
        }
        our.push_back(H);
    }
    for (int i=0; i < n-m+1; i++){
        int MD = 1, ns=0;
        for (int j=0; j < m; j++){
            ns += (MD * our[j]);
            ns %= MOD;
            MD *= p[m];
            MD %= MOD;
        }
        if (huj.count(ns)){
            for (int p=0; p < huj[ns].size(); p++){
                mx[i][huj[ns][p]] = true;
            }
        }
        if (i==n-m) break;
        for (int j=0; j < m; j++){
            our[j] -= (b[j][i] - 'a' + 1) - MOD;
            our[j] %= MOD;
            int nm = pw(PRIME, MOD-2, MOD);
            our[j] *= nm;
            our[j] %= MOD;
            our[j] += p[m-1] * (b[j][i+m] - 'a' + 1);
            our[j] %= MOD;
        }
    }
    for (int i=0; i < n-m+1; i++) for (int j=0; j < n-m+1; j++) matrix[i][j] &= mx[i][j];
}
signed main() {
    cin >> n >> m;
    for (int i=0; i < n; i++){
        string s;
        cin >> s;
        a.push_back(s);
    }
    for (int i=0; i < m; i++){
        string s;
        cin >> s;
        b.push_back(s);
    }
    for (int i=0; i < n-m+1; i++) for (int j=0; j < n-m+1; j++) matrix[i][j] = true;
    for (int i=0; i < 4; i++){
        calculate(mods[i], prs[i]);
    }
    for (int i=0; i < n-m+1;i++) for (int j=0; j < n-m+1; j++){
        if (matrix[i][j]){
            cout << j+1 << " " << i+1 << endl;
            return 0;
        }
    }
    return 0;
}