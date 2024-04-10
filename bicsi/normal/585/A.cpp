#include <bits/stdc++.h>

using namespace std;

int V[5000], Next[5000], Prev[5000], D[5000];
int64_t P[5000];
vector<int> Sol;
int n;

int Rem(int j) {
    Next[Prev[j]] = Next[j];
    Prev[Next[j]] = Prev[j];
    int64_t d = D[j];

    for(int k=Next[j]; k; k = Next[k]) {
        P[k] -= d;
        if(P[k] < 0) {
            Next[Prev[k]] = Next[k];
            Prev[Next[k]] = Prev[k];
            d += D[k];
        }
    }
    return Prev[j];
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    cin >> n;

    assert(n >= 1 && n <= 4000);

    for(int i=1; i<=n; i++) {
        cin>>V[i]>>D[i]>>P[i];

        assert(V[i] >= 1 && V[i] <= 1000000);
        assert(D[i] >= 1 && D[i] <= 1000000);
        assert(P[i] >= 1 && P[i] <= 1000000);

        Next[i] = i+1;
        Prev[i] = i-1;
    }
    Next[n] = 0;

    for(int i=1; i; i = Next[i]) {
        Sol.push_back(i);
        Prev[i] = 0;
        for(int j=Next[i]; j; j = Next[j], V[i]--) {
            P[j] -= max(V[i], 0);
            if(P[j] < 0) P[j] = -1;
        }
        for(int j=Next[i]; j; j = Next[j])
            if(P[j] < 0)
                j = Rem(j);
        Next[0] = 0;
    }

    cout << Sol.size() << '\n';
    for(auto x : Sol) {
        cout << x << ' ';
    }



    return 0;
}