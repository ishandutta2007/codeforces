#include <bits/stdc++.h>

using namespace std;

typedef complex<double> Complex;
const double PI = 4 * atan(1.0);
 
int N = (1 << 16);
Complex P[1 << 21], Q[1 << 21], R[1 << 21];

void FFT(Complex In[], Complex Out[], int n, int step, bool r) {
    if(n == 1) {
        Out[0] = In[0];
    } else {
        FFT(In, Out, n/2, step*2, r);
        FFT(In+step, Out+n/2, n/2, step*2, r);
 
        Complex eps(cos(2*PI/n), sin(2*PI/n)),
                w(1, 0);
        if(r) eps = conj(eps);
 
        for(int i=0; i<n/2; i++) {
            Complex aux = w * Out[i+n/2];
            Out[i+n/2] = Out[i] - aux;
            Out[i] = Out[i] + aux;
            w *= eps;
        }
    }
}

 
 
void Mul(Complex A[], Complex B[], Complex R[]) {
    FFT(A, R, N, 1, 0);
    FFT(B, A, N, 1, 0);
 
    for(int i = 0; i < N; ++i) {
        B[i] = A[i] * R[i];
        B[i] /= N;
    }
 
    FFT(B, R, N, 1, 1);
}

vector<int> Solve(vector<bool> what, vector<bool> what2) {

    // cerr << "solving for ";
    // for (auto x : what) cerr << x; cerr << endl;

    int n = what.size();

    for (N = 1; N <= 2*n; N *= 2);
    memset(P, 0, N * sizeof(*P));
    memset(Q, 0, N * sizeof(*Q));
    memset(R, 0, N * sizeof(*R));


    for (int i = 0; i < n; ++i) {
        P[i] = (what[i] ? 1 : 0);
        Q[n - i] = (what2[i] ? 1 : 0);
    }

    Mul(P, Q, R);

    vector<int> ret(n - 1);
    for (int i = n + 1; i < n + n; ++i) {
        ret[i - n - 1] = round(real(R[i]));
    }
    return ret;
}

int main() {
    //freopen("input", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string str; cin >> str;

        vector<bool> zero(n, 0), one(n, 0), two(n, 0), zerox(n, 0), onex(n, 0);
        for (int i = 0; i < n; ++i) {
            if (str[i] == 'V' or str[i] == '?')
                zero[i] = true;
            if (str[i] == 'K' or str[i] == '?')
                one[i] = true;
            if (str[i] == '?')
                two[i] = true;
            if (str[i] == 'V') zerox[i] = true;
            if (str[i] == 'K') onex[i] = true;
        }

        vector<int> ans;
        vector<int> b1 = Solve(zerox, onex), b2 = Solve(onex, zerox);
        vector<bool> bad(n, false);

        for (int i = 1; i < n; ++i) {
            for (int j = i; j < n; j += i)
                if (b1[j - 1] > 0 or b2[j - 1] > 0)
                    bad[i - 1] = true;
        }

        // cerr << "bad: ";
        // for (auto x : bad) cerr << x; cerr << endl;

        for (int i = 0; i < n; ++i) {
            // cerr << i << ": " << a[i] + b[i] - c[i] << endl;
            if (!bad[i])
                ans.push_back(i + 1);
        }

        cout << ans.size() << '\n';
        for (auto x : ans) cout << x << " ";
            cout << '\n';
    }

    return 0;
}