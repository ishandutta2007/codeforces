#include <bits/stdc++.h>
using namespace std;

template <typename dataType>
struct Complex
{
    dataType re, im;

    Complex() : re(0), im(0) {}
    Complex (const dataType& a, const dataType& b) : re(a), im(b) {}
    Complex(const complex<dataType>& c) : re(c.real()), im(c.imag()) {}

    Complex& operator = (const complex<dataType>& c){
        this->re = c.real();
        this->im = c.imag();
        return *this;
    }

    dataType real() const{return this->re;}
    dataType imag() const{return this->im;}
    void real(dataType const& r){this->re = r;}
    void imag(dataType const& i){this->im = i;}
    void polar(const dataType& rho, const dataType& theta = 0){
        this->re = rho * cos(theta);
        this->im = rho * sin(theta);
    }
    Complex conj() const{return Complex(this->re, -this->im);}
    dataType norm() const{return sqrt(this->re * this->re + this->im * this->im);}
    dataType normSquared() const{return this->re * this->re + this->im * this->im;}
    Complex inverse() const{return this->conj() / this->normSquared();}
    Complex operator + (const Complex<dataType>& c) const{return Complex(this->re + c.re, this->im + c.im);}
    Complex& operator += (const Complex<dataType>& c){return *this = *this + c;}
    Complex operator - (const Complex<dataType>& c) const{return Complex(this->re - c.re, this->im - c.im);}
    Complex& operator -= (const Complex<dataType>& c){return *this = *this + c;}
    Complex operator * (const Complex<dataType>& c) const{return Complex(this->re * c.real() - this->im * c.imag(), this->re * c.imag() + this->im * c.real());}
    Complex& operator *= (const Complex<dataType>& c){return *this = *this * c;}
    Complex operator * (const dataType& c) const{return Complex(this->re * c, this->im * c);}
    Complex& operator *= (const dataType& c){return *this = *this * c;}
    Complex operator / (const Complex<dataType>& c) const{return *this * c.inverse();}
    Complex& operator /= (const Complex<dataType>& c){return *this = *this / c;}
    Complex operator / (const dataType& c) const{ return Complex(this->re / c, this->im / c);}
    Complex& operator /= (const dataType& c){ return *this = *this / c;}

    friend istream& operator >> (istream& stream, Complex& C){
        return stream >> C.re >> C.im;
    }
    friend ostream& operator << (ostream& stream, const Complex& C){
        return stream << "(" << C.re << "," << C.im << ")";
    }
};

using FFT_t = Complex<double>;

using ll = long long;
const ll mod = 1e9+7;

int gsig(ll n){
    return (n*(n-1)/2)%2==0;
}
#include <bits/stdc++.h>
using namespace std;
/*
    FFT implementation with double by dacin21
*/

int log2i(unsigned long long a){
    return __builtin_clzll(1) - __builtin_clzll(a);
}
vector<FFT_t > roots;
// pre-calculate complex roots, log(N) calls to sin/cos
void gen_roots(int N){
    if((int)roots.size()!=N){
        roots.clear();
        roots.resize(N);
        for(int i=0;i<N;++i){
            if((i&-i) == i){
                roots[i] = polar(1.0, 2.0*3.1415926535897932384626*i/N);
            } else {
                roots[i] = roots[i&-i] * roots[i-(i&-i)];
            }
        }
    }
}
void fft(FFT_t *a, int n, bool isInv = false){
    for (int i=1, j=0; i<n; ++i) {
        int m = n >> 1;
        for (; j>=m; m >>= 1)
            j -= m;
        j += m;
        if (i < j)
            swap(a[i], a[j]);
    }
    gen_roots(n);
    assert((int)roots.size()==n);
    for(int iter=1, sh=log2i(n)-1;iter<n;iter*=2, --sh){
        for(int x=0;x<n;x+=2*iter){
            for(int y=0;y<iter;++y){
                FFT_t ome = roots[y<<sh];
                if(isInv) ome = ome.conj();
                FFT_t v = a[x+y], w=a[x+y+iter];
                a[x+y] = v+ome*w;
                a[x+y+iter] = v-ome*w;
            }
        }
    }
}
const double rounding_error_cap = 0.2;
void poly_mul(vector<FFT_t > &a, vector<FFT_t > const&b){
    int logN = log2i(a.size());
    int N = 1<<logN;
    assert((int)a.size()==N && (int)b.size()==N);

    vector<FFT_t > convB = b;
    fft(a.data(), N);
    fft(convB.data(), N);
    for(int i=0;i<N;++i){
        a[i]*=convB[i];
    }
    fft(a.data(), N, true);
    for(int i=0;i<N;++i){
        a[i]/=N;
        //assert((fabs(a[i].real() - round(a[i].real())) < rounding_error_cap  || !(cerr << fabs(a[i].real() - round(a[i].real())) << endl)) && "Rounding error!");
        //assert((fabs(a[i].imag()) < rounding_error_cap  || !(cerr << fabs(a[i].imag()) << endl)) && "Rounding error!");
        a[i] = FFT_t (round(a[i].real()), 0.0);
    }
}



