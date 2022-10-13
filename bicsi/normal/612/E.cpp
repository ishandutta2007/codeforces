#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005

vector<vector<int>> Cicli[MAXN];
vector<int> Ciclu;
bool Viz[MAXN];
int P[MAXN], Sol[MAXN];
int n;

void MergeCiclu(int sz) {
    for(int i=0; i<sz; i++)
        Sol[Ciclu[i]] = Ciclu[i+1];
    Sol[Ciclu[sz-1]] = Ciclu[0];
}

void SolveImpar(vector<int> &C) {
    int sz = C.size();
    for(int t=0; t<sz; t++)
        Ciclu[t] = 0;

    int poz = 0;
    for(auto x : C) {
        Ciclu[poz] = x;
        poz += 2;
        if(poz >= sz) poz -= sz;
    }

    MergeCiclu(sz);
}

void SolvePar(vector<int> &A, vector<int> &B) {
    for(int t=0; t<2*A.size(); t++)
        Ciclu[t] = 0;

    int poz = 0;
    for(auto x : A) {
        Ciclu[poz] = x;
        poz += 2;
    }
    poz = 1;
    for(auto x : B) {
        Ciclu[poz] = x;
        poz += 2;
    }

    MergeCiclu(2*A.size());
}

void checkSol() {
    for(int i=1; i<=n; i++) {
        assert(Sol[Sol[i]] == P[i]);
    }
}

void Read(int &x) {
    char c;
    for(c = getchar(); !isdigit(c); c = getchar());
    for(x = 0; isdigit(c); c = getchar())
        x = (x << 1) + (x << 3) + c - '0';
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    Read(n);

    for(int i=1; i<=n; i++) {
        Read(P[i]);
    }

    for(int i=1; i<=n; i++) {
        if(Viz[i]) continue;

        Ciclu.clear();
        int j = i;
        do {
            Viz[j] = 1;
            Ciclu.push_back(j);
            j = P[j];
        } while(!Viz[j]);

        Cicli[Ciclu.size()].push_back(Ciclu);
    }

    Ciclu.clear();
    Ciclu.resize(n, 0);

    for(int sz=1; sz<=n; sz++) {
        if(sz % 2 == 1) {
            for(auto C : Cicli[sz])
                SolveImpar(C);
        } else {
            if(Cicli[sz].size() % 2 == 1) {
                cout << "-1";
                return 0;
            } else {
                for(int t=0; t<Cicli[sz].size(); t+=2)
                    SolvePar(Cicli[sz][t], Cicli[sz][t+1]);
            }
        }
    }

    checkSol();

    for(int i=1; i<=n; i++) {
        cout << Sol[i] << " ";
    }

    return 0;
}