/**
 * Author: Ulf Lundstrom
 * Date: 2009-08-03
 * License: CC0
 * Source: My head
 * Description: Basic operations on square matrices.
 * Usage: Matrix<int, 3> A;
 *  A.d = {{{{1,2,3}}, {{4,5,6}}, {{7,8,9}}}};
 *  vector<int> vec = {1,2,3};
 *  vec = (A^N) * vec;
 * Status: tested
 */

#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define sq(a) ((a)*(a))
 
#define MOO(i,a,b) for (int i=a; i<b; i++)
#define M00(i,a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define per(i,a,b) for (int i = (b)-1; i >= a; i--)
#define rep(i,a,b) for (int i=a; i<b; i++)
 
#define FOR(i,a,b) for (int i=a; i<b; i++)
#define F0R(i,a) for (int i=0; i<a; i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; i--)
#define R0F(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << endl, 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << endl;
#define _<< " _ " <<
 
#define int long long
 
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
 
typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<vector<int>> vvi;
 
const ld PI = acos(-1.0);
const ld EPS = 1e-7;
const int MOD = 998244353;
const int n = 105;

template<class T, int N> struct Matrix {
	typedef Matrix M;
	array<array<T, N>, N> d{};
	M operator*(const M& m) const {
		M a;
		rep(i,0,N) rep(j,0,N)
			rep(k,0,N) {
			    a.d[i][j] += d[i][k]*m.d[k][j];
			    a.d[i][j] %= MOD;
			    }
		return a;
	}
	
	M operator^(int p) const {
		assert(p >= 0);
		M a, b(*this);
		rep(i,0,N) a.d[i][i] = 1;
		while (p) {
			if (p&1) a = a*b;
			b = b*b;
			p >>= 1;
		}
		return a;
	}
};

int32_t main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int nn, m, k;
    cin >> nn >> m >> k;
    
    Matrix<int, n> M;
    Matrix<int, n> nD;
    
    Matrix<int, 2 * n> trans;
    Matrix<int, 2 * n> vec;
    
    F0R(i, m){
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        
        nD.d[u][u] -= 1;
        nD.d[v][v] -= 1;
        M.d[u][v] += 1;
        M.d[v][u] += 1;
    }
    
    Matrix<int, n> M2 = M * M;
    
    F0R(i, n){
        F0R(j, n){
            trans.d[i][j] = M.d[i][j];
            
            vec.d[i + n][j] = M.d[i][j];
            vec.d[i][j] = M2.d[i][j];
        }
        
        trans.d[i][i + n] = 1 + nD.d[i][i];
        trans.d[i + n][i] = 1;
        
        vec.d[i][i] += nD.d[i][i];
    }
    
    Matrix<int, n + n> fM = (trans ^ (k - 1)) * vec;
    
    /*F0R(i, 8){
        F0R(j, 4){
            cout << fM.d[i][j] << " ";
        }
        cout << '\n';
    }*/
    
    int out;
    
    F0R(i, n){
        out += fM.d[i + n][i];
        out %= MOD;
        out += MOD;
    }
    
    cout << (out % MOD);
}