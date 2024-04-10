#include <bits/stdc++.h>
using namespace std;
#define MAXN 262144

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> &a, bool invert){
    int n = a.size();
    for(int i = 1, j = 0; i<n; i++){
        int bit = n >> 1;
        for(; j&bit; bit>>=1) j^=bit;
        j ^= bit;
        if(i < j) swap(a[i], a[j]);
    }
    for(int len = 2; len <= n; len<<=1){
        double ang = 2*PI/len*(invert?-1:1);
        cd wlen(cos(ang), sin(ang));
        for(int i = 0; i<n; i+=len){
            cd w(1);
            for(int j = 0; j<len/2; j++){
                cd u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if(invert) for(cd &x : a) x/=n;
}

vector<long long> mul(const vector<int>& a, const vector<int>& b){
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n < a.size()+b.size()) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa, 0); fft(fb, 0);
    for(int i = 0; i<n; i++) fa[i] *= fb[i];
    fft(fa, 1);
    vector<long long> res(n);
    for(int i = 0; i<n; i++) res[i] = round(fa[i].real());
    return res;
}

int n, m, q;
vector<long long> arr(MAXN), brr(MAXN); 
vector<int> a(MAXN), b(MAXN);
vector<int> amn(MAXN), bmn(MAXN), amx(MAXN), bmx(MAXN);
vector<long long> v(MAXN), aeh(MAXN), beh(MAXN), aev(MAXN), bev(MAXN), abad(MAXN), bbad(MAXN);
vector<long long> apre(MAXN), bpre(MAXN);

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = 0; i<m; i++) cin >> brr[i];
    for(int i = 0; i<MAXN; i++) a[i] = b[i] = amn[i] = bmn[i] = amx[i] = bmx[i] = 0;
    for(int i = 0; i<n; i++) a[arr[i]]++;
    for(int i = 0; i<n-1; i++) amn[min(arr[i], arr[i+1])]++;
    for(int i = 0; i<n-1; i++) amx[max(arr[i], arr[i+1])]++;
    for(int i = 0; i<m; i++) b[brr[i]]++;
    for(int i = 0; i<m-1; i++) bmn[min(brr[i], brr[i+1])]++;
    for(int i = 0; i<m-1; i++) bmx[max(brr[i], brr[i+1])]++;
    v = mul(a, b); aeh = mul(a, bmn); aev = mul(b, amn); beh = mul(a, bmx); bev = mul(b, amx);
    abad = mul(amn, bmn); bbad = mul(amx, bmx);
    for(int i = 0; i<MAXN; i++) apre[i] = v[i]-aeh[i]-aev[i]+abad[i];
    for(int i = 0; i<MAXN; i++) bpre[i] = v[i]-beh[i]-bev[i]+bbad[i];
    for(int i = 1; i<MAXN; i++) apre[i] += apre[i-1];
    for(int i = MAXN-2; i>=0; i--) bpre[i] += bpre[i+1];
    while(q--){
        int x; cin >> x;
        cout << bpre[x]-apre[x-1] << endl;
    }
}