vector<ll> mul(vector<ll> const&a, vector<ll> const&b){
    vector<ll> ret(a.size()+b.size()-1, 0);
    for(size_t i=0;i<a.size();++i){
        for(size_t j=0;j<b.size();++j){
            ret[i+j]+=a[i]*b[j];
            ret[i+j]%=mod;
        }
    }
    return ret;
}

vector<FFT_t > gconv(vector<ll> const&v ,size_t n, bool re = true){
    if(re) n = 1ll<<(log2i(3*n)+1);
    vector<FFT_t > x(n);
    for(size_t i=0;i<v.size();++i){
        x[3*i].real(v[i]%30000);
        x[3*i+1].real(v[i]/30000);
    }
    fft(x.data(), n, false);
    return x;
}
vector<ll> cmul(vector<FFT_t > &c1, vector<FFT_t > const&c2, size_t siz){
    assert(c1.size() == c2.size());
    int N = c1.size();
    for(int i=0;i<N;++i){
        c1[i]*=c2[i];
    }
    fft(c1.data(), N, true);
    for(int i=0;i<N;++i){
        c1[i]/=N;
        c1[i] = FFT_t (((ll)round(c1[i].real()))%mod, 0.0);
    }
    vector<ll>ret(siz, 0);
    for(size_t i=0;i<siz;++i){
        ret[i]=(((ll)c1[3*i].real()) + ((ll)c1[3*i+1].real())/*%mod*/*30000ll + ((ll)c1[3*i+2].real())/*%mod*/*30000ll*30000ll)%mod;
    }
    return ret;
}

vector<ll> me2(vector<ll> const&a, vector<ll> const&po, vector<ll> const&neg){
    vector<ll> x = a;
    vector<ll> y = a;
    for(int i=0;i<(int)a.size();++i){
        if((i&1)) x[i]=0;
        else y[i]=0;
    }
    x = mul(x, po);
    y = mul(y, neg);
    for(int i=0;i<(int)x.size();++i){
        x[i]+=y[i];
        if(x[i]>=mod) x[i]-=mod;
    }
    return x;
}

vector<ll> me(vector<ll> const&a, vector<FFT_t> const&po, vector<FFT_t> const&neg, size_t siz){
    vector<ll> x = a;
    vector<ll> y = a;
    for(int i=0;i<(int)a.size();++i){
        if((i&1)) x[i]=0;
        else y[i]=0;
    }
    auto t = gconv(x, po.size(), false);
    x = cmul(t, po, siz);
    t = gconv(y, neg.size(), false);
    y = cmul(t, neg, siz);
    for(int i=0;i<(int)x.size();++i){
        x[i]+=y[i];
        if(x[i]>=mod) x[i]-=mod;
    }
    return x;
}

