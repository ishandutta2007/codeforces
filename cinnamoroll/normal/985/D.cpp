// warm heart, wagging tail,and a smile just for you!
//
//                            
//                             
//                             
//                            
//                           
//                          
//                          
//                      
//                    
//                  
//                 
//                 
//                                    
//                              
//                            
//                       
//                          
//                          
//                           
//       
//     
//                            
//                        
//                
//   
//    
//      
//
#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

const int DEFAULT_SIZE = 1000;
struct Bigint : vector<long long> {
    static const long long BASE = 100000000;
    static const int BASE_DIGIT = 8;
    int sign;
    
    Bigint() : vector<long long>(1, 0) { sign = 1; }
    Bigint(long long num) : vector<long long>(DEFAULT_SIZE, 0) {
        sign = 1; if (num < 0) sign = -1, num = -num;
        (*this)[0] = num;
        (*this).normalize();
    }
    Bigint(int SIZE, long long num) : vector<long long>(SIZE, 0) {
        sign = 1; if (num < 0) sign = -1, num = -num;
        (*this)[0] = num;
        (*this).normalize();
    }
    
    Bigint& normalize() {
        long long c = 0;
        for (int i = 0;; ++i) {
            if (i >= (*this).size()) (*this).push_back(0);
            if ((*this)[i] < 0 && i+1 >= (*this).size()) (*this).push_back(0);
            while ((*this)[i] < 0) { (*this)[i+1] -= 1; (*this)[i] += BASE; }
            long long a = (*this)[i] + c;
            (*this)[i] = a % BASE;
            c = a / BASE;
            if (c == 0 && i == (*this).size()-1) break;
        }
        return (*this);
    }
    
    inline Bigint operator - () {
        Bigint res = (*this);
        bool allzero = true; for (int i = 0; i < res.size(); ++i) if (res[i] != 0) { allzero = false; break; }
        if (!allzero) res.sign *= -1;
        return res;
    }
    inline const Bigint& operator += (const Bigint &x);
    inline const Bigint& operator -= (const Bigint &x);
    inline const Bigint& operator *= (long long x);
    inline const Bigint& operator *= (const Bigint &x);
    inline const Bigint& operator /= (long long x);
    inline const Bigint& operator /= (const Bigint &x);
    inline const Bigint& operator %= (long long x);
    inline const Bigint& operator %= (const Bigint &x);
};
 
inline Bigint abs(const Bigint &x) {
    Bigint z = x;
    if (z.sign == -1) z.sign = 1;
    return z;
}
inline Bigint conv(const string &s) {
    Bigint res = 0;
    for (int i = 0; i < s.size(); ++i) {
        res += (long long)(s[i] - '0');
        if (i != s.size()-1) res *= 10;
    }
    return res;
}
ostream &operator << (ostream &os, const Bigint &x) {
    if (x.sign == -1) os << '-';
    int d = (int)x.size()-1;
    for (d = (int)x.size()-1; d >= 0; --d) if (x[d] > 0) break;
    if (d == -1) os << 0;
    else os << x[d];
    for (int i = d-1; i >= 0; --i) { os.width(Bigint::BASE_DIGIT); os.fill('0'); os << x[i]; }
    return os;
}
istream &operator >> (istream &is, Bigint &x) {
    string s; is >> s;
    x = conv(s);
    return is;
}
inline string tostr(const Bigint &x) {
    stringstream ss;
    ss << x;
    return ss.str();
}
bool operator > (Bigint x, Bigint y) {
    x.normalize(); y.normalize();
    if (x.sign > y.sign) return true;
    else if (x.sign < y.sign) return false;
    else {
        while (x.size() < y.size()) x.push_back(0);
        while (x.size() > y.size()) y.push_back(0);
        if (x.sign == 1) {
            for (int i = (int)x.size()-1; i >= 0; --i) if (x[i] != y[i]) return x[i] > y[i];
            return false;
        }
        else {
            for (int i = (int)x.size()-1; i >= 0; --i) if (x[i] != y[i]) return x[i] < y[i];
            return false;
        }
    }
}
bool operator < (Bigint x, Bigint y) { return y > x; }
bool operator <= (Bigint x, Bigint y) { return !(x > y); }
bool operator >= (Bigint x, Bigint y) { return !(y > x); }
bool operator != (Bigint x, Bigint y) { return (x > y) || (y > x); }
bool operator == (Bigint x, Bigint y) { return !(x > y) && !(y > x); }
 
