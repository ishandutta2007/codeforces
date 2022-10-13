#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int A[2000000];

const long long INF = 1e17;

vector<int> Factors;
void Factorize(int x) {
    //Factors.clear();

    for(int d=2; 1LL*d*d<=x; d++) {
        if(x % d == 0) {
            Factors.push_back(d);
            while(x % d == 0)
                x /= d;
        }
    }

    if(x > 1) Factors.push_back(x);
}

long long Pref[2000000], Suff[2000000],
    MaxP[2000000], MaxS[2000000];

int Good(int no, int fact) {
    if(no % fact == 0) return 0;
    if((no + 1) % fact == 0) return b;
    if((no - 1) % fact == 0) return b;
    return -1;
}

long long SolveFor(int factor) {

    MaxP[0] = MaxS[n+1] = INF;

    for(int i=1; i<=n; i++) {
        int rez = Good(A[i], factor);

        if(rez == -1) Pref[i] = INF;
        else Pref[i] = Pref[i-1] + rez - a;

        MaxP[i] = min(MaxP[i-1], Pref[i]);
    }


    for(int i=n; i>=1; i--) {
        int rez = Good(A[i], factor);

        if(rez == -1) Suff[i] = INF;
        else Suff[i] = Suff[i+1] + rez - a;

        MaxS[i] = min(MaxS[i+1], Suff[i]);
    }

    MaxP[0] = MaxS[n+1] = 0;

    long long best = INF;
    for(int i=0; i<=n; i++) {
        best = min(best, MaxP[i] + MaxS[i+1]);
    }

    return best + 1LL * n * a;
}

void Read(int &a) {
    char c;
    for(c = getchar(); !isdigit(c); c = getchar());

    for(a = 0; isdigit(c); c = getchar()) {
        a = (a << 1) + (a << 3) + c - '0';
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug", "r", stdin);
    #endif // ONLINE_JUDGE

    Read(n); Read(a); Read(b);

    for(int i=1; i<=n; i++) {
        Read(A[i]);
    }

    for(int d=-1; d<=1; d++) {
        Factorize(A[1] + d);
        Factorize(A[n] + d);
    }

    long long best = INF;

    for(auto factor : Factors) {
        best = min(best, SolveFor(factor));
    }

    cout << best;
    return 0;
}