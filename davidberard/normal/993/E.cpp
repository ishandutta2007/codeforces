#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const ld PI = 3.14159265358979323;

typedef complex<ld> Complex;
// Forward Transform - If using this for convolution, make sure to
// add n leading zeros to a vector of length n
vector<Complex> rfft(vector<Complex> a, int dir=1) {
  int n = a.size(); if (n == 1) return a;
  Complex wn = polar( (ld)1, dir*2*PI/n ), w = 1;
  vector<Complex> a_[2], y_[2], y(n);
  for (int i = 0; i < n; ++i) a_[i&1].push_back(a[i] / ld(dir>0 ? 1 : 2));
  y_[0] = rfft(a_[0], dir); y_[1] = rfft(a_[1], dir);
  for (int k = 0; k < n/2; ++k, w*=wn) {
    y[k] = y_[0][k] + w*y_[1][k];
    y[k + n/2] = y_[0][k] - w*y_[1][k];
  } return y; }
// Inverse Transform - this time you don't care about adding zeros
vector<Complex> ifft(vector<Complex> a) { return rfft(a, -1); }
// *** Fast Fourier Transform (Iterative) ***
// Reverse-bitmasking adder. rev_incr(a,n) returns REV(REV(a)+1)
inline int rev_incr(int a, int n) { int msk = n/2, cnt=0;
  while ( a&msk ) { cnt++; a<<=1; }
  a &= msk-1; a |= msk;
  while ( cnt-- ) a >>= 1;
  return a; }
// Compute in V the discrete fourier transform of v
// dir=1: forward transform, evaluates polynomial at complex roots of unity
// dir=-1: inverse transform, interpolates point-value form to coefficients
vector<Complex> FFT(vector<Complex> v, int dir=1) {
  Complex wm,w,u,t; int n = v.size(); vector<Complex> V(n);
  for (int k=0,a=0; k<n; ++k, a=rev_incr(a,n))
    V[a] = v[k] / ld(dir>0 ? 1 : n);
  for (int m=2; m<=n; m<<=1) {
    wm = polar( (ld)1, dir*2*PI/m );
    for (int k=0; k<n; k+=m) {
      w = 1;
      for (int j=0; j<m/2; ++j, w*=wm) {
        u = V[k + j];
        t = w * V[k + j + m/2];
        V[k + j] = u + t;
        V[k + j + m/2] = u - t;
      } } } return V; }
//! See problem 30-6 in CLRS for more details on the integer FFT
//! hints for integer version:
//! 440564289 and 1713844692 are inverses and 2^27th roots of 1 mod p=(15<<27)+1
//! Precompute inverses for integer FFT, otherwise it will be very slow.
// Multiply two polynomials sum_i a[i]x^i and sum_i b[i]x^i
vector<ld> convolution(vector<ld> a, vector<ld> b) {
  int sz = a.size()+b.size()-1;
  int n  = 1<<int(ceil(log2(sz)));
  vector<Complex> av(n,0), bv(n,0), cv;
  for (int i=0; i<a.size(); i++) av[i] = a[i];
  for (int i=0; i<b.size(); i++) bv[i] = b[i];
  cv = FFT(bv); bv = FFT(av);
  for (int i=0; i<n; i++) av[i] = bv[i]*cv[i];
  cv = FFT(av, -1);
  // cv is now the convolution of a and b: cv[k] = sum_(i+j=k) a[i]*b[j]
  vector<ld> c(sz);
  for (int i=0; i<sz; i++)
    c[i] = cv[i].real(); // if result should be int, use int(cv[i].real()+0.5)
  return c; }


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
    int N;
    int x;
    cin >> N >> x;
    vector<int> arr(N);
    for(int& ii : arr) cin >> ii;
    vector<int> pfx(N+1, 0);
    vector<int> amts(N+1, 0);
    amts[0]++;
    int last_of_type = -1;
    ll zero_ans = 0;
    for(int i=0;i<N;++i) {
        pfx[i+1] = pfx[i]+(arr[i]<x);
        amts[pfx[i+1]]++;
        if(pfx[i+1] != pfx[i]) {
            //if(last_of_type != -1) {
                ll diff = i-last_of_type;
                zero_ans += diff*(diff-1)/2;//(diff > 1 ? (diff)*(diff-1)/2 : 0);
            //}
            last_of_type = i;
        }
    }
        ll diff = N-last_of_type;
        zero_ans += /*diff*(diff+1)/2;*/(diff > 1 ? (diff)*(diff-1)/2 : 0);
        //zero_ans += (diff)*(diff+1)/2;
    int mx = pfx.back();
    vector<ld> me(mx+1, 0);
    for(int i=0;i<mx+1;++i) {
        me[i] = amts[i];
    }
    vector<ld> rev = me;
    reverse(rev.begin(), rev.end());
    vector<ld> ans_ld = convolution(me, rev);
    vector<ll> ans = vector<ll>(N+1, 0);
    for(int i=0;i<mx+1;++i) {
        ans[mx-i] = ans_ld[i]+0.5;
    }
    ans[0] = zero_ans;
    for(int i=mx+1;i<N+1;++i) {
        ans[i] = 0;
    }
    for(ll& ii : ans) {
        cout << ii << " ";
    }
    cout << endl;

    return 0;
}