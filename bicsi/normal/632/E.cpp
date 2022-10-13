#include <bits/stdc++.h>

using namespace std;

const int N = 1048576;
const int P = 399507457;
const int G = 173;
const int invG = 101608833;
const int invN = 399507076;

int Pol[N], R[N];

void fft(int In[], int Out[], int n, int step, int g) {
    if(n == 1) {
        Out[0] = In[0];
    } else {
        fft(In, Out, n/2, step*2, 1LL * g * g % P);
        fft(In+step, Out+n/2, n/2, step*2, 1LL * g * g % P);

        int w = 1;
        for(int i=0; i<n/2; i++) {
            int aux = 1LL * w * Out[i+n/2] % P;
            Out[i+n/2] = Out[i] - aux;
            Out[i] = Out[i] + aux;

            if(Out[i+n/2] < 0) Out[i+n/2] += P;
            if(Out[i] >= P) Out[i] -= P;

            w = 1LL * w * g % P;
        }
    }
}

void Multiply(int A[], int B[]) {
    for(int i=0; i<N; i++) {
        A[i] = 1LL * A[i] * B[i] % P;
    }
}


int main() {
//    freopen("debug", "r", stdin);
    ios_base::sync_with_stdio(false);

    int nn, k, a;
    cin >> nn >> k;

    while(nn--) {
        cin >> a;
        R[a] = 1;
    }

    fft(R, Pol, N, 1, G);
    for(int i=0; i<N; i++)
        R[i] = 1;


    int nnn = N;
    while(k) {
        if(k % 2 == 1) Multiply(R, Pol);
        Multiply(Pol, Pol);
        k /= 2;
    }

    fft(R, Pol, N, 1, invG);

    for(int i=1; i<N; i++) {
        if(1ll * Pol[i] * invN % P) {
            cout << i << " ";
        }
    }

    return 0;
}