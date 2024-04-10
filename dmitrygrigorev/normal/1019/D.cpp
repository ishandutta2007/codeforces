#include <bits/stdc++.h>
#define LL long long
using namespace std;
int x[2000], y[2000];
LL S;
void pr(int vrt, int A, int B){
    cout << x[vrt]+A << " " << y[vrt]+B << endl;
}
void Tr(int i, int j, int p, int A, int B){
    LL X = (LL)x[j]*(LL) y[p] - (LL) x[p]*(LL) y[j];
    if ((X==S)|(X==-S)){
        cout << "Yes" << endl;
        pr(i, 0, 0);
        pr(j, A, B);
        pr(p, A, B);
        exit(0);
    }
}
signed main() {
    int n;
    cin >> n >> S;
    S<<=1;
    int ss = S;
    for (int i=0;i<n;i++) cin >> x[i] >> y[i];
    for (int i=0; i<n;i++){
        for (int j=i+1;j<n;j++){
            x[j] -= x[i], y[j] -= y[i];
        }
        for (int j=i+1; j < n; j++){
            for (int p=j+1; p < n; p++){
                int X = x[j]*y[p] - x[p]*y[j];
                if ((X==ss)|(X==-ss)){
                    Tr(i, j, p, x[i], y[i]);
                }
            }
        }
        for (int j=i+1;j<n;j++){
            x[j] += x[i], y[j] += y[i];
        }
    }
    cout << "No";
}