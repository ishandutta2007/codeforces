#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> ii;
typedef vector<ld> vd;
typedef vector<vd> vvd;

const int maxn = 128;

vvd operator * (const vvd &A, const vvd &B){
    vvd res(maxn, vd(maxn, 0));
    
    for (int i = 0; i < maxn; ++i){
        for (int j = 0; j < maxn; ++j){
            for (int k = 0; k < maxn; ++k){
                res[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    return res;
}

vvd mpow(const vvd &A, int n){
    if (n == 1) return A;
    vvd tmp = mpow(A*A, n/2);
    if (n % 2) tmp = tmp*A;
    return tmp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vd prb(maxn, 0);
    for (int i = 0;i <= x; ++i) cin >> prb[i];
    vvd mat(maxn, vd(maxn, 0));
    for (int i = 0; i < maxn; ++i){
        for (int j =0; j < maxn; ++j){
            mat[i][j] = prb[i xor j];
            //cerr << mat[i][j] << " ";
        }
        //cerr << endl;
    }
    
    vvd res = mpow(mat, n);
    cout.setf(ios::fixed);
    cout.precision(15);
    cout << 1-res[0][0] << endl;
}