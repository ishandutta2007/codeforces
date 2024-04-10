#include <bits/stdc++.h>

using namespace std;

#define MAXN 500005

int n, m;

char str[MAXN];

long long PosX[MAXN], PosY[MAXN], NegX[MAXN], NegY[MAXN];
int SPosX[MAXN], SNegX[MAXN];

int maxpx, maxpy, maxnx, maxny;

const long long INF = 1e17;
const int MOD = 1e9 + 7;

void Precomp(char neg, char pos, long long ToNeg[], long long ToPos[]) {
    int delta = 0;
    int n = 0;
    int posmax = 0, negmax = 0;

    for(int i=0; str[i]; i++) {
        if(str[i] == neg) delta -= 1;
        if(str[i] == pos) delta += 1;

        if(delta > 0 && ToPos[delta] == 0) ToPos[delta] = i + 1;
        if(delta < 0 && ToNeg[-delta] == 0) ToNeg[-delta] = i + 1;

        if(delta > 0) posmax = max(posmax, delta);
        if(delta < 0) negmax = max(negmax, -delta);

        n += 1;
    }

    for(int i=1; i<MAXN; i++) {
        if(ToPos[i] == 0) {
            if(delta > 0) ToPos[i] = n + ToPos[i - delta];
            else ToPos[i] = INF;
        }
        if(ToNeg[i] == 0) {
            if(delta < 0) ToNeg[i] = n + ToNeg[i + delta];
            else ToNeg[i] = INF;
        }
    }

}

void GetPart(long long V[], int S[]) {
    for(int i=1; i<MAXN; i++) {
        S[i] = (S[i-1] + V[i]) % MOD;
    }
}

int bs1(long long V[], long long with) {
    int sol = 0, i;
    for(i=1; i<MAXN; i<<=1);
    for(i>>=1; i; i>>=1)
        if(sol + i < MAXN && V[sol+i] <= with)
            sol += i;
    return sol;
}

int bs2(long long NV[], long long PV[]) {
    int sol = 0, i;
    for(i=1; i<=m; i<<=1);
    for(i>>=1; i; i>>=1) {
        if(sol + i <= m && NV[sol + i] <= PV[m - sol - i + 1])
            sol += i;
    }
    return sol;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    cin >> n >> n >> m >> str;
    Precomp('L', 'R', NegX, PosX);
    Precomp('U', 'D', NegY, PosY);

    GetPart(NegX, SNegX);
    GetPart(PosX, SPosX);

    int total = 0;

    for(int i=1; i<=n; i++) {
        long long cmpwith = min(NegY[i], PosY[n-i+1]);

        int p1 = bs1(NegX, cmpwith);
        int p2 = bs1(PosX, cmpwith);

        long long k = 0;

        if(p1 + p2 <= m) {
            k = (SNegX[p1] + SPosX[p2] + 1LL * cmpwith * (m - p1 - p2)) % MOD;
        } else {
            int p = bs2(NegX, PosX);
            if(NegX[p] == INF || PosX[m-p] == INF) { cout << -1; return 0; }
            k = (SNegX[p] + SPosX[m-p]);
        }


        total += k % MOD;
        if(total >= MOD) total -= MOD;
    }

    cout << total;


    return 0;
}