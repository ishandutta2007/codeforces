#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

struct Mat{
    int n, m;
    vector<vector<int>> mat;
    Mat(){}
    Mat(int _n, int _m){
        n = _n, m = _m;
        mat.assign(n, vector<int>(m, 0));
    }
    void id(){
        assert(n == m);
        for(int i = 0; i<n; i++)
            mat[i][i] = 1;
    }
    Mat operator * (const Mat& o) const{
        assert(m == o.n);
        Mat res = Mat(n, o.m);
        for(int i = 0; i<n; i++)
            for(int j = 0; j<o.m; j++)
                for(int k = 0; k<m; k++) inc(res.mat[i][j], mul(mat[i][k], o.mat[k][j]));
        return res;
    }
};

Mat bpow(Mat a, int b){
    assert(a.n == a.m);
    Mat res(a.n, a.n);
    res.id();
    while(b){
        if(b&1) res = res*a;
        a = a*a;
        b >>= 1;
    }
    return res;
}

int n, m, k, siz, ans;
Mat res, trans;

int hsh(int i, int j){
    return i*(1<<m)+j;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> m; siz = (k+1)*(1<<m);
    res = Mat(siz, 1);
    res.mat[hsh(0, 0)][0] = 1;
    trans = Mat(siz, siz);
    for(int i = 0; i<=k; i++){
        for(int j = 0; j<(1<<m); j++){
            if(j&1){
                if(!i) continue;
                inc(trans.mat[hsh(i, j)][hsh(i-1, j>>1)], 1+__builtin_popcount(j>>1));
                inc(trans.mat[hsh(i, j)][hsh(i-1, (j>>1)^(1<<(m-1)))], 2+__builtin_popcount(j>>1));
            } else{
                inc(trans.mat[hsh(i, j)][hsh(i, j>>1)], 1);
                inc(trans.mat[hsh(i, j)][hsh(i, (j>>1)^(1<<(m-1)))], 1);
            }
        }        
    }
    res = bpow(trans, n)*res;
    for(int i = 0; i<(1<<m); i++)
        inc(ans, res.mat[hsh(k, i)][0]);
    cout << ans << endl;
}