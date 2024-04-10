#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <bitset>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define rep(i, n) for(int i=0;i<n;i++)
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define szz(x) (int)(x).size()
#define Fi first
#define Se second

const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f;
const ll MOD = 1000000007;
const int IT_MAX = 1 << 17;

const int MX = 1000005;

#include <complex>
namespace FFT{
    // blog.myungwoo.kr/54
    typedef complex<double> base;
    typedef long long ll;

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

    const double C_PI = acos(-1);

    void fft(vector <base> &a, bool invert){
        int n = sz(a);
        for(int i=0,j=0;i<n;++i) {
            if(i>j) swap(a[i],a[j]);
            for(int k=n>>1;(j^=k)<k;k>>=1);
        }
        for (int len=2;len<=n;len<<=1){
            double ang = 2*C_PI/len*(invert?-1:1);
            base wlen(cos(ang), sin(ang));
            for (int i=0;i<n;i+=len){
                base w(1);
                for (int j=0;j<len/2;j++){
                    if((j & 511) == 511)w = base(cos(ang * j), sin(ang * j));	//     . cos, sin     
                    base u = a[i+j], v = a[i+j+len/2]*w;
                    a[i+j] = u+v;
                    a[i+j+len/2] = u-v;
                    w *= wlen;
                }
            }
        }
        if (invert){
            for (int i=0;i<n;i++) a[i] /= n;
        }
    }

    void multiply(const vector<int> &a,const vector<int> &b,vector<int> &res, const int MOD){
        vector <base> fa(all(a)), fb(all(b));
        int n = 1;
        while (n < max(sz(a),sz(b))) n <<= 1; n <<= 1;
        fa.resize(n); fb.resize(n);
        fft(fa,false); fft(fb,false);
        for (int i=0;i<n;i++) fa[i] *= fb[i];
        fft(fa,true);
        res.resize(n);
        for (int i=0;i<n;i++) res[i] = ((ll)(fa[i].real()+(fa[i].real()>0?0.5:-0.5))) % MOD;
    }

    void multiply_with_modulo(const vector<int> &a,const vector<int> &b,vector<int> &res, const int MOD){
        int n = 1;
        while (n < max(sz(a),sz(b))) n <<= 1; n <<= 1;
        vector <base> A(n), B(n);
        int L_BLOCK = 15;	//2^L_BLOCK ~= sqrt(MOD).
        for(int i=0;i<n;i++) A[i] = (i < sz(a) ? base(a[i] & ((1<<L_BLOCK)-1), a[i] >> L_BLOCK) : base(0));
        for(int i=0;i<n;i++) B[i] = (i < sz(b) ? base(b[i] & ((1<<L_BLOCK)-1), b[i] >> L_BLOCK) : base(0));
        fft(A, false); fft(B, false);
        vector <base> f1(n), f2(n), f3(n), f4(n);
        for(int i=0;i<n;i++) {
            int j=(n-i)&(n-1);
            f2[i]=(A[i]+conj(A[j]))*base(0.5,0);
            f1[i]=(A[i]-conj(A[j]))*base(0,-0.5);
            f4[i]=(B[i]+conj(B[j]))*base(0.5,0);
            f3[i]=(B[i]-conj(B[j]))*base(0,-0.5);
        }
        for(int i=0;i<n;i++) {
            A[i]=f1[i]*f3[i]+f1[i]*f4[i]*base(0,1);
            B[i]=f2[i]*f4[i]*base(0,1)+f2[i]*f3[i];
        }
        fft(A, true); fft(B, true);
        res.resize(n);
        for(int i=0;i<n;i++) {
            ll g1=(ll)(A[i].real()+0.5) % MOD;	//A[i].real > 0  .
            ll g2=(ll)(A[i].imag()+0.5) % MOD;
            ll g3=(ll)(B[i].real()+0.5) % MOD;
            ll g4=(ll)(B[i].imag()+0.5) % MOD;
            res[i] = (g4 + ((g2+g3)<<L_BLOCK) + (g1<<(L_BLOCK<<1))) % MOD;
        }
    }

    void multiply_big(const vector<int> &a,const vector<int> &b, vector <ll> &res){
        //      
        //  long long  
        int n = 1;
        while (n < max(sz(a),sz(b))) n <<= 1; n <<= 1;
        vector <base> A(n), B(n);
        int L_BLOCK = 10;
        for(int i=0;i<n;i++) A[i] = (i < sz(a) ? base(a[i] & ((1<<L_BLOCK)-1), a[i] >> L_BLOCK) : base(0));
        for(int i=0;i<n;i++) B[i] = (i < sz(b) ? base(b[i] & ((1<<L_BLOCK)-1), b[i] >> L_BLOCK) : base(0));
        fft(A, false); fft(B, false);
        vector <base> f1(n), f2(n), f3(n), f4(n);
        for(int i=0;i<n;i++) {
            int j=(n-i)&(n-1);
            f2[i]=(A[i]+conj(A[j]))*base(0.5,0);
            f1[i]=(A[i]-conj(A[j]))*base(0,-0.5);
            f4[i]=(B[i]+conj(B[j]))*base(0.5,0);
            f3[i]=(B[i]-conj(B[j]))*base(0,-0.5);
        }
        for(int i=0;i<n;i++) {
            A[i]=f1[i]*f3[i]+f1[i]*f4[i]*base(0,1);
            B[i]=f2[i]*f4[i]*base(0,1)+f2[i]*f3[i];
        }
        fft(A, true); fft(B, true);
        res.resize(n);
        for(int i=0;i<n;i++) {
            ll g1=(ll)(A[i].real()+0.5);
            ll g2=(ll)(A[i].imag()+0.5);
            ll g3=(ll)(B[i].real()+0.5);
            ll g4=(ll)(B[i].imag()+0.5);
            res[i] = (g4 + ((g2+g3)<<(L_BLOCK)) + (g1<<(L_BLOCK<<1)));
        }
    }
}

int n, m, k;
vector <int> X[200020];
int A[200020];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1;i<=n;i++) {
        int x; scanf("%d", &x); --x;
        A[x]++;
    }
    for(int i=0;i<m;i++) {
        X[i].resize(A[i] + 1);
        rep(j, A[i] + 1) X[i][j] = 1;
    }
    for(int i=1;i<m;i*=2) {
        for(int j=0;i+j<m;j+=2*i) {
            FFT::multiply(X[j], X[j+i], X[j], 1009);
            while(szz(X[j]) > 1 && X[j].back() == 0) X[j].pop_back();
        }
    }
    printf("%d\n", szz(X[0]) < k+1 ? 0 : X[0][k]);
    return 0;
}