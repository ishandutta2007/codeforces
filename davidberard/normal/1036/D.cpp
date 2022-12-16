#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 300300;

ll A[NMAX], B[NMAX], An[NMAX], Bn[NMAX], n, m;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=0;i<n;++i) {
        An[i] = i+1;
    }
    for(int i=1;i<=n;++i) {
        cin >> A[i];
    }
    cin >> m;
    for(int i=0;i<m;++i) {
        Bn[i] = i+1;
    }
    for(int i=1;i<=m;++i) {
        cin >> B[i];
    }
    An[n] = -1;
    Bn[m] = -1;
    int ap = 1, bp = 1;
    int al = n, bl = m;
    while(ap > 0 && bp > 0) {
        int ac = ap, bc = bp;
        while(A[ap] != B[bp]) {
            if(A[ap] > B[bp]) {
                if(Bn[bp] == -1) {
                    cout << -1 << endl;
                    return 0;
                }
                B[bc] += B[Bn[bp]];
                Bn[bp] = Bn[Bn[bp]];
                bl--;
            } else if(A[ap] < B[bp]) {
                if(An[ap] == -1) {
                    cout << -1 << endl;
                    return 0;
                }
                A[ac] += A[An[ap]];
                An[ap] = An[An[ap]];
                al--;
            }
        }
        if(A[ap] != B[bp]) {
            cout << -1 << endl;
            return 0;
        }
        //cerr << " proceed with " << A[ap] << " " << B[bp] << endl;
        ap = An[ap];
        bp = Bn[bp];
    }
    cerr << "!! " << ap << " " << bp << " " << al << " " << bl << endl;
    if(al != bl) {
        cout << -1 << endl;
        return 0;
    }
    cout << al << endl;
    return 0;
}