struct Triag{
    ll n;
    vector<ll> pos;
    vector<ll> neg;
    vector<FFT_t > pconv, nconv;
    Triag(){
        n=1;
        pos = {1, 1};
        neg = {1, mod-1};
    }
    Triag operator+(Triag &o)const{
        Triag ret;
        ret.n = n+o.n;
        int sig = gsig(o.n+n+1)^gsig(n+1);
        if(n<=16||o.n<=16){
            if(!sig){
                ret.pos = me2(pos, o.pos, o.neg);
                ret.neg = me2(neg, o.neg, o.pos);
            } else {
                ret.pos = me2(neg, o.pos, o.neg);
                ret.neg = me2(pos, o.neg, o.pos);
            }
            return ret;
        }
        size_t s = pos.size()+o.pos.size();
        if(o.pconv.size() < 3*s) o.pconv = gconv(o.pos, s);
        if(o.nconv.size() < 3*s) o.nconv = gconv(o.neg, s);
        if(!sig){
            ret.pos = me(pos, o.pconv, o.nconv, ret.n+1);
            ret.neg = me(neg, o.nconv, o.pconv, ret.n+1);
        } else {
            ret.pos = me(neg, o.pconv, o.nconv, ret.n+1);
            ret.neg = me(pos, o.nconv, o.pconv, ret.n+1);
        }
        return ret;
    }
    Triag& operator++(){
        //self-merge with 10 FFTs
        vector<ll> tmp(n+1);
        for(size_t i=0;i<tmp.size();i+=1){ tmp[i] = (i&1)?0:pos[i];}
        auto lpos = gconv(tmp, 2*n+2, true);
        ll m = lpos.size();
        for(size_t i=0;i<tmp.size();i+=1){ tmp[i] = (i&1)==0?0:pos[i];}
        auto rpos = gconv(tmp, m, false);
        auto mpos = rpos;
        for(size_t i=0;i<mpos.size();++i) mpos[i]+=lpos[i];

        for(size_t i=0;i<tmp.size();i+=1){ tmp[i] = (i&1)?0:neg[i];}
        auto lneg = gconv(tmp, m, false);
        for(size_t i=0;i<tmp.size();i+=1){ tmp[i] = (i&1)==0?0:neg[i];}
        auto rneg = gconv(tmp, m, false);
        auto mneg = rneg;
        for(size_t i=0;i<mpos.size();++i) mneg[i]+=lneg[i];

        //mpos = gconv(pos, m, false);
        //mneg = gconv(neg, m, false);

        int sig = gsig(2*n+1)^gsig(n+1);
        if(!sig){
            auto e = cmul(lpos, mpos, 2*n+1);
            pos = cmul(rpos, mneg, 2*n+1);
            for(size_t i=0;i<pos.size();++i) {
                pos[i]+=e[i];
                if(pos[i]>=mod) pos[i]-=mod;
            }
            e = cmul(lneg, mneg, 2*n+1);
            neg = cmul(rneg, mpos, 2*n+1);
            for(size_t i=0;i<pos.size();++i) {
                neg[i]+=e[i];
                if(neg[i]>=mod) neg[i]-=mod;
            }
            //ret.pos = me(pos, o.pconv, o.nconv, ret.n+1);
            //ret.neg = me(neg, o.nconv, o.pconv, ret.n+1);
        } else {
            auto e = cmul(lneg, mpos, 2*n+1);
            pos = cmul(rneg, mneg, 2*n+1);
            for(size_t i=0;i<pos.size();++i) {
                pos[i]+=e[i];
                if(pos[i]>=mod) pos[i]-=mod;
            }
            e = cmul(lpos, mneg, 2*n+1);
            neg = cmul(rpos, mpos, 2*n+1);
            for(size_t i=0;i<pos.size();++i) {
                neg[i]+=e[i];
                if(neg[i]>=mod) neg[i]-=mod;
            }
            //ret.pos = me(neg, o.pconv, o.nconv, ret.n+1);
            //ret.neg = me(pos, o.nconv, o.pconv, ret.n+1);
        }

        n = n+n;

        return *this;
    }
};

int main()
{
    #ifdef LOCAL_RUN
    freopen("inB.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    #endif // LOCAL_RUN
    cin.tie(0); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n==1){
        ll a;
        cin >> a;
        cout << a %mod;
        return 0;
    }
    Triag tr, e;
    Triag f = e+e;
    tr.n=0;
    tr.pos = tr.neg = {1};
    int exp = n-1;

    for(int i = 1<<25;i>1;i>>=1){
        if(2*i<=exp) ++tr;//tr = tr+tr;
        if(exp&i){
            tr = f+tr;
        }
    }
	if(exp&1) tr = tr+e;
    ll ans = 0, a;
    ll modmod = mod*mod;
    for(int i=0;i<n;++i){
        cin >> a;
        ans+=a*tr.pos[i];
        if(ans>modmod) ans-=modmod;
    }
    ans%=mod;
    cout << ans << "\n";



    return 0;
}