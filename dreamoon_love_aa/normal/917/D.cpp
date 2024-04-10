// modified by dreamoon
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
typedef vector<vector<int> > Mat;

const int MAXV = 101;
const int MAXE = MAXV * MAXV;
const int MOD = 1e9 + 7;

int inv(int x) {
    if(x == 1) return 1;
    return LL(MOD - MOD / x) * inv(MOD % x) % MOD;
}

int det(Mat &a, int n) {
    LL res = 1;
    for(int i = 1; i < n; ++i) {
        if(a[i][i] == 0) return 0;
        for(int j = i + 1; j < n; ++j) {
            LL t = LL(a[j][i]) * inv(a[i][i]) % MOD;
            for(int k = i; k < n; ++k) {
                a[j][k] -= (a[i][k] * t) % MOD;
                if(a[j][k] < 0) a[j][k] += MOD;
            }
        }
        res = (res * a[i][i]) % MOD;
    }
    return res;
}

void guass(Mat &a, int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            LL t = LL(a[j][i]) * inv(a[i][i]) % MOD;
            for(int k = i; k <= n; ++k) {
                a[j][k] -= (a[i][k] * t) % MOD;
                if(a[j][k] < 0) a[j][k] += MOD;
            }
        }
    }
    for(int i = n - 1; i >= 0; --i) {
        for(int j = i + 1; j < n; ++j) {
            a[i][n] -= (LL(a[i][j]) * a[j][n]) % MOD;
            if(a[i][n] < 0) a[i][n] += MOD;
        }
        a[i][n] = LL(a[i][n]) * inv(a[i][i]) % MOD;
    }
}

int la[MAXE], lb[MAXE], kind[MAXE];
int T, n, m, k;

int get_column(int a) {
    Mat mat(n, vector<int>(n));
    for(int i = 0; i < m; ++i) {
        int t = (kind[i] & 1) * a + (kind[i] >> 1);
        mat[la[i]][la[i]] += t;
        mat[lb[i]][lb[i]] += t;
        mat[la[i]][lb[i]] = mat[lb[i]][la[i]] = (t > 0 ? MOD - t : 0);
    }
    return det(mat, n);
}

void solve() {
    Mat mat(n, vector<int>(n + 1));
    for(int i = 0; i < n; ++i) {
        LL tmp = 1;
        for(int j = 0; j < n; ++j)
            mat[i][j] = tmp, tmp = (tmp * i) % MOD;
        mat[i][n] = get_column(i);
    }
    guass(mat, n);

    for(int i = 0; i < n; ++i) 
        printf("%d%c",mat[i][n]," \n"[i==n-1]);
}
int ker[101][101];
int main() {
    scanf("%d", &n);
    for(int i=0;i<n-1;i++){
        int x,y;
        scanf("%d%d",&x,&y);x--;y--;
        if(x>y)swap(x,y);
        la[i]=x;lb[i]=y;
        ker[x][y]=1;
        kind[i]=1;
    }
    m=n-1;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            if(!ker[i][j]){
                la[m]=i;
                lb[m]=j;
                kind[m]=2;
                m++;
            }
        }
    //for(int i=0;i<m;i++)printf("%d %d %d\n",la[i],lb[i],kind[i]);
    solve();
}