inline Bigint operator + (Bigint x, Bigint y) {
    while (x.size() < y.size()) x.push_back(0);
    while (x.size() > y.size()) y.push_back(0);
    Bigint z((int)x.size(), 0);
    if (x.sign == y.sign) {
        z.sign = x.sign;
        for (int i = 0; i < x.size(); ++i) z[i] = x[i] + y[i];
    }
    else {
        if (x.sign == -1) swap(x, y);
        if (x >= -y) { z.sign = 1; for (int i = 0; i < x.size(); ++i) z[i] = x[i] - y[i]; }
        else { z.sign = -1; for (int i = 0; i < x.size(); ++i) z[i] = y[i] - x[i]; }
    }
    return z.normalize();
}
inline Bigint operator - (Bigint x, Bigint y) {
    y = -y;
    return x + y;
}
inline Bigint operator * (Bigint x, long long a) {
    Bigint z((int)x.size(), 0);
    if ( (x.sign == 1 && a >= 0) || (x.sign == -1 && a < 0) ) z.sign = 1;
    else z.sign = -1;
    if (a < 0) a = -a;
    for (int i = 0; i < x.size(); ++i) z[i] = x[i] * a;
    return z.normalize();
}
inline Bigint operator * (Bigint x, Bigint y) {
    int tx = (int)x.size()-1, ty = (int)y.size()-1;
    for (tx = (int)x.size()-1; tx >= 0; --tx) if (x[tx] > 0) break;
    for (ty = (int)y.size()-1; ty >= 0; --ty) if (y[ty] > 0) break;
    Bigint z(tx+ty+5, 0);
    if (x.sign == y.sign) z.sign = 1;
    else z.sign = -1;
    for (int i = 0; i <= tx; ++i) {
        for (int j = 0; j <= ty && i+j < z.size()-1; ++j) {
            long long val = x[i] * y[j] + z[i+j];
            z[i+j+1] += val / Bigint::BASE;
            z[i+j] = val % Bigint::BASE;
        }
    }
    return z.normalize();
}
pair<Bigint, long long> divmod(Bigint x, long long a) {
    long long c = 0, t = 0;
    for (int i = (int)x.size()-1; i >= 0; --i) {
        t = Bigint::BASE * c + x[i];
        x[i] = t / a;
        c = t % a;
    }
    x.normalize();
    return pair<Bigint, long long>(x, c);
}
Bigint operator / (Bigint x, long long a) {
    return divmod(x, a).first;
}
long long operator % (Bigint x, long long a) {
    return divmod(x, a).second;
}
pair<Bigint, Bigint> divmod(Bigint x, Bigint y) {
    Bigint zero = 0;
    if (abs(x) < abs(y)) return pair<Bigint, Bigint>(zero, x);
    Bigint ay = abs(y), q((int)x.size(), 0), r((int)y.size(), 0);
    int tx = (int)x.size()-1;
    for (tx = (int)x.size()-1; tx >= 0; --tx) if (x[tx] > 0) break;
    for (int i = tx; i >= 0; --i) {
        r = r * Bigint::BASE + x[i];
        long long lo = 0, hi = Bigint::BASE;
        if (r >= ay) {
            while (hi - lo > 1) {
                long long mid = (hi + lo) / 2;
                if (ay * mid > r) hi = mid;
                else lo = mid;
            }
            r = r - ay * lo;
        }
        q[i] = lo;
    }
    if (x.sign == -1 || y.sign == -1) q.sign = -1, r.sign = -1;
    return make_pair(q.normalize(), r.normalize());
}
Bigint operator / (Bigint x, Bigint y) {
    return divmod(x, y).first;
}
Bigint operator % (Bigint x, Bigint y) {
    return divmod(x, y).second;
}
inline Bigint pow(Bigint a, long long n) {
    Bigint res = 1;
    while (n > 0) { if (n & 1) { res = res * a; } a = a * a; n >>= 1; }
    return res;
}
Bigint sqrt(Bigint num) {
    Bigint lo = 1, hi = num;
    while (hi - lo > 1) {
        Bigint med = (lo + hi) / 2;
        if (med * med > num) hi = med;
        else lo = med;
    }
    return lo;
}
inline const Bigint& Bigint::operator += (const Bigint &x) {*this = *this + x; return *this;}
inline const Bigint& Bigint::operator -= (const Bigint &x) {*this = *this - x; return *this;}
inline const Bigint& Bigint::operator *= (long long x) {*this = *this * x; return *this;}
inline const Bigint& Bigint::operator *= (const Bigint &x) {*this = *this * x; return *this;}
inline const Bigint& Bigint::operator /= (long long x) {*this = *this / x; return *this;}
inline const Bigint& Bigint::operator /= (const Bigint &x) {*this = *this / x; return *this;}
inline const Bigint& Bigint::operator %= (long long x) {*this = *this % x; return *this;}
inline const Bigint& Bigint::operator %= (const Bigint &x) {*this = *this % x; return *this;}

Bigint n,h;
bool check(Bigint mid){
  if(mid <= h) return n <= mid*(mid+1)/2;
  else{
    Bigint x = (mid+h)/2;
    Bigint tmp = 0;
    tmp += (x+1)*x/2;
    tmp += (h+(h+mid-x-1))*(mid-x)/2;
    return tmp >= n;
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> h;

  Bigint ng = 0, ok = 1e18;
  while (abs(ng-ok)>1) {
    Bigint mid = (ng+ok)/2;
    (check(mid)?ok:ng) = mid;
  }

  cout << ok << endl;

  return 0;
}