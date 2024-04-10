#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
int K = 19;
const int LENGTH = 1 << K;
double PI = 3.1415926535897932384;
vector<complex<double> > angles;
void fft(vector<complex<double> > &v, bool invert, int lvl){
    if (v.size() == 1) return;
    int sz = v.size();
    vector<complex<double> > v0(sz / 2), v1(sz / 2);
    for (int i=0; i < sz / 2; i++){
        v0[i] = v[2*i];
        v1[i] = v[2*i+1];
    }
    fft(v0, invert, lvl - 1);
    fft(v1, invert, lvl - 1);
    complex<double> angle_multiple;
    complex<double> now = (1);
    if (invert) angle_multiple = angles[2*lvl];
    else angle_multiple = angles[2*lvl + 1];
    for (int i=0; i < sz/2; i++){
        v[i] = v0[i] + now * v1[i];
        v[i + sz/2] = v0[i] - now * v1[i];
        if (invert){
            v[i] /= 2;
            v[i + sz/2] /= 2;
        }
        now *= angle_multiple;
    }
}
signed main()
{
    //freopen("1.txt", "r", stdin);
    //freopen("3.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    for (int i=1; i <= LENGTH; i*=2){
        double angle = 2 * PI / (double) i;
        complex<double> c(cos(angle), sin(angle));
        complex<double> c1(cos(-angle), sin(-angle));
        angles.push_back(c);
        angles.push_back(c1);
    }
    vector<bool> v;
    for (int i=0; i < n; i++){
        int p;
        cin >> p;
        if (p < x) v.push_back(true);
        else v.push_back(false);
    }
    vector<int> a, b;
    int ctr = 1;
    for (int i=0; i < n; i++){
        if (!v[i]) ctr++;
        else{
            a.push_back(ctr);
            ctr = 1;
        }
    }
    ctr = 1;
    for (int i=n-1; i >= 0; i--){
        if (!v[i]) ctr++;
        else{
            b.push_back(ctr);
            ctr = 1;
        }
    }
    int nm = 0, res = 0;
    for (int i=0; i < n; i++){
        if (!v[i]) nm++;
        else{
            res += nm*(nm+1)/2;
            nm = 0;
        }
    }
    res += nm*(nm+1)/2;
    cout << res << " ";
    if (a.size()){
        int now = 0;
        int number = 1;
        int len = a.size();
        while (true){
            if (2 * len < number) break;
            number *= 2;
            now++;
        }
        vector<complex<double> > A(number), B(number);
        for (int i=0; i < number; i++){
            A[i] = (0);
            B[i] = (0);
        }
        for (int i=0; i < a.size(); i++){
            A[i] = (a[i]);
            B[i] = (b[i]);
        }
        fft(A, false, now);
        fft(B, false, now);
        for (int i=0; i < number; i++){
            A[i] *= B[i];
        }
        fft(A, true, now);
        for (int i=a.size() - 1; i >= 0; i--){
            int rs = round(A[i].real());
            cout << rs << " ";
        }
    }
    for (int i=a.size(); i < n; i++) cout << 0 << " ";
    cout << endl;
    return 0;
}