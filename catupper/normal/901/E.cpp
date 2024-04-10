#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<complex>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef complex<long double> CP;

vector<CP> FFT2POW(vector<CP> &x, CP w){
    if(x.size() == 1)return x;
    Int n = x.size();
    vector<CP> even;
    vector<CP> odd;
    for(Int i = 0;i < n;i++){
        if(i % 2 == 0)even.push_back(x[i]);
        else odd.push_back(x[i]);
    }
    even = FFT2POW(even, w * w);
    odd = FFT2POW(odd, w * w);
    vector<CP> res(n);
    CP w_i = 1;
    for(Int i = 0;i < n;i++){
        res[i] = even[i % even.size()] + w_i * odd[i % odd.size()];
        w_i *= w;
    }
    return res;
}

CP primitive_root(Int n){
    double theta = 2 * PI/ n;
    return CP(cos(theta), sin(theta));
}

vector<CP> INV_FFT(vector<CP>&);

vector<CP> FFT(vector<CP> &a){
    Int n = a.size();
    if((n & -n) == n)return FFT2POW(a, primitive_root(n));
    
    Int m = 1;
    while(m < 2*n)m <<= 1;
    
    CP w = primitive_root(2 * n);
    vector<CP> ws(2*n+1,1);
    for(Int i = 1;i <= 2*n;i++)ws[i] = ws[i-1] * w;

    vector<CP> winv(m, 0);
    vector<CP> aw(m, 0);
    for(Int i = 0;i < n;i++){
        Int p = -(i*i) % (2*n) + 2*n;
        winv[n-i] = winv[n+i] = ws[p];
        aw[i] = a[i] * ws[i*i%(2*n)];
    }
    auto WINV = FFT(winv);
    auto AW = FFT(aw);
    for(Int i = 0;i < m;i++)WINV[i] *= AW[i];
    auto c = INV_FFT(WINV);
    vector<CP> A(n);
    for(Int i = 0;i < n;i++){
        A[i] = ws[i*i%(2*n)] * c[n+i]; 
    }
    return A;    
}

vector<CP> INV_FFT(vector<CP>& x){
    reverse(x.begin() + 1, x.end());
    auto res = FFT(x);
    for(auto &elem:res)elem /= res.size();
    return res;
}

int main(){
    Int n;
    cin >> n;
    vector<CP> b(n), c(n);
    vector<CP> db(n), dc(n);
    for(Int i = 0;i < n;i++)cin >> b[i];
    for(Int i = 0;i < n;i++)cin >> c[i];
    for(Int i = 0;i < n;i++){
        db[i] = b[i] - b[(n+i-1)%n];
        dc[i] = (c[(i+1) % n] - c[i]) / (long double)2.;
    }
    reverse(db.begin()+1, db.end());
    auto DB = FFT(db);
    auto DC = FFT(dc);
    vector<CP> A(n,0);
    for(Int i = 1;i < n;i++)A[i] = DC[i] / DB[i];
    auto a_c = INV_FFT(A);
    vector<Int> a_diff(n,0);
    for(Int i = 1;i < n;i++){
        a_diff[i] = Int(a_c[i].real() - a_c[0].real() + 30000 + 0.1) - 30000;
//        cout << a_diff[i] << " ";
    }cout << endl;
    double a_ = n, b_ = 0, c_ = -Int(c[0].real());
    for(Int i = 0;i < n;i++){
        Int b_a = Int(b[i].real()) - a_diff[i];
        b_ += -2* b_a;
        c_ += b_a*b_a;
    }
    vector<Int> oks;
    for(Int a0 = -5000;a0 <= 5000;a0++){
        if(a0*a0*a_ + a0*b_ + c_ == 0)oks.push_back(a0);
    }
    printf("%d\n", int(oks.size()));
    for(Int a0: oks){
        for(Int i = 0;i < n;i++)printf("%lld ", a0 + a_diff[i]);
        puts("");
    }    
    return 0;
}