#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define MAXN 200500
#define R1 3
#define R2 332748118

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int euclid(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int d = euclid(b, a%b, x1, y1);
    x = y1, y = x1-y1*(a/b);
    return d;
}

int inv(int a){
    int x, y;
    euclid(a, MOD, x, y);
    return (x%MOD+MOD)%MOD;
}

int binpow(int a, int pw){
    int res = 1;
    while(pw>0){
        if(pw&1) grow(res, a);
        grow(a, a);
        pw >>= 1;
    }
    return res;
}

void ntt(vector<int> &a, bool invert){
    int n = a.size();
    for(int i = 1, j = 0; i<n; i++){
        int bit = n>>1;
        for(; j&bit; bit>>=1) j^=bit;
        j ^= bit;
        if(i < j) swap(a[i], a[j]);
    }

    for(int len = 2; len<=n; len <<= 1){
        int wlen = binpow((invert)?R2:R1, (MOD-1)/len);
        for(int i = 0; i<n; i += len){
            int w = 1;
            for(int j = 0; j<len/2; j++){
                int u = a[i+j], v = mul(a[i+j+len/2], w);
                a[i+j] = add(u, v);
                a[i+j+len/2] = sub(u, v);
                grow(w, wlen);
            }
        }
    }
    if(invert){
        int n1 = inv(n);
        for(int &x : a) grow(x, n1);
    }
}

vector<int> multiply(vector<int> &a, vector<int> &b){
    vector<int> na(a.begin(), a.end()), nb(b.begin(), b.end());
    int n = 1;
    while(n < a.size()+b.size()) n <<= 1;
    na.resize(n), nb.resize(n);
    ntt(na, 0); ntt(nb, 0);
    for(int i = 0; i<n; i++) grow(na[i], nb[i]);
    ntt(na, 1);
    return na;
}

int n;
int fac[MAXN], invfac[MAXN];
vector<pair<int, int>> arr;

void init(){
    fac[0] = 1;
    for(int i = 1; i<MAXN; i++) fac[i] = mul(fac[i-1], i);
    for(int i = 0; i<MAXN; i++) invfac[i] = inv(fac[i]);
}

int comb(int a, int b){
    if(b < 0 || a < 0 || b > a) return 0;
    return mul(fac[a], mul(invfac[b], invfac[a-b]));
}

void test(){
    vector<int> p1 = {1, 1}; vector<int> p2 = {1, 1};
    vector<int> res = multiply(p1, p2);
    for(auto x : res) cout << x << " ";
    cout << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); init();
    cin >> n; arr.resize(n);
    for(int i = 0; i<n; i++) cin >> arr[i].first >> arr[i].second;
    // test();
    vector<int> ans; ans.push_back(1);
    int cur = 1;
    for(int i = 0; i<n; i++){
        int a = arr[i].first, b = arr[i].second;
        int nxt = cur+a-b;
        int l = b-cur+1, r = a+b-l;
        // cout << l << " " << r << endl;
        vector<int> poly;
        for(int j = l; j<=r; j++) poly.push_back(comb(a+b, j));
        ans = multiply(ans, poly);
        ans = vector<int>(ans.begin()+cur-1, ans.begin()+cur-1+nxt);
        cur = nxt;
    }
    int res = 0;
    for(auto x : ans) inc(res, x);
    cout << res << endl